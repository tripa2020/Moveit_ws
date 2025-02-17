#include "testbot_hw_interface/MyRobot.h"

MyRobot::MyRobot(ros::NodeHandle& nh)
{
    // Initialize joint command arrays
    for (int i = 0; i < 3; ++i) {
        cmd_[i] = 0.0;
        pos_[i] = 0.0;
        vel_[i] = 0.0;
        eff_[i] = 0.0;
    }

    // Register joint states
    hardware_interface::JointStateHandle state_handle_1("joint1", &pos_[0], &vel_[0], &eff_[0]);
    jnt_state_interface_.registerHandle(state_handle_1);

    hardware_interface::JointStateHandle state_handle_2("joint2", &pos_[1], &vel_[1], &eff_[1]);
    jnt_state_interface_.registerHandle(state_handle_2);

    hardware_interface::JointStateHandle state_handle_3("joint3", &pos_[2], &vel_[2], &eff_[2]);
    jnt_state_interface_.registerHandle(state_handle_3);

    registerInterface(&jnt_state_interface_);

    // Register joint command interfaces
    hardware_interface::JointHandle pos_handle_1(jnt_state_interface_.getHandle("joint1"), &cmd_[0]);
    jnt_pos_interface_.registerHandle(pos_handle_1);

    hardware_interface::JointHandle pos_handle_2(jnt_state_interface_.getHandle("joint2"), &cmd_[1]);
    jnt_pos_interface_.registerHandle(pos_handle_2);

    hardware_interface::JointHandle pos_handle_3(jnt_state_interface_.getHandle("joint3"), &cmd_[2]);
    jnt_pos_interface_.registerHandle(pos_handle_3);

    registerInterface(&jnt_pos_interface_);

    // Initialize the action client using smart pointer
    traj_client_ = std::make_unique<TrajClient>("test_controller/follow_joint_trajectory", true);

    // Wait for the action server to come up
    while(!traj_client_->waitForServer(ros::Duration(5.0))){
        ROS_INFO("Waiting for the follow_joint_trajectory action server to start...");
    }
    ROS_INFO("Connected to follow_joint_trajectory action server.");

    // Initialize the publisher
    cmd_pub_ = nh.advertise<std_msgs::Float64MultiArray>("cmd_topic", 10);
}

MyRobot::~MyRobot()
{
    // Destructor handled by smart pointer
}

void MyRobot::read()
{
    // Simulate reading joint states
    pos_[0] += 0.001;
    pos_[1] += 0.001;
    pos_[2] += 0.001;

    // In a real scenario, replace with actual sensor readings
}

void MyRobot::write()
{
    // Create and populate the message
    std_msgs::Float64MultiArray cmd_msg;
    cmd_msg.data.resize(3);
    cmd_msg.data[0] = cmd_[0];
    cmd_msg.data[1] = cmd_[1];
    cmd_msg.data[2] = cmd_[2];
    
    // Publish the command
    cmd_pub_.publish(cmd_msg);

    // Log the published commands
    ROS_INFO("Published Commands: [%f, %f, %f]", cmd_[0], cmd_[1], cmd_[2]);

    // In a real scenario, send 'cmd_' to your hardware (e.g., via serial to Arduino)
}
control_msgs::FollowJointTrajectoryGoal MyRobot::armExtensionTrajectory()
{
    control_msgs::FollowJointTrajectoryGoal goal;

    // Define which joints the trajectory will control
    goal.trajectory.joint_names.push_back("joint1");
    goal.trajectory.joint_names.push_back("joint2");
    goal.trajectory.joint_names.push_back("joint3");

    // We will have 2 points in this trajectory
    goal.trajectory.points.resize(2);

    // First point
    int ind = 0;
    goal.trajectory.points[ind].positions.resize(3);
    goal.trajectory.points[ind].positions[0] = 0.0;
    goal.trajectory.points[ind].positions[1] = 0.0;
    goal.trajectory.points[ind].positions[2] = 0.0;

    goal.trajectory.points[ind].velocities.resize(3, 0.0);
    goal.trajectory.points[ind].time_from_start = ros::Duration(1.0);

    // Second point
    ind = 1;
    goal.trajectory.points[ind].positions.resize(3);
    goal.trajectory.points[ind].positions[0] = -0.3;
    goal.trajectory.points[ind].positions[1] =  0.2;
    goal.trajectory.points[ind].positions[2] = -0.1;

    goal.trajectory.points[ind].velocities.resize(3, 0.0);
    goal.trajectory.points[ind].time_from_start = ros::Duration(2.0);

    return goal;
}
void MyRobot::doneCb(const actionlib::SimpleClientGoalState& state,
                     const control_msgs::FollowJointTrajectoryResultConstPtr& result)
{
    if (state == actionlib::SimpleClientGoalState::SUCCEEDED)
    {
        ROS_INFO("Trajectory execution succeeded.");
    }
    else
    {
        ROS_WARN("Trajectory execution failed: %s", state.toString().c_str());
    }
}

void MyRobot::activeCb()
{
    ROS_INFO("Trajectory goal just went active.");
}

void MyRobot::feedbackCb(const control_msgs::FollowJointTrajectoryFeedbackConstPtr& feedback)
{
    ROS_INFO_THROTTLE(1, "Received Feedback: Positions [%f, %f, %f]",
                      feedback->actual.positions[0],
                      feedback->actual.positions[1],
                      feedback->actual.positions[2]);
}

void MyRobot::sendGoal(control_msgs::FollowJointTrajectoryGoal goal)
{
    // Set the start time for the trajectory slightly in the future
    goal.trajectory.header.stamp = ros::Time::now() + ros::Duration(1.0);

    // Send the goal with callbacks
    traj_client_->sendGoal(goal,
                           boost::bind(&MyRobot::doneCb, this, _1, _2),
                           boost::bind(&MyRobot::activeCb, this),
                           boost::bind(&MyRobot::feedbackCb, this, _1));
}