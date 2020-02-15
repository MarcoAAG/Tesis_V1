# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "rosplane_msgs: 5 messages, 0 services")

set(MSG_I_FLAGS "-Irosplane_msgs:/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(rosplane_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg" NAME_WE)
add_custom_target(_rosplane_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rosplane_msgs" "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg" ""
)

get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg" NAME_WE)
add_custom_target(_rosplane_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rosplane_msgs" "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg" "std_msgs/Header"
)

get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg" NAME_WE)
add_custom_target(_rosplane_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rosplane_msgs" "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg" ""
)

get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg" NAME_WE)
add_custom_target(_rosplane_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rosplane_msgs" "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg" ""
)

get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg" NAME_WE)
add_custom_target(_rosplane_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "rosplane_msgs" "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_cpp(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_cpp(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_cpp(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_cpp(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplane_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(rosplane_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplane_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(rosplane_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(rosplane_msgs_generate_messages rosplane_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_cpp _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_cpp _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_cpp _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_cpp _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_cpp _rosplane_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rosplane_msgs_gencpp)
add_dependencies(rosplane_msgs_gencpp rosplane_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rosplane_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_eus(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_eus(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_eus(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_eus(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplane_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(rosplane_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplane_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(rosplane_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(rosplane_msgs_generate_messages rosplane_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_eus _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_eus _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_eus _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_eus _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_eus _rosplane_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rosplane_msgs_geneus)
add_dependencies(rosplane_msgs_geneus rosplane_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rosplane_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_lisp(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_lisp(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_lisp(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_lisp(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplane_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(rosplane_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplane_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(rosplane_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(rosplane_msgs_generate_messages rosplane_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_lisp _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_lisp _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_lisp _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_lisp _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_lisp _rosplane_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rosplane_msgs_genlisp)
add_dependencies(rosplane_msgs_genlisp rosplane_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rosplane_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_nodejs(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_nodejs(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_nodejs(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_nodejs(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplane_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(rosplane_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplane_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(rosplane_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(rosplane_msgs_generate_messages rosplane_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_nodejs _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_nodejs _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_nodejs _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_nodejs _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_nodejs _rosplane_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rosplane_msgs_gennodejs)
add_dependencies(rosplane_msgs_gennodejs rosplane_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rosplane_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_py(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/melodic/share/std_msgs/cmake/../msg/Header.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_py(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_py(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplane_msgs
)
_generate_msg_py(rosplane_msgs
  "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplane_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(rosplane_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplane_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(rosplane_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(rosplane_msgs_generate_messages rosplane_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Internals.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_py _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/State.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_py _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Waypoint.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_py _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Current_Path.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_py _rosplane_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/marco/Tesis/ROS/src/rosplane/rosplane_msgs/msg/Controller_Commands.msg" NAME_WE)
add_dependencies(rosplane_msgs_generate_messages_py _rosplane_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(rosplane_msgs_genpy)
add_dependencies(rosplane_msgs_genpy rosplane_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS rosplane_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplane_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/rosplane_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(rosplane_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplane_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/rosplane_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(rosplane_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplane_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/rosplane_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(rosplane_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplane_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/rosplane_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(rosplane_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplane_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplane_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/rosplane_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(rosplane_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
