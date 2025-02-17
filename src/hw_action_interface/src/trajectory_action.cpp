#include <ros/ros.h>
#include <actionlib/client/simple_action_client.h>
#include <control_msgs/FollowJointTrajectoryAction.h>
#include <vector>
#include <string>
#include <actionlib/client/simple_action_client.h>

typedef actionlib::SimpleActionClient< control_msgs::FollowJointTrajectoryAction > TrajClient;

class RobotArm
{
private:
  TrajClient* traj_client_;

public:
  RobotArm() 
  {
    // Use the standard FollowJointTrajectory action name
    traj_client_ = new TrajClient("test_controller/follow_joint_trajectory", true);
    // Wait for the action server to come up
    while(!traj_client_->waitForServer(ros::Duration(5.0))){
      ROS_INFO("Waiting for the follow_joint_trajectory action server to start...");
    }
    ROS_INFO("Connected to follow_joint_trajectory action server.");
  }

  ~RobotArm()
  {
    delete traj_client_;
  }

  void startTrajectory(control_msgs::FollowJointTrajectoryGoal goal)
  {
    // Start the trajectory slightly in the future
    goal.trajectory.header.stamp = ros::Time::now() + ros::Duration(1.0);
    traj_client_->sendGoal(goal);
  }

  control_msgs::FollowJointTrajectoryGoal armExtensionTrajectory()
  {
    control_msgs::FollowJointTrajectoryGoal goal;

    // Adjust the number of joints to match your robot configuration:
    // Here we assume 3 joints because we pushed 3 joint names
    goal.trajectory.joint_names.push_back("joint1");
    goal.trajectory.joint_names.push_back("joint2");
    goal.trajectory.joint_names.push_back("joint3");

    goal.trajectory.points.resize(2);

    // First point
    int ind = 0;
    goal.trajectory.points[ind].positions.resize(3);
    goal.trajectory.points[ind].positions[0] = 0.0;
    goal.trajectory.points[ind].positions[1] = 0.0;
    goal.trajectory.points[ind].positions[2] = 0.0;

    goal.trajectory.points[ind].velocities.resize(3);
    for (int j = 0; j < 3; ++j)
      goal.trajectory.points[ind].velocities[j] = 0.0;

    goal.trajectory.points[ind].time_from_start = ros::Duration(2.0);

    // Second point
    ind = 1;
    goal.trajectory.points[ind].positions.resize(3);
    goal.trajectory.points[ind].positions[0] = -0.3;
    goal.trajectory.points[ind].positions[1] =  0.2;
    goal.trajectory.points[ind].positions[2] = -0.1;

    goal.trajectory.points[ind].velocities.resize(3);
    for (int j = 0; j < 3; ++j)
      goal.trajectory.points[ind].velocities[j] = 0.0;

    goal.trajectory.points[ind].time_from_start = ros::Duration(4.0);

    return goal;
  }

  actionlib::SimpleClientGoalState getState()
  {
    return traj_client_->getState();
  }
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "robot_driver");

  RobotArm arm;
  arm.startTrajectory(arm.armExtensionTrajectory());

  // Wait for trajectory completion
  while(!arm.getState().isDone() && ros::ok())
  {
    ros::Duration(0.05).sleep();
  }

  return 0;
}