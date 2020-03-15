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
#include "HL_gio.h"
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
static void TaskDataAcquisition(void *pvParameters);
TaskHandle_t TaskInitHandle;

/*
**************************************************************************************
FUNCTION FOR SCI COMMUNICATION
**************************************************************************************
*/
void sciSendText(sciBASE_t *sci, uint8 *text, uint32 length);
void sciSendData(sciBASE_t *sci, uint8 *text, uint32 length);
#define TSIZE_INTRO 9
#define TSIZE_OK 4
#define TSIZE_a 3
uint8 TEXT1[TSIZE_INTRO] = {'C', 'O', 'N', 'E', 'C', 'T', 'A', 'D', 'O'};
uint8 TEXTOK[TSIZE_OK] = {'O', 'K', '\n'};
uint8 TEXTa[TSIZE_a] = {'a', '\n'};

/*
**************************************************************************************
FUNCTION FOR PID CONTROLLER
**************************************************************************************
*/
uint16 CoordinateX = 320;
uint16 CoordinateY = 240;
void sendPWM(bool dir, float32 PID, bool ID);
bool sign(float32 PID);
/* USER CODE END */

int main(void)
{
/* USER CODE BEGIN (3) */
    hetInit();
    sciInit();
    gioInit();

    gioSetBit(gioPORTB, 6, 0);
    gioSetBit(gioPORTB, 7, 0);

    if (xTaskCreate(TaskInit, "TaskInit", configMINIMAL_STACK_SIZE, NULL, 3, &TaskInitHandle) != pdTRUE)
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

    uint32 datareceived;

    datareceived = sciReceiveByte(sciREG1);
    while (datareceived != 64)
    {
        datareceived = sciReceiveByte(sciREG1);
    }
    sciSendText(sciREG1, &TEXTOK[0], TSIZE_OK); /* send text 1 */

    gioSetBit(gioPORTB, 6, 1);
    gioSetBit(gioPORTB, 7, 0);

    //PWM0 init
    pwm0het0.period = 20000;
    pwm0het0.duty = 0;
    setpwmsignal(hetRAM1, pwm0, pwm0het0);
    //PWM1 init
    pwm1het1.period = 20000;
    pwm1het1.duty = 0;
    setpwmsignal(hetRAM1, pwm1, pwm1het1);

    if (xTaskCreate(TaskControl, "TaskControl", configMINIMAL_STACK_SIZE, NULL, 2, NULL) != pdTRUE)
    {
        // TASK HAS NOT CREATED
    }
    if (xTaskCreate(TaskDataAcquisition, "TaskDataAcquisition", configMINIMAL_STACK_SIZE, NULL, 1, NULL) != pdTRUE)
    {
        // TASK HAS NOT CREATED
    }
    vTaskDelete(TaskInitHandle);
}
static void TaskDataAcquisition(void *pvParameters)
{
    TickType_t xLastExecutionTime;
    xLastExecutionTime = xTaskGetTickCount();
    uint32 datareceivedX;
    uint32 datareceivedY_aux;
    uint32 datareceivedY;
    uint32 Data;

    for (;;)
    {
        gioSetBit(gioPORTB, 7, 1);
        CoordinateX = 0;
        //CoordinateY = 0;
        sciSendText(sciREG1, &TEXTa[0], TSIZE_a); /* send text 1 */
        Data = sciReceiveByte(sciREG1);
        while (Data != 48)
        {
            sciSendText(sciREG1, &TEXTa[0], TSIZE_a); /* send text 1 */
            Data = sciReceiveByte(sciREG1);
        }
        datareceivedY = sciReceiveByte(sciREG1);
        datareceivedY_aux = sciReceiveByte(sciREG1);
        CoordinateY = (uint16)(datareceivedY) | (uint16)(datareceivedY_aux << 8);

        CoordinateX = (CoordinateX > 640) ? 640 : CoordinateX;
        CoordinateY = (CoordinateY > 480) ? 480 : CoordinateY;

        //sciReceive(sciREG1, 1, (uint8 *)&datareceivedX);
        //sciSendData(sciREG1, (uint8 *)&Data, 2);
        //sciSend(sciREG1, 2, (unsigned char *)"\r\n");
        // vTaskDelayUntil(&xLastExecutionTime, 16.66 * portTICK_PERIOD_MS);
    }
}
static void TaskControl(void *pvParameters)
{
    /*
    *MOTOR 1    <<<< Y >>>>
    * R       CENTRO        L
    * 343-670   671-723   723-1000
    * LEFT -> DOWN
    * RIGHT -> UP
    */

    /*
    *MOTOR 2    <<<< X >>>>
    * R         CENTRO        L
    * 402-674   675-726     727-1000
    */
    float32 lastError[2] = {0.0, 0.0}; //[0]->X & [1]->Y
    float32 error[2] = {0.0, 0.0};     //[0]->X & [1]->Y
    float32 sumError[2] = {0.0, 0.0};  //[0]->X & [1]->Y
    float32 Kp[2] = {0.0, 0.0};        //[0]->X & [1]->Y
    float32 Kd[2] = {0.0, 0.0};        //[0]->X & [1]->Y
    float32 Ki[2] = {0.0, 0.0};        //[0]->X & [1]->Y
    float32 PID[2] = {0, 0};           //[0]->X & [1]->Y

    TickType_t xLastExecutionTime;
    xLastExecutionTime = xTaskGetTickCount();

    for (;;)
    {
        gioSetBit(gioPORTB, 7, 0);

        //Save the last error
        lastError[0] = error[0];
        lastError[1] = error[1];

        //Obtain Errors
        error[0] = (float32)320 - CoordinateX;
        error[1] = (float32)240 - CoordinateY;

        //Sum error
        sumError[0] += error[0];
        sumError[1] += error[1];

        //Setting gains for Proportional control
        Kp[0] = 0;
        Kp[1] = 0.1; //0.55
        //Setting gains for Diferential control
        Kd[0] = 0;
        Kd[1] = 0.00000001;
        //Setting gains for Integral control
        Ki[0] = 0;
        Ki[1] = 0.0;

        PID[0] = Kp[0] * error[0] + (Kd[0] * (error[0] - lastError[0]) / 0.0166) + Ki[0] * sumError[0]; //For motor 2
        PID[1] = Kp[1] * error[1] + (Kd[1] * (error[1] - lastError[1]) / 0.0166) + (Ki[1] * sumError[1]); //For motor 1

        sendPWM(sign(PID[1]), PID[1], 0);

        //pwm0het0.duty = 723; //For motor 1
        //setpwmsignal(hetRAM1, pwm0, pwm0het0);

        pwm1het1.duty = 590;
        setpwmsignal(hetRAM1, pwm1, pwm1het1); //For motor 2

        vTaskDelayUntil(&xLastExecutionTime, 16.66 * portTICK_PERIOD_MS);
    }
}
bool sign(float32 PID)
{
    bool ret;
    ret = (PID > 0) ? 1 : 0;
    return ret;
}
void sendPWM(bool dir, float32 PID, bool ID)
{
    /*
    *ID 0 -> MOTOR 1
    *ID 1 -> MOTOR 2
    *dir 0 -> TURN LEFT -> NEGATIVE ERROR
    *dir 1 -> TURN  RIGHT -> POSITIVE ERROR
    */

    //SETTING BOUNDARIES
    if (ID == 0)
    {
        if (dir == 1)
        {
            PID = 722 + PID;
            PID = (PID > 1000) ? 1000 : PID;
            PID = (PID < 727) ? 720 : PID;
        }
        else
        {

            PID = 671 + PID;
            PID = (PID > 670) ? 672 : PID;
            PID = (PID < 393) ? 393 : PID;
        }
        pwm0het0.duty = (uint32)PID; //For motor 1
        setpwmsignal(hetRAM1, pwm0, pwm0het0);
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
/* USER CODE END */
