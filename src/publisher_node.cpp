
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>
#include <cinttypes>
#include <string>

#include "publisher_package/topic_name.h"

int main(int argc, char** argv) {

  ros::init(argc, argv, "publisher_node");

  ros::NodeHandle nh;

  ros::Publisher chatter_pub = nh.advertise<std_msgs::String>(topic_name, 1000);
  ros::Rate loop_rate(1);

  std_msgs::String msg;
  std::stringstream ss;

  uint64_t count = 0;
  while (ros::ok()) {

    ss << "hello world " << count++;
    msg.data = ss.str();
    ROS_INFO("%s", msg.data.c_str());

    chatter_pub.publish(msg);

    ss.str(std::string());

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
