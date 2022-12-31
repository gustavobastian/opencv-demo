cmake_minimum_required(VERSION 3.0.0)
project(opencv-demo VERSION 0.1.0)
find_package( OpenCV REQUIRED )
##find_package(OpenCV REQUIRED PATHS /usr/local/share/OpenCV NO_DEFAULT_PATH) # manual specification of the OpenCVConfig.cmake path is necessary since otherwise, cmake assigns /opt/local a higher priority and ocv2.4 will be used

message(STATUS "OpenCV_INCLUDE_DIRS = ${OpenCV_INCLUDE_DIRS}")
message(STATUS "OpenCV_LIBS = ${OpenCV_LIBS}")


include(CTest)
enable_testing()

include_directories( ${OpenCV_INCLUDE_DIRS} )


add_executable(opencv-demo main.cpp)

target_link_libraries( opencv-demo ${OpenCV_LIBS} )

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
