/** @file HL_sys_main.c 
*   @brief Application main file
*   @date 11-Dec-2018
*   @version 04.07.01
*
*   This file contains an empty main function,
*   which can be used for the application.
*/

/* 
* Copyright (C) 2009-2018 Texas Instruments Incorporated - www.ti.com  
* 
* 
*  Redistribution and use in source and binary forms, with or without 
*  modification, are permitted provided that the following conditions 
*  are met:
*
*    Redistributions of source code must retain the above copyright 
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the 
*    documentation and/or other materials provided with the   
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS 
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT 
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT 
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT 
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT 
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

/* USER CODE BEGIN (0) */
/* USER CODE END */

/* Include Files */

#include "HL_sys_common.h"

/* USER CODE BEGIN (1) */
#include "HL_sys_core.h"
#include "FreeRTOS.h"
#include "os_task.h"
#include "HL_het.h"
#include "HL_sci.h"
#include "HL_spi.h"
#include "as5048.h"
/* USER CODE END */

/** @fn void main(void)
*   @brief Application main function
*   @note This function is empty by default.
*
*   This function is called after startup.
*   The user can use this function to implement the application.
*/

/* USER CODE BEGIN (2) */

/*
**************************************************************************************
FUNCTIONS FOR PWM CREATOR
**************************************************************************************
*/
static const uint32 s_het1pwmPolarity[8U] =
    {
        3U,
        3U,
        3U,
        3U,
        3U,
        3U,
        3U,
        3U,
};
hetSIGNAL_t pwm0het0; // pwm signal for motor input
hetSIGNAL_t pwm1het1; // pwm signal for motor input
void setpwmsignal(hetRAMBASE_t *hetRAM, uint32 pwm, hetSIGNAL_t signal);

/*
**************************************************************************************
FUNCTION FOR FREERTOS SYSTEM
**************************************************************************************
*/
static void TaskInit(void *pvParameters);
static void TaskControl(void *pvParameters);
TaskHandle_t TaskInitHandle;

/*
**************************************************************************************
FUNCTION FOR SCI COMMUNICATION
**************************************************************************************
*/
void sciSendText(sciBASE_t *sci, uint8 *text, uint32 length);
void sciSendData(sciBASE_t *sci, uint8 *text, uint32 length);
#define TSIZE_INTRO 9
uint8 TEXT1[TSIZE_INTRO] = {'C', 'O', 'N', 'E', 'C', 'T', 'A', 'D', 'O'};

/*
**************************************************************************************
FUNCTION FOR SPI COMMUNICATION
**************************************************************************************
*/

spiDAT1_t SPI1_data_configCh0;

uint16_t ComandoSPI1[1] = {0};
uint16_t DatoSPI1[4];
uint16_t Dato_1_SPI1[1];
uint16_t Dato_2_SPI1[1];
uint16_t Dato_3_SPI1[1];
uint16_t Dato_4_SPI1[1];
void delaymio(uint32_t DelayMax);

/* USER CODE END */

int main(void)
{
    /* USER CODE BEGIN (3) */
    hetInit();
    sciInit();
    spiInit();
    // as5048Init();

    SPI1_data_configCh0.CS_HOLD = FALSE;
    SPI1_data_configCh0.WDEL = TRUE;
    SPI1_data_configCh0.DFSEL = SPI_FMT_0; // antes en SPI_FMT_1: modo 2: Select the Data word format by setting DFSEL bits. Select the Number of the configured SPIFMTx register (0 to 3) to used for the communication. Note: It is highly recommended to use SPIDAT1 register, SPIDAT0 is supported for compatibility reason
    SPI1_data_configCh0.CSNR = 0xFE;       // con este controlamos el slave chip select 1

    _enable_interrupt_(); // habilitamos interrupci�n global

    if (xTaskCreate(TaskInit, "TaskInit", configMINIMAL_STACK_SIZE, NULL, 2, &TaskInitHandle) != pdTRUE)
    {
        // TASK HAS NOT CREATED
        return 0;
    }
    vTaskStartScheduler();
    for (;;)
        ;
    /* USER CODE END */

    return 0;
}

/* USER CODE BEGIN (4) */
/*
**************************************************************************************
FUNCTION FOR FREERTOS SYSTEM
**************************************************************************************
*/
static void TaskInit(void *pvParameters)
{
    portTickType xLastWakeTime;
    xLastWakeTime = xTaskGetTickCount();

    sciSendText(sciREG1, &TEXT1[0], TSIZE_INTRO); /* send text 1 */

    //PWM0 init
    pwm0het0.period = 20000;
    pwm0het0.duty = 500;
    setpwmsignal(hetRAM1, pwm0, pwm0het0);
    //PWM1 init
    pwm1het1.period = 20000;
    pwm1het1.duty = 500;
    setpwmsignal(hetRAM1, pwm1, pwm1het1);

    vTaskDelayUntil(&xLastWakeTime, (5000 * portTICK_RATE_MS)); //Sleep task for 2 seconds
    if (xTaskCreate(TaskControl, "TaskControl", configMINIMAL_STACK_SIZE, NULL, 1, NULL) != pdTRUE)
    {
        // TASK HAS NOT CREATED
    }
    vTaskDelete(TaskInitHandle);
}
static void TaskControl(void *pvParameters)
{
    uint16 n;
    n = 5;
    uint16_t value[1];
    uint16_t AS5048A_ANGLE[1] = {0x3FFF};

    // ComandoSPI1[0] = 0x3FFF; // config en direcci�n 0 comienza en la 00 y escribe hasta el 3; 0100 0011
    // spiSendAndGetData(spiREG1, &SPI1_data_configCh0, 1, ComandoSPI1, Dato_1_SPI1);
    // delaymio(5000);
    // read(AS5048A_ANGLE, spiREG1, &SPI1_data_configCh0);
    for (;;)
    {

        pwm0het0.duty = 590;
        setpwmsignal(hetRAM1, pwm0, pwm0het0);

        pwm1het1.duty = 590;
        setpwmsignal(hetRAM1, pwm1, pwm1het1);

        // value = getRawRotation(spiREG1, &SPI1_data_configCh0);
        AS5048A_ANGLE[0] = 0x3FFF;
        value[0] = read(&AS5048A_ANGLE, spiREG1, &SPI1_data_configCh0);
        delaymio(20000);
        sciSendData(sciREG1, (uint8 *)&value[0], 4);
        sciSend(sciREG1, 2, (unsigned char *)"\r\n");

        // ComandoSPI1[0] = 0x3FFF; // config en direcci�n 0 comienza en la 00 y escribe hasta el 3; 0100 0011
        // spiSendAndGetData(spiREG1, &SPI1_data_configCh0, 1, ComandoSPI1 , Dato_2_SPI1);
        // delaymio(20000);
        // ComandoSPI1[0] = 0x3FFF; // config en direcci�n 0 comienza en la 00 y escribe hasta el 3; 0100 0011
        // spiSendAndGetData(spiREG1, &SPI1_data_configCh0, 1, ComandoSPI1[0], Dato_2_SPI1);
        // delaymio(5000);

        // delaymio(50000);
        // delaymio(50000);

        // sciSendData(sciREG1, (uint8 *)&Dato_2_SPI1[0], 4);
        // sciSend(sciREG1, 2, (unsigned char *)"\r\n");
        // sciSendData(sciREG1, (uint8 *)&Dato_2_SPI1[0], 4);
        // sciSend(sciREG1, 2, (unsigned char *)"\r\n");
    }
}

void vApplicationIdleHook(void)
{
}
/*
**************************************************************************************
FUNCTIONS FOR PWM CREATOR
**************************************************************************************
*/
void setpwmsignal(hetRAMBASE_t *hetRAM, uint32 pwm, hetSIGNAL_t signal)
{
    uint32 action;
    uint32 pwmPolarity = 0U;
    float64 pwmPeriod = 0.0F;

    if (hetRAM == hetRAM1)
    {
        pwmPeriod = (signal.period * 1000.0F) / 800.000F;
        pwmPolarity = s_het1pwmPolarity[pwm];
    }
    else
    {
    }
    if (signal.duty == 0U)
    {
        action = (pwmPolarity == 3U) ? 0U : 2U;
    }
    else if (signal.duty >= 10000U)
    {
        action = (pwmPolarity == 3U) ? 2U : 0U;
    }
    else
    {
        action = pwmPolarity;
    }

    hetRAM->Instruction[(pwm << 1U) + 41U].Control = ((hetRAM->Instruction[(pwm << 1U) + 41U].Control) & (~(uint32)(0x00000018U))) | (action << 3U);
    hetRAM->Instruction[(pwm << 1U) + 41U].Data = ((((uint32)pwmPeriod * signal.duty) / 10000) << 7U) + 128U; // el duty va de 0 a 10000, es decir de 0ms a 20ms
    hetRAM->Instruction[(pwm << 1U) + 42U].Data = ((uint32)pwmPeriod << 7U) - 128U;
}

/*
**************************************************************************************
FUNCTION FOR SCI COMMUNICATION
**************************************************************************************
*/
void sciSendData(sciBASE_t *sci, uint8 *text, uint32 length)
{
    uint8 txt = 0;
    uint8 txt1 = 0;

#if ((__little_endian__ == 1) || (__LITTLE_ENDIAN__ == 1))
    text = text + (length - 1);
#endif

    while (length--)
    {
#if ((__little_endian__ == 1) || (__LITTLE_ENDIAN__ == 1))
        txt = *text--;
#else
        txt = *text++;
#endif

        txt1 = txt;

        txt &= ~(0xF0);
        txt1 &= ~(0x0F);
        txt1 = txt1 >> 4;

        if (txt <= 0x9)
        {
            txt += 0x30;
        }
        else if (txt > 0x9 && txt <= 0xF)
        {
            txt += 0x37;
        }
        else
        {
            txt = 0x30;
        }

        if (txt1 <= 0x9)
        {
            txt1 += 0x30;
        }
        else if ((txt1 > 0x9) && (txt1 <= 0xF))
        {
            txt1 += 0x37;
        }
        else
        {
            txt1 = 0x30;
        }

        while ((sciREG1->FLR & 0x4) == 4)
            ;                       /* wait until busy */
        sciSendByte(sciREG1, txt1); /* send out text   */
        while ((sciREG1->FLR & 0x4) == 4)
            ;                      /* wait until busy */
        sciSendByte(sciREG1, txt); /* send out text   */
    };
}

void sciSendText(sciBASE_t *sci, uint8 *text, uint32 length)
{
    while (length--)
    {
        while ((sciREG1->FLR & 0x4) == 4)
            ;                          /* wait until busy */
        sciSendByte(sciREG1, *text++); /* send out text   */
    };
}
void delaymio(uint32_t DelayMax)
{
    uint32_t id = 0;
    for (id = 0; id < DelayMax; ++id)
    {
        asm(" nop");
    }
}

/* USER CODE END */
