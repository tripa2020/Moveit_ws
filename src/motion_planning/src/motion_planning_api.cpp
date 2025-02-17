#include <pluginlib/class_loader.hpp>
#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/robot_state/conversions.h>
#include <moveit/planning_pipeline/planning_pipeline.h>
#include <moveit/planning_interface/planning_interface.h>
#include <moveit/planning_scene_monitor/planning_scene_monitor.h>
#include <moveit/kinematic_constraints/utils.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <moveit_msgs/PlanningScene.h>
#include <moveit_visual_tools/moveit_visual_tools.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>
#include <tf2/LinearMath/Quaternion.h>
#include <geometry_msgs/PoseStamped.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <moveit_msgs/GetPositionIK.h>


class MotionPlanner {
public:
  MotionPlanner() {
    
    
    // Initialize the robot model loader and planning scene monitor
    robot_model_loader_ = std::make_shared<robot_model_loader::RobotModelLoader>("robot_description");
    robot_model_ = robot_model_loader_->getModel();
    planning_scene_monitor_ = std::make_shared<planning_scene_monitor::PlanningSceneMonitor>(robot_model_loader_);
    planning_scene_monitor_->startSceneMonitor();
    planning_scene_monitor_->startWorldGeometryMonitor();
    planning_scene_monitor_->startStateMonitor("/joint_states");

    // Initialize the planning pipeline
    robot_model_ = robot_model_loader_->getModel();
    robot_state_ptr = std::make_shared<moveit::core::RobotState>(planning_scene_monitor::LockedPlanningSceneRO(planning_scene_monitor_)->getCurrentState());
    const moveit::core::JointModelGroup* joint_model_group = robot_state_ptr->getJointModelGroup("tripp_arm");
    planning_pipeline_ = std::make_shared<planning_pipeline::PlanningPipeline>(robot_model_, node_handle_, "planning_plugin", "request_adapters");
  }
// NEED TO GET THE CURRENT STATE OF THE ROBOT IN ORDER FOR PLANNING TO WORK
  void updateCurrentState() {
    robot_state_ptr = planning_scene_monitor_->getStateMonitor()->getCurrentState();

  }
// psuedo code for the planning need to make sure it is updated with the current robot state
  
  
void plan(moveit::planning_interface::MoveGroupInterface& move_group_interface) {
  // // 1. Create a motion plan request
  //   planning_interface::MotionPlanRequest req;
  //   planning_interface::MotionPlanResponse res;

    // 2. Define your pose goal 
    geometry_msgs::PoseStamped pose;
    pose.header.frame_id = "link3";  // Set your base frame
    pose.pose.position.x = 0.4;
    pose.pose.position.y = 0.12;
    pose.pose.position.z = 0.2;
    pose.pose.orientation.w = 1.0;
    move_group_interface.setPoseTarget(pose); // Set the target pose

    // 3. Plan the motion
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    bool success = (move_group_interface.plan(my_plan) == moveit::core::MoveItErrorCode::SUCCESS);

    // 4. Check for planning errors
    if (!success) {
      ROS_ERROR("Could not compute plan successfully");
      return;
    }else{
      ROS_INFO("Plan successful");
    }

  // 5. (Optional) Visualize the trajectory
  // ... (You can add your visualization code here if needed) ...
    // ROS_INFO_NAMED("tutorial", "Visualizing plan 1 as trajectory line");
    // visual_tools_.publishAxisLabeled(pose, "pose1");
    // visual_tools_.publishText(pose, "Pose Goal", rvt::WHITE, rvt::XLARGE);
    // visual_tools_.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
    // visual_tools_.trigger();
    // visual_tools_.prompt("Press 'next' in the RvizVisualToolsGui window to continue the demo");
        }


        // void current_state() {
  // // Get a shared pointer to the current state
  //   moveit::core::RobotStatePtr current_state_ptr = planning_scene_monitor_->getStateMonitor()->getCurrentState();
  //   // Dereference the pointer to get the actual RobotState object
  //   moveit::core::RobotState current_state = *current_state_ptr; 
  //   const moveit::core::JointModelGroup* joint_model_group = current_state.getJointModelGroup("tripp_arm"); 
  //   if (!joint_model_group) {
  //       ROS_ERROR("Failed to get joint model group 'tripp_arm'");
  //       return;
  //   }

  //   const std::vector<std::string>& joint_names = joint_model_group->getVariableNames();
  //   std::vector<double> joint_values;
  //   current_state.copyJointGroupPositions(joint_model_group, joint_values);

  //   std::stringstream ss;
  //   ss << "Current position: [";
  //   for (std::size_t i = 0; i < joint_names.size(); ++i) {
  //       ss << joint_values[i];
  //       if (i < joint_names.size() - 1) {
  //       ss << ", ";
  //       }
  //   }
  //   ss << "]";

  //   ROS_INFO_STREAM(ss.str()); // Print the formatted output

  //   }

    // void executePlan(const planning_interface::MotionPlanResponse& res) {
    //   moveit::planning_interface::MoveGroupInterface move_group("tripp_arm");
    //   moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    //   my_plan.trajectory_ = res.trajectory_; 
    //   move_group.execute(my_plan);
    // }
private:
  ros::NodeHandle node_handle_;
  // Robot model and Robot state
  robot_model_loader::RobotModelLoaderPtr robot_model_loader_;
  moveit::core::RobotModelPtr robot_model_;
  moveit::core::RobotStatePtr robot_state_ptr;
  // Planning Scene init
  planning_scene_monitor::PlanningSceneMonitorPtr planning_scene_monitor_;
  planning_pipeline::PlanningPipelinePtr planning_pipeline_;
  // Joint Group init
  const moveit::core::JointModelGroup* joint_model_group_;
  //moveit interface
  moveit_visual_tools::MoveItVisualTools visual_tools_;

};


void ikCallback(const moveit_msgs::GetPositionIK::Response& res, const ros::ServiceClient& service_client)
{
  ROS_INFO_STREAM("IK result received: " << res);
  // Process the IK solution here (e.g., visualize, execute)
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "motion_planning");
  ros::NodeHandle nh;
  ros::AsyncSpinner spinner(1);
  spinner.start();
  moveit_visual_tools::MoveItVisualTools visual_tools("linkb");
  moveit::planning_interface::MoveGroupInterface move_group_interface("tripp_arm");

  namespace rvt = rviz_visual_tools;

  ros::ServiceClient service_client = nh.serviceClient<moveit_msgs::GetPositionIK>("/compute_ik");
  ros::Publisher planning_robot_state_publisher =
      nh.advertise<moveit_msgs::DisplayRobotState>("/display_robot_state", 1);
  
  while (!service_client.exists())
  {
    ROS_INFO("Waiting for service");
    ros::Duration(1.0).sleep();
  }

  MotionPlanner motion_planner;
  
  moveit_msgs::GetPositionIK::Request service_request;
  moveit_msgs::GetPositionIK::Response service_response;
  service_request.ik_request.group_name = "tripp_arm";
  service_request.ik_request.pose_stamped.header.frame_id = "link4";
  service_request.ik_request.pose_stamped.pose.position.x = 0.4;
  service_request.ik_request.pose_stamped.pose.position.y = 0.15;
  service_request.ik_request.pose_stamped.pose.position.z = 0.2;

  service_request.ik_request.pose_stamped.pose.orientation.x = 1.0;
  service_request.ik_request.pose_stamped.pose.orientation.y = 0.0;
  service_request.ik_request.pose_stamped.pose.orientation.z = 0.0;
  service_request.ik_request.pose_stamped.pose.orientation.w = 0.0;

   service_client.call(service_request, service_response);
  ROS_INFO_STREAM(
      "Result: " << ((service_response.error_code.val == service_response.error_code.SUCCESS) ? "True " : "False ")
                 << service_response.error_code.val);



  // Get the current state
  
  // for (int x = 0; x <= 180; x += 10) {
  //   // 1. Convert angle to radians
  //   double radians = x * M_PI / 180.0; 

    //   // 2. Create a quaternion
  //   tf2::Quaternion q;
  //   q.setRPY(radians, 0, 0); // Rotate around x-axis
  //   geometry_msgs::Quaternion orientation = tf2::toMsg(q);
  //   // 3. Create a PoseStamped message
  //   geometry_msgs::PoseStamped pose;
  //   pose.header.frame_id = "linkb";
  //   pose.pose.position.x = 0.4;     // Corrected
  //   pose.pose.position.y = 0.16;
  //   pose.pose.position.z = 0.2;
  //   pose.pose.orientation = orientation; 

  //   std::size_t arrow_id = x/10;
  //   visual_tools.publishArrow(pose, rviz_visual_tools::RED, rviz_visual_tools::SMALL, arrow_id);

  //   ROS_INFO_STREAM("Angle: " << x << " degrees, Orientation (x, y, z, w): " 
  //                   << pose.pose.orientation.x << ", " 
  //                   << pose.pose.orientation.y << ", " 
  //                   << pose.pose.orientation.z << ", " 
  //                   << pose.pose.orientation.w);

  //   // 6. Wait (optional)
  //   ros::Duration(.2).sleep(); 
  //   visual_tools.trigger(); 
  // }
  
  

  visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to continue the demo");
  // Publish a marker at the end-effector position
  geometry_msgs::PoseStamped current_pose = move_group_interface.getCurrentPose();
  visual_tools.publishSphere(current_pose.pose, rviz_visual_tools::RED, rviz_visual_tools::LARGE);
  visual_tools.trigger(); 
  // Check for planning errors
  
  
  
  
  visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to continue the demo");


  
  
}



    

 