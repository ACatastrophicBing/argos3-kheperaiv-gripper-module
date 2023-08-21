if(ARGOS_BUILD_FOR_SIMULATOR)
  add_library(kheperaiv_diffusion MODULE kheperaiv_diffusion.h kheperaiv_diffusion.cpp)
endif(ARGOS_BUILD_FOR_SIMULATOR)
if(ARGOS_BUILD_FOR STREQUAL "khiv")
  add_executable(kheperaiv_diffusion kheperaiv_diffusion.h kheperaiv_diffusion.cpp ${CMAKE_SOURCE_DIR}/plugins/robots/kheperaiv/real_robot/main.cpp)
endif(ARGOS_BUILD_FOR STREQUAL "khiv")

target_link_libraries(kheperaiv_diffusion
  argos3core_${ARGOS_BUILD_FOR}
  argos3plugin_${ARGOS_BUILD_FOR}_kheperaiv
  argos3plugin_${ARGOS_BUILD_FOR}_genericrobot)


if(ARGOS_BUILD_FOR_SIMULATOR)
  add_library(kheperaiv_gripper_test MODULE kheperaiv_gripper_test.h kheperaiv_gripper_test.cpp)
endif(ARGOS_BUILD_FOR_SIMULATOR)
if(ARGOS_BUILD_FOR STREQUAL "khiv")
add_executable(kheperaiv_gripper_test kheperaiv_gripper_test.h kheperaiv_gripper_test.cpp ${CMAKE_SOURCE_DIR}/plugins/robots/kheperaiv/real_robot/main.cpp)
endif(ARGOS_BUILD_FOR STREQUAL "khiv")

target_link_libraries(kheperaiv_gripper_test
  argos3core_${ARGOS_BUILD_FOR}
  argos3plugin_${ARGOS_BUILD_FOR}_kheperaiv
  argos3plugin_${ARGOS_BUILD_FOR}_genericrobot)