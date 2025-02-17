#include <pluginlib/class_loader.hpp>
#include <ros/ros.h>

// MoveIt
#include <moveit/robot_model_loader/robot_model_loader.h>
#include <moveit/robot_state/conversions.h>
#include <moveit/planning_pipeline/planning_pipeline.h>
#include <moveit/planning_interface/planning_interface.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/kinematic_constraints/utils.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/PlanningScene.h>
#include <moveit_visual_tools/moveit_visual_tools.h>

// File: MotionPlanner.h

#ifndef MOTION_PLANNER_H
#define MOTION_PLANNER_H

class MotionPlanner
{
public:
    MotionPlanner(const std::string& robot_description, const std::string& planning_plugin, const std::string& request_adapters);
    // void initialize();
    // bool planGoal();
    // void visualizeTrajectory();
    // // Add more public member functions as needed

private:
    // Initialization functions
    // void initScene();
    // void initVisualTools();
    // // Planning functions
    // void setupPlanningRequest();
    // // Visualization functions
    // void publishTrajectory();

    // Member variables
    ros::NodeHandle node_handle_;
    ros::AsyncSpinner spinner_;
    robot_model_loader::RobotModelLoaderPtr robot_model_loader_;
    planning_scene_monitor::PlanningSceneMonitorPtr planning_scene_monitor_;
    planning_pipeline::PlanningPipelinePtr planning_pipeline_;
    moveit_visual_tools::MoveItVisualTools visual_tools_;
    moveit::core::RobotModelPtr robot_model_;
    moveit::core::RobotStatePtr robot_state_;
    
    // Additional members like planning requests, responses, etc.
};


#endif // MOTION_PLANNER_H
