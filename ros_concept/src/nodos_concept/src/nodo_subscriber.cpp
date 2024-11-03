#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "chrono"


using std::placeholders::_1;
using namespace std::chrono_literals;
class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("minimal_subscriber")
  {
    auto topic_callback =
      [this](std_msgs::msg::String::UniquePtr msg) -> void {
        RCLCPP_INFO(this->get_logger(), "I heard from lambda function : '%s'", msg->data.c_str());
      };

    subscription_1_ =
      this->create_subscription<std_msgs::msg::String>("topic_1", 10, topic_callback);
    
    subscription_2_ =
      this->create_subscription<std_msgs::msg::String>("topic_1", 10, std::bind(&MinimalSubscriber::topicCallback_2, this,_1));
    //void callback(){

    std::function<void(std_msgs::msg::String)> func1 = std::bind(&MinimalSubscriber::topicCallback_2, this,_1);

    subscription_3_ =
      this->create_subscription<std_msgs::msg::String>("topic_1", 10, func1);
    var_ = 0;


  }
  ~MinimalSubscriber(){

    RCLCPP_INFO(this->get_logger(), "Desctructor was call");

  }
    void topicCallback_2(const std_msgs::msg::String &msg)
    {
        // Write a message every time a new message is received on the topic.
        RCLCPP_INFO_STREAM(get_logger(), "I heard: " << msg.data.c_str());
        var_ =2;
 
    }

private:
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_1_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_2_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_3_;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_4_;
  int var_;
};

class robot{
  public:
    robot(){

      printf("Robot inicializado");
    }
  private:
    std::string name_robot_;

};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node_1 =std::make_shared<MinimalSubscriber>();
  //MinimalSubscriber *node_2 = new MinimalSubscriber();

  // init time 
  rclcpp::Time start_time = node_1->now();
  auto lapse_time = rclcpp::Duration(2,0);
  auto rate = rclcpp::Rate(2);
  while( lapse_time > node_1->now() - start_time){

    rclcpp::spin_some(node_1);
    rate.sleep();
  }
  node_1.reset();
  // update time
  start_time = node_1->now();
  while( lapse_time > node_1->now() - start_time){

    rclcpp::spin_some(node_1);
    rate.sleep();
  }
  rclcpp::shutdown();
  return 0;
}