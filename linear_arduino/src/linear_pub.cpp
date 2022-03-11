#include "ros/ros.h"
#include "std_msgs/Int64.h"

#include <sstream>

int main(int argc, char **argv) {
  ros::init(argc, argv, "pub");
  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::Int64>("chatter", 1000);
  ros::Rate loop_rate(10);

  //int num = 0;
  
  while (ros::ok())
  {
    std_msgs::Int64 msg;
    // std::stringstream ss;

    msg.data = 1;
    ROS_INFO("%ld", msg.data);
    chatter_pub.publish(msg);
    ros::Duration(8).sleep();
  
    msg.data = 2;
    ROS_INFO("%ld", msg.data);
    chatter_pub.publish(msg);
    ros::Duration(8).sleep();
  }
  return 0;
}
