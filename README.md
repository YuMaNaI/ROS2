## ros2_ws  
ロボットプログラミング用  
## 概要
現在の時刻を取得する
## 機能
・フォーマットした時刻を文字列として発行  
・一秒ごとに時刻を更新して出力  
・プログラムはシステムの現在時刻を取得し、YYYY-MM-DD HH:MM:SS 形式で整形します。  
## テスト
[![Build and Test ROS2 Package on Multiple Versions](https://github.com/YuMaNaI/ros2_ws/actions/workflows/build_test.yml/badge.svg)](https://github.com/YuMaNaI/ros2_ws/actions/workflows/build_test.yml)
## テスト環境
Ubuntu 22.04 LTS
## インストール  
このパッケージはROS2　Humble および Iron に対応しています。  
1.ワークスペースの作成  
```
mkdir -p ~/ros2_ws/src
cd ~/ros2_ws/src
```  
2.リポジトリをクローン  
```git clone https://github.com/YuMaNaI/hello_pkg.git```  
3.ビルド  
```
cd ~/ros2_ws
colcon build --packages-select hello_pkg
```
4.セットアップファイルをソース  
```source install/setup.bash```  

## 使用方法  
ノードの起動  
```ros2 run hello_pkg hello```  

出力例  
```
data: "現在の時刻: 2024-12-25 14:30:15"
data: "現在の時刻: 2024-12-25 14:30:16"
```
## プログラム例
一秒ごとにメッセージを作成  
```
timer_ = this->create_wall_timer(
    std::chrono::seconds(1),
    std::bind(&TimePublisher::publish_time, this)
);
```  

メッセージ作成、発行
```
void publish_time()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S");  

    auto message = std_msgs::msg::String();
    message.data = "現在の時刻: " + ss.str();
    publisher_->publish(message);
}
```  

## ライセンス  
- このプロジェクトはYuMaNaIのもとで公開されています。  
- このソフトパッケージは、BSD-3-Clause license の下、再頒布および使用が許可されます  
- © 2024 Yuma Naito  
