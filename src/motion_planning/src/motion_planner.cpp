#include "motion_planner.h"
#include <moveit/robot_model_loader/robot_model_loader.h>
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

class MotionPlanner{
    private:

    public:
        MotionPlanner(){
            

        }




}
// void MotionPlanner::initialize()
// {
//     initScene();
//     initVisualTools();
//     // Additional initialization if needed
// }

// void MotionPlanner::initScene()
// {
//     planning_scene_monitor_->startSceneMonitor();
//     planning_scene_monitor_->startWorldGeometryMonitor();
//     planning_scene_monitor_->startStateMonitor();
// }

// void MotionPlanner::initVisualTools()
// {
//     visual_tools_.deleteAllMarkers();
//     visual_tools_.loadRemoteControl();
//     Eigen::Isometry3d text_pose = Eigen::Isometry3d::Identity();
//     text_pose.translation().z() = 1.75;
//     visual_tools_.publishText(text_pose, "Motion Planning Pipeline Demo", rviz_visual_tools::WHITE, rviz_visual_tools::XLARGE);
//     visual_tools_.trigger();
//     visual_tools_.prompt("Press 'next' in the RvizVisualToolsGui window to start the demo");
// }

// bool MotionPlanner::planGoal()
// {
//     // Implement planning logic here
//     // Return true if planning succeeds, false otherwise
//     return true;
// }

// void MotionPlanner::visualizeTrajectory()
// {
//     // Implement visualization logic here
// }
// cpp
// Copy code
// // File: main.cpp

// #include "MotionPlanner.h"

// int main(int argc, char** argv)
// {
//     ros::init(argc, argv, "move_group_tutorial");
//     MotionPlanner planner("robot_description", "planning_plugin", "request_adapters");
//     planner.initialize();

//     while (ros::ok())
//     {
//         if (planner.planGoal())
//         {
//             planner.visualizeTrajectory();
//         }
//         // Additional loop logic if needed
//     }

//     return 0;
// }