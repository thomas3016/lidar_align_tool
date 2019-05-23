cmake_minimum_required(VERSION 2.8.3)
project(lidar_align_tool)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(Qt5Widgets REQUIRED)
find_package(Eigen3 REQUIRED)
find_package (PCL  REQUIRED)
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  sensor_msgs
  std_msgs
  cv_bridge
  pcl_conversions
  pcl_ros
)

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)

catkin_package(

)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ${EIGEN3_INCLUDE_DIR}
  ${Qt5Widgets_INCLUDE_DIRS}
  include/
  include/lidar_align_tool
  ui/
)

set(CMAKE_AUTOMOC ON)

add_library(align_mainwindow
        src/mainwindow.cpp
        include/lidar_align_tool/mainwindow.h
        )
target_link_libraries(align_mainwindow 
       ${Qt5Widgets_LIBRARIES} 
       ${catkin_LIBRARIES} 
       ${PCL_LIBRARIES}
)

add_executable(align_node
        node/main.cpp
        )
target_link_libraries(align_node 
        align_mainwindow 
        ${PCL_LIBRARIES}
        )

add_executable(align_adjust_node
        node/adjust_node.cpp
        )
target_link_libraries(align_adjust_node 
       align_mainwindow
       ${PCL_LIBRARIES} 
       ${catkin_LIBRARIES}
)



