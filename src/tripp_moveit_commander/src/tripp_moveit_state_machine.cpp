#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>  // For tf2::fromMsg
#include <geometry_msgs/Pose.h>
#include <tf2/LinearMath/Quaternion.h>
#include <iostream>
#include <cmath>
#include <algorithm>

// The circle constant tau = 2*pi. One tau is one rotation in radians.
const double tau = 2 * M_PI;
// defining the lengths of the links
const double L1 = 0.2;
const double L2 = 0.15;
const double L3 = 0.05;

struct IKResult {
    double theta1;  // in radians
    double theta2;  // in radians
    double theta3;  // in radians
    double x_val ;  // in meters
};


IKResult I_k(double y, double z, double gam_deg) {
    // Convert gam from degrees to radians
    double gam = gam_deg * M_PI / 180.0;

    // Calculate intermediate values for the y-z plane
    double p_2y = y - L3 * std::cos(gam);
    double p_2z = z - L3 * std::sin(gam);

    // Compute the intermediate value for the cosine law
    double intermediate_value = (p_2y * p_2y + p_2z * p_2z - (L1 * L1 + L2 * L2)) / (2.0 * L2 * L1);
    // Clamp the value to the valid range of acos, i.e. [-1, 1]
    intermediate_value = std::max(-1.0, std::min(1.0, intermediate_value));

    // Calculate the angles using inverse trigonometric functions
    double theta2 = std::acos(intermediate_value);
    double theta1 = std::atan2(p_2z, p_2y) - std::atan2(L2 * std::sin(theta2), L1 + L2 * std::cos(theta2));
    double theta3 = gam - (theta1 + theta2);

    // Return the angles in radians
    return {theta1, theta2, theta3};
}
//Robot States
enum State {
  IDLE,             // Waiting for user input.
  RECEIVING_GOAL,   // Received a goal, now setting it.
  PLANNING,         // Planning a motion trajectory.
  EXECUTING,        // Executing the planned trajectory.
  ERROR_STATE,      // Handling any errors.
  FINISHED,
  REVIEW          // Exiting the program.
};

int main(int argc, char** argv)
{
  ros::init(argc, argv, "move_group_interface_tutorial");
  ros::NodeHandle node_handle;
  ros::AsyncSpinner spinner(1);
  spinner.start();
//******* INITIALIZE _***********
  static const std::string PLANNING_GROUP = "tripp_arm";
  moveit::planning_interface::MoveGroupInterface move_group_interface(PLANNING_GROUP);
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

  moveit::core::RobotStatePtr current_state = move_group_interface.getCurrentState();
  const moveit::core::JointModelGroup* joint_model_group =
      move_group_interface.getCurrentState()->getJointModelGroup(PLANNING_GROUP);
  
  moveit::planning_interface::MoveGroupInterface::Plan my_plan;


// ******Visualization*********
// Visualization
  
  namespace rvt = rviz_visual_tools;
  moveit_visual_tools::MoveItVisualTools visual_tools("world","/rviz_visual_tools");
  visual_tools.deleteAllMarkers();

 
  visual_tools.loadRemoteControl();

  Eigen::Isometry3d text_pose = Eigen::Isometry3d::Identity();
  text_pose.translation().z() = 1.0;
  visual_tools.publishText(text_pose, "State_Machine", rvt::WHITE, rvt::XLARGE);

  visual_tools.trigger();
  visual_tools.prompt("Press 'next' in the RvizVisualToolsGui window to start the demo");

  //******INITIALIZE STATE MACHINE */
  geometry_msgs::Pose target_pose;

  State tripp_state = IDLE;
  double x = 0.0, y = 0.0, z = 0.0;
  IKResult j_pos;  // Ensure IKResult has a proper default or is assigned before use.
  std::vector<double> joint_group_positions;


  ROS_INFO("State machine initialized. Waiting for pose goals...");
  while (ros::ok() && tripp_state != FINISHED) {
    switch (tripp_state)
    {
        case IDLE:
        {
            ROS_INFO(">>> Entering case IDLE (state=%d)", tripp_state);
            // Wait for user input to set a new pose goal
            ROS_INFO("Waiting for pose goal... [x , y, z ]");
            std::string input_line;
            std::getline(std::cin, input_line);

            ROS_INFO("Received input: %s", input_line.c_str());
            // Parse the input line to extract x, y, z values
            std::istringstream iss(input_line);
            if ((iss >> x >> y >> z)) {
              j_pos = I_k(y, z, 180);
              std::cout << "IK Result:\n";
              std::cout << "Theta1: " << j_pos.theta1 << " radians\n";
              std::cout << "Theta2: " << j_pos.theta2 << " radians\n";
              std::cout << "Theta3: " << j_pos.theta3 << " radians\n";
              

              tripp_state = RECEIVING_GOAL; 
              
                
            }else{
               
              ROS_ERROR("Invalid input. Please enter three numbers for x, y, z.");
              tripp_state = ERROR_STATE;
              
            }
            break;
            
    }
        case RECEIVING_GOAL:
        {
          ROS_INFO("State: RECEIVING_GOAL - Setting the target pose.");
          current_state = move_group_interface.getCurrentState();
          
          current_state->copyJointGroupPositions(joint_model_group, joint_group_positions);

        //********WORKSPACE CHECK - add later */
        // if (!( (0 < x && x < 1) && (0 < y && y < 0.3) && (0 < z && z < 0.3) )){
        //     ROS_ERROR("Invalid input. numbers are outside of workspace");
        //     tripp_state = ERROR_STATE;
        //     break; 
        //   }else{

          // Global joint _position vector


          joint_group_positions[0] = x; // meters
          joint_group_positions[1] = j_pos.theta1;  
          joint_group_positions[2] = j_pos.theta2;  
          joint_group_positions[3] = j_pos.theta3;  
          ROS_INFO("Using x: %f, IK Theta1: %f, Theta2: %f, Theta3: %f", x, j_pos.theta1, j_pos.theta2, j_pos.theta3);
          move_group_interface.setJointValueTarget(joint_group_positions);

          move_group_interface.setStartStateToCurrentState();
          move_group_interface.setMaxVelocityScalingFactor(0.05);
          move_group_interface.setMaxAccelerationScalingFactor(0.05);
          tripp_state = PLANNING;

          
            
          break;
        }
        
        case PLANNING:
        {
          ROS_INFO("State: PLANNING - Computing motion plan...");
          bool success = (move_group_interface.plan(my_plan) == moveit::core::MoveItErrorCode::SUCCESS);
          if (success) {
            ROS_INFO("Planning succeeded.");
            // visualize the plan in RViz
            visual_tools.deleteAllMarkers();
            visual_tools.publishText(text_pose, "Joint Space Goal", rvt::WHITE, rvt::XLARGE);
            visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
            visual_tools.trigger();
            ROS_INFO("Execute this plan? (y/n) ");
            std::string answer;
            std::getline(std::cin, answer);
            if (answer == "y" || answer == "Y") {
                tripp_state = EXECUTING;
            } else {
            ROS_WARN("Plan discarded. Returning to IDLE.");
                tripp_state = IDLE;
            }  // Proceed to execution if planning is successful
            } else {
            ROS_ERROR("Planning failed!");
            tripp_state = ERROR_STATE;  // Handle error as needed
             }
            break;


        }
        case EXECUTING:
        {
        moveit::core::MoveItErrorCode exec_result = move_group_interface.move();
        if (exec_result == moveit::planning_interface::MoveItErrorCode::SUCCESS){
            ROS_INFO("Execution succeeded.");
            tripp_state = IDLE;
        }else{
            ROS_ERROR("Execution failed!");
            tripp_state = ERROR_STATE;  // Handle error as needed
        
        }
         // the actuall execution is async so need something to delay until the motion is finished
         break; // Reset to IDLE after execution
        }

        case REVIEW:
        {
          ROS_INFO("State: FINISHED - Exiting the program.");
          tripp_state = FINISHED;
          break;
        }
        
        case ERROR_STATE:
        {
          ROS_ERROR("State: ERROR_STATE - An error occurred. Exiting.");
          tripp_state = IDLE;
          break;
        }
  }

}
        




}