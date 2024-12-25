cmake_minimum_required(VERSION 3.8)  # 必要なCMakeのバージョン
project(hello_pkg)                  # プロジェクト名（パッケージ名と同じにする）

# 必要なパッケージを探す
find_package(ament_cmake REQUIRED)  # ビルドシステム
find_package(rclcpp REQUIRED)       # ROS2のC++クライアントライブラリ
find_package(std_msgs REQUIRED)     # メッセージ型ライブラリ

# 実行ファイルのビルド設定
add_executable(hello src/hello.cpp) # 実行ファイル名とソースファイルの指定

# 実行ファイルが依存するパッケージの指定
ament_target_dependencies(hello rclcpp std_msgs)

# インストール先の設定
install(TARGETS
  hello
  DESTINATION lib/${PROJECT_NAME})  # パッケージ名のディレクトリに配置

# パッケージとして登録
ament_package()
