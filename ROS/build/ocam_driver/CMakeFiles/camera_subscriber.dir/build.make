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
include ocam_driver/CMakeFiles/camera_subscriber.dir/depend.make

# Include the progress variables for this target.
include ocam_driver/CMakeFiles/camera_subscriber.dir/progress.make

# Include the compile flags for this target's objects.
include ocam_driver/CMakeFiles/camera_subscriber.dir/flags.make

ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o: ocam_driver/CMakeFiles/camera_subscriber.dir/flags.make
ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o: /home/marco/Tesis/ROS/src/ocam_driver/src/camera_subscriber.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/marco/Tesis/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o"
	cd /home/marco/Tesis/ROS/build/ocam_driver && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o -c /home/marco/Tesis/ROS/src/ocam_driver/src/camera_subscriber.cpp

ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.i"
	cd /home/marco/Tesis/ROS/build/ocam_driver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/marco/Tesis/ROS/src/ocam_driver/src/camera_subscriber.cpp > CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.i

ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.s"
	cd /home/marco/Tesis/ROS/build/ocam_driver && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/marco/Tesis/ROS/src/ocam_driver/src/camera_subscriber.cpp -o CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.s

ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o.requires:

.PHONY : ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o.requires

ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o.provides: ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o.requires
	$(MAKE) -f ocam_driver/CMakeFiles/camera_subscriber.dir/build.make ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o.provides.build
.PHONY : ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o.provides

ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o.provides.build: ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o


# Object files for target camera_subscriber
camera_subscriber_OBJECTS = \
"CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o"

# External object files for target camera_subscriber
camera_subscriber_EXTERNAL_OBJECTS =

/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: ocam_driver/CMakeFiles/camera_subscriber.dir/build.make
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/libcv_bridge.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/libimage_transport.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/libmessage_filters.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/libnodeletlib.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/libbondcpp.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/libclass_loader.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/libPocoFoundation.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libdl.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/libroslib.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/librospack.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/libroscpp.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libboost_signals.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/librosconsole.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/librostime.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /opt/ros/melodic/lib/libcpp_common.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_shape.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_stitching.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_superres.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_videostab.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_aruco.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_bgsegm.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_bioinspired.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_ccalib.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_datasets.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_dpm.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_face.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_freetype.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_fuzzy.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_hdf.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_line_descriptor.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_optflow.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_plot.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_reg.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_saliency.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_stereo.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_structured_light.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_surface_matching.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_text.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_ximgproc.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_xobjdetect.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_xphoto.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_video.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_viz.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_phase_unwrapping.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_rgbd.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_calib3d.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_features2d.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_flann.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_objdetect.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_ml.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_highgui.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_photo.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_videoio.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_imgcodecs.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_imgproc.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: /usr/lib/x86_64-linux-gnu/libopencv_core.so.3.2.0
/home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber: ocam_driver/CMakeFiles/camera_subscriber.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/marco/Tesis/ROS/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber"
	cd /home/marco/Tesis/ROS/build/ocam_driver && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/camera_subscriber.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ocam_driver/CMakeFiles/camera_subscriber.dir/build: /home/marco/Tesis/ROS/devel/lib/ocam_driver/camera_subscriber

.PHONY : ocam_driver/CMakeFiles/camera_subscriber.dir/build

ocam_driver/CMakeFiles/camera_subscriber.dir/requires: ocam_driver/CMakeFiles/camera_subscriber.dir/src/camera_subscriber.cpp.o.requires

.PHONY : ocam_driver/CMakeFiles/camera_subscriber.dir/requires

ocam_driver/CMakeFiles/camera_subscriber.dir/clean:
	cd /home/marco/Tesis/ROS/build/ocam_driver && $(CMAKE_COMMAND) -P CMakeFiles/camera_subscriber.dir/cmake_clean.cmake
.PHONY : ocam_driver/CMakeFiles/camera_subscriber.dir/clean

ocam_driver/CMakeFiles/camera_subscriber.dir/depend:
	cd /home/marco/Tesis/ROS/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marco/Tesis/ROS/src /home/marco/Tesis/ROS/src/ocam_driver /home/marco/Tesis/ROS/build /home/marco/Tesis/ROS/build/ocam_driver /home/marco/Tesis/ROS/build/ocam_driver/CMakeFiles/camera_subscriber.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : ocam_driver/CMakeFiles/camera_subscriber.dir/depend

