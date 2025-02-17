#include <urdf/model.h>
#include "ros/ros.h"
#include "iostream"
#include <ros/package.h>

int main(int argc, char** argv){
  ros::init(argc, argv, "my_parser");

  // if (argc ){
  //   ROS_ERROR("Need a urdf file as argument");
  //   return -1;
  // }
  std::string urdf_file = "/home/alex/catkin_ws/src/tripp_description/urdf/tripp.urdf";

  urdf::Model model;
  if (!model.initFile(urdf_file)) {
    ROS_ERROR("Failed to parse URDF file: %s", urdf_file.c_str());
    return -1;
    }

    ROS_INFO("Successfully parsed URDF file: %s", urdf_file.c_str());
    return 0;

}