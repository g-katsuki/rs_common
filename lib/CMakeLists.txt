cmake_minimum_required(VERSION 2.8)
project(rs_common)
# Add definitions
if(WIN32 AND CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "C:/local" CACHE PATH "Installation directory" FORCE)
endif()
# Set installation
install(DIRECTORY include/ryusei DESTINATION include)