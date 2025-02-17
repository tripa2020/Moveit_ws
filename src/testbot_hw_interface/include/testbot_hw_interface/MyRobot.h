#ifndef HW_ACTION_INTERFACE_MY_ROBOT_H
#define HW_ACTION_INTERFACE_MY_ROBOT_H

#include <ros/ros.h>
#include <controller_manager/controller_manager.h>
#include <hardware_interface/joint_command_interface.h>
#include <hardware_interface/joint_state_interface.h>
#include <hardware_interface/robot_hw.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <std_msgs/Float64MultiArray.h>


 // @brief Typedef for a SimpleActionClient specialized for FollowJointTrajectoryAction.
 
typedef actionlib::SimpleActionClient<control_msgs::FollowJointTrajectoryAction> TrajClient;

class MyRobot : public hardware_interface::RobotHW
{
public:
    MyRobot(ros::NodeHandle& nh);
    ~MyRobot();

    void read();
    void write();
    
    control_msgs::FollowJointTrajectoryGoal armExtensionTrajectory();

    // Callback functions
    void doneCb(const actionlib::SimpleClientGoalState& state,
               const control_msgs::FollowJointTrajectoryResultConstPtr& result);

    void activeCb();
    void feedbackCb(const control_msgs::FollowJointTrajectoryFeedbackConstPtr& feedback);

    // Function to send a goal with callbacks
    void sendGoal(control_msgs::FollowJointTrajectoryGoal goal);

private:
    std::unique_ptr<TrajClient> traj_client_;
    ros::Publisher cmd_pub_;

    hardware_interface::JointStateInterface jnt_state_interface_;
    hardware_interface::PositionJointInterface jnt_pos_interface_;

    double cmd_[3];
    double pos_[3];
    double vel_[3];
    double eff_[3];
};

#endif // HW_ACTION_INTERFACE_MY_ROBOT_H