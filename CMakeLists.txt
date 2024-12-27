cmake_minimum_required(VERSION 3.8) # 3.10未満のバージョン警告は修正済み
project(hello_pkg)

find_package(ament_cmake REQUIRED) # ament_cmakeを必須に指定
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

add_executable(hello src/hello.cpp)
ament_target_dependencies(hello rclcpp std_msgs)

install(TARGETS
  hello
  DESTINATION lib/${PROJECT_NAME})

ament_package()
