#include <ros/ros.h>
#include "husky_highlevel_controller/HuskyHighlevelController.hpp"
#include <sensor_msgs/LaserScan.h>


void scan_callback(sensor_msgs::LaserScan scaned_data )
{ 
  ROS_INFO_STREAM(*std::min_element(scaned_data.ranges.begin(),scaned_data.ranges.end()));
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "husky_highlevel_controller");
  ros::NodeHandle nodeHandle("~");

  husky_highlevel_controller::HuskyHighlevelController huskyHighlevelController(nodeHandle);

  ros::Subscriber subsriber= nodeHandle.subscribe("/scan",5 , scan_callback);
  ROS_INFO("subscribed to scan");
  ros::spin();
  return 0;
}
