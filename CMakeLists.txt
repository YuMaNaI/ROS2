cmake_minimum_required(VERSION 3.8)
project(hello_pkg)

find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(hello src/hello.cpp)
ament_target_dependencies(hello rclcpp std_msgs)

install(TARGETS
  hello
  DESTINATION lib/${PROJECT_NAME})

ament_package()
