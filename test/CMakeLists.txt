cmake_minimum_required(VERSION 2.8)
project(rs_common_test)
# Add definitions
if(WIN32 AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "C:/local" CACHE PATH "Installation directory" FORCE)
endif()
if(MSVC)
  add_definitions(-D_WIN32_WINNT=0x0501)
  set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs")
else()
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build")
  set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS}")
endif()

# Set dependent libraries
set(OPENCV_HEADER_DIR "" CACHE PATH "The path to opencv headers")
set(OPENCV_LIBRARY_DIR "" CACHE PATH "The path to opencv libraries")
set(DEPENDENT_LIBS opencv_core)
include_directories(
  ${OPENCV_HEADER_DIR}
)
link_directories(
  ${OPENCV_LIBRARY_DIR}
)

# Build information
set(EXECUTABLES "type_test")
foreach(target IN LISTS EXECUTABLES)
  add_executable(${target} src/${target}.cpp)
  target_link_libraries(${target} ${DEPENDENT_LIBS})
endforeach()

# Set installation
foreach(target IN LISTS EXECUTABLES)
  install(
    TARGETS ${target}
    RUNTIME DESTINATION bin
  )
endforeach()