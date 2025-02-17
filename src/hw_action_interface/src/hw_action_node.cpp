#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/FollowJointTrajectoryAction.h>





int main(int argc, char **argv)
{
  // Initialize the ROS node


  ros::init(argc, argv, "hw_action_interface");
  ros::NodeHandle nh;
  std::shared_ptr<actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction>> actionClient_;

  // Create an instance of your robot

  // Create the controller manager
  // Setup a separate thread to service ROS callbacks
  ros::AsyncSpinner spinner(1);
  spinner.start();

  // Setup for the control loop
  ros::Time prev_time = ros::Time::now();
  ros::Rate rate(10.0); // 10 Hz rate
  
  while (ros::ok())
  {
    // Get current time and compute elapsed time
    const ros::Time time = ros::Time::now();
    const ros::Duration period = time - prev_time;
    prev_time = time;

    // Execution of the control loop
    
    // Sleep to maintain loop rate
    rate.sleep();
  }

  return 0;
}
