# Install script for directory: /home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/argos3/plugins/robots/kheperaiv/control_interface" TYPE FILE FILES
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_camera_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_encoder_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_ground_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_lidar_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_light_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_proximity_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_ultrasound_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_gripper_actuator.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_turret_actuator.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/control_interface/ci_kheperaiv_turret_encoder_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/control_interface/buzz_controller_kheperaiv.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/argos3/plugins/robots/kheperaiv/simulator" TYPE FILE FILES
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/dynamics2d_kheperaiv_model.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_entity.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_light_rotzonly_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_measures.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_ground_rotzonly_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_lidar_default_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_proximity_default_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_ultrasound_default_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_turret_entity.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_turret_encoder_default_sensor.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_turret_default_actuator.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_gripper_default_actuator.h"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/qtopengl_kheperaiv.h"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/argos3/plugins/simulator/visualizations/qt-opengl/textures" TYPE FILE FILES
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_texture_bottom.png"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_texture_side.png"
    "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/plugins/robots/kheperaiv/simulator/kheperaiv_texture_top.png"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_khiv_kheperaiv.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_khiv_kheperaiv.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_khiv_kheperaiv.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/argos3" TYPE SHARED_LIBRARY FILES "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/build_robot/plugins/robots/kheperaiv/libargos3plugin_khiv_kheperaiv.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_khiv_kheperaiv.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_khiv_kheperaiv.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_khiv_kheperaiv.so"
         OLD_RPATH "/home/midnightpegasus/Documents/WPI/MQP/Pinci_Send/argos3-kheperaiv-gripper-module/src/home/midnightpegasus/khepera4_development/libkhepera-2.1/lib:/home/midnightpegasus/anaconda3/lib:/usr/local/lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/argos3/libargos3plugin_khiv_kheperaiv.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
endif()

