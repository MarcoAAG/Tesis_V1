# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marco/Tesis/ROS/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marco/Tesis/ROS/build

# Include any dependencies generated for this target.
include object_tracking/CMakeFiles/object_tracking.dir/depend.make

# Include the progress variables for this target.
include object_tracking/CMakeFiles/object_tracking.dir/progress.make

# Include the compile flags for this target's objects.
include object_tracking/CMakeFiles/object_tracking.dir/flags.make

object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o: object_tracking/CMakeFiles/object_tracking.dir/flags.make
object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o: /home/marco/Tesis/ROS/src/object_tracking/src/object_tracking.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marco/Tesis/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o"
	cd /home/marco/Tesis/ROS/build/object_tracking && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o -c /home/marco/Tesis/ROS/src/object_tracking/src/object_tracking.cpp

object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/object_tracking.dir/src/object_tracking.cpp.i"
	cd /home/marco/Tesis/ROS/build/object_tracking && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marco/Tesis/ROS/src/object_tracking/src/object_tracking.cpp > CMakeFiles/object_tracking.dir/src/object_tracking.cpp.i

object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/object_tracking.dir/src/object_tracking.cpp.s"
	cd /home/marco/Tesis/ROS/build/object_tracking && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marco/Tesis/ROS/src/object_tracking/src/object_tracking.cpp -o CMakeFiles/object_tracking.dir/src/object_tracking.cpp.s

object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o.requires:

.PHONY : object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o.requires

object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o.provides: object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o.requires
	$(MAKE) -f object_tracking/CMakeFiles/object_tracking.dir/build.make object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o.provides.build
.PHONY : object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o.provides

object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o.provides.build: object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o


# Object files for target object_tracking
object_tracking_OBJECTS = \
"CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o"

# External object files for target object_tracking
object_tracking_EXTERNAL_OBJECTS =

/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: object_tracking/CMakeFiles/object_tracking.dir/build.make
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/libcv_bridge.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/libimage_transport.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/libmessage_filters.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/libclass_loader.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/libPocoFoundation.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libdl.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/libroscpp.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/librosconsole.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/libroslib.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/librospack.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/librostime.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /opt/ros/melodic/lib/libcpp_common.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking: object_tracking/CMakeFiles/object_tracking.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marco/Tesis/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking"
	cd /home/marco/Tesis/ROS/build/object_tracking && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/object_tracking.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
object_tracking/CMakeFiles/object_tracking.dir/build: /home/marco/Tesis/ROS/devel/lib/object_tracking/object_tracking

.PHONY : object_tracking/CMakeFiles/object_tracking.dir/build

object_tracking/CMakeFiles/object_tracking.dir/requires: object_tracking/CMakeFiles/object_tracking.dir/src/object_tracking.cpp.o.requires

.PHONY : object_tracking/CMakeFiles/object_tracking.dir/requires

object_tracking/CMakeFiles/object_tracking.dir/clean:
	cd /home/marco/Tesis/ROS/build/object_tracking && $(CMAKE_COMMAND) -P CMakeFiles/object_tracking.dir/cmake_clean.cmake
.PHONY : object_tracking/CMakeFiles/object_tracking.dir/clean

object_tracking/CMakeFiles/object_tracking.dir/depend:
	cd /home/marco/Tesis/ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marco/Tesis/ROS/src /home/marco/Tesis/ROS/src/object_tracking /home/marco/Tesis/ROS/build /home/marco/Tesis/ROS/build/object_tracking /home/marco/Tesis/ROS/build/object_tracking/CMakeFiles/object_tracking.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : object_tracking/CMakeFiles/object_tracking.dir/depend

