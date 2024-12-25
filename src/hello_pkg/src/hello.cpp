#include "rclcpp/rclcpp.hpp"       // ROS2の基本ライブラリ
#include "std_msgs/msg/string.hpp" // メッセージ型ライブラリ
#include <chrono>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std::chrono_literals;

class TimePublisher : public rclcpp::Node
{
public:
    TimePublisher() : Node("time_publisher") // ノード名を設定
    {
        // パブリッシャーを作成
        publisher_ = this->create_publisher<std_msgs::msg::String>("current_time", 10);

        // 1秒ごとにデータを発行するタイマーを作成
        timer_ = this->create_wall_timer(
            1s, std::bind(&TimePublisher::publish_time, this));
    }

private:
    // 現在時刻を発行する関数
    void publish_time()
    {
        // 現在時刻を取得
        auto now = std::chrono::system_clock::now();
        std::time_t now_time = std::chrono::system_clock::to_time_t(now);

        // 時刻をフォーマット
        std::stringstream ss;
        ss << std::put_time(std::localtime(&now_time), "%Y-%m-%d %H:%M:%S");

        // メッセージの作成
        auto message = std_msgs::msg::String();
        message.data = "現在の時刻: " + ss.str();

        // メッセージを発行
        publisher_->publish(message);

        // コンソールログにも出力
        RCLCPP_INFO(this->get_logger(), "Published: '%s'", message.data.c_str());
    }

    // メンバ変数
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<TimePublisher>());
    rclcpp::shutdown();
    return 0;
}
