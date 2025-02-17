#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <std_msgs/Float64MultiArray.h>








class MyRobot : public hardware_interface::RobotHW
{
public:
  MyRobot()
  {
  }

  

  bool init(ros::NodeHandle& nh)
  {
    // Initialization code moved from constructor
    // Get controller joint names from parameter server
    
    // Register joints with the hardware interface
    //joint_state_interface for joint 1  
    hardware_interface::JointStateHandle state_handle_0("joint0", &pos[0], &vel[0], &eff[0]);
    jnt_state_interface.registerHandle(state_handle_0);
    hardware_interface::JointStateHandle state_handle_1("joint1", &pos[1], &vel[1], &eff[1]);
    jnt_state_interface.registerHandle(state_handle_1);
    hardware_interface::JointStateHandle state_handle_2("joint2", &pos[2], &vel[2], &eff[2]);
    jnt_state_interface.registerHandle(state_handle_2);
    hardware_interface::JointStateHandle state_handle_3("joint3", &pos[3], &vel[3], &eff[3]);
    jnt_state_interface.registerHandle(state_handle_3);
    registerInterface(&jnt_state_interface);
    
    hardware_interface::JointHandle pos_handle_0(jnt_state_interface.getHandle("joint0"), &cmd[0]);
    jnt_pos_interface.registerHandle(pos_handle_0);
    hardware_interface::JointHandle pos_handle_1(jnt_state_interface.getHandle("joint1"), &cmd[1]);
    jnt_pos_interface.registerHandle(pos_handle_1);
    hardware_interface::JointHandle pos_handle_2(jnt_state_interface.getHandle("joint2"), &cmd[2]);
    jnt_pos_interface.registerHandle(pos_handle_2);
    hardware_interface::JointHandle pos_handle_3(jnt_state_interface.getHandle("joint3"), &cmd[3]);
    jnt_pos_interface.registerHandle(pos_handle_3);
    registerInterface(&jnt_pos_interface);

    cmd_pub_ = nh.advertise<std_msgs::Float64MultiArray>("cmd_topic", 10);
    
    return true; // Indicate successful initialization
  }

  void read()
  {
    // Improve simulation by adding realistic sensor data reading
    // For example, read from subscribed topics or add noise to the positions
    pos[0] = cmd[0]; 
    pos[1] = cmd[1]; 
    pos[2] = cmd[2];
    pos[3] = cmd[3]; 

    eff[0] = cmd[0]; 
    eff[1] = cmd[1]; 
    eff[2] = cmd[2];
    eff[3] = cmd[3];



    // Update velocities and efforts if applicable
  }

  void write()
  {
    // Send commands to the actuators
    // For demonstration, we'll just print the commands

      std_msgs::Float64MultiArray cmd_msg;
      cmd_msg.data.resize(4);
      cmd_msg.data[0] = cmd[0];
      cmd_msg.data[1] = cmd[1];
      cmd_msg.data[2] = cmd[2];
      cmd_msg.data[3] = cmd[3];
      
      // Add error handling for the publisher
      if (cmd_pub_)
      {
        cmd_pub_.publish(cmd_msg);
      }
      else
      {
        ROS_ERROR("Command publisher not initialized.");
      }
      // ROS_INFO("%f, %f, %f", cmd[0], cmd[1], cmd[2]);
    
  }

private:
  hardware_interface::JointStateInterface jnt_state_interface;
  hardware_interface::PositionJointInterface jnt_pos_interface;
  ros::Publisher cmd_pub_;
  double cmd[4]= {0, 0, 0, 0};
  double pos[4]= {0, 0, 0, 0};
  double vel[4]= {0, 0, 0, 0};
  double eff[4]= {0, 0, 0, 0};
};


int main(int argc, char **argv)
{
  // Initialize the ROS node
  ros::init(argc, argv, "hw_interface");
  ros::NodeHandle nh;

  // Create an instance of your robot
  MyRobot robot;
  if (!robot.init(nh))
  {
    ROS_FATAL("Failed to initialize the robot.");
    return -1;
  }

  // Create the controller manager
  controller_manager::ControllerManager cm(&robot, nh);
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
    robot.read();
    cm.update(time, period);
    
    robot.write();

    // Sleep to maintain loop rate
    rate.sleep();
  }

  return 0;
}
