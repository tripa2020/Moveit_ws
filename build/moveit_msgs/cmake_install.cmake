# Install script for directory: /home/alex/moveit_ws/src/moveit_msgs

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/alex/moveit_ws/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs/action" TYPE FILE FILES
    "/home/alex/moveit_ws/src/moveit_msgs/action/ExecuteTrajectory.action"
    "/home/alex/moveit_ws/src/moveit_msgs/action/MoveGroup.action"
    "/home/alex/moveit_ws/src/moveit_msgs/action/MoveGroupSequence.action"
    "/home/alex/moveit_ws/src/moveit_msgs/action/Pickup.action"
    "/home/alex/moveit_ws/src/moveit_msgs/action/Place.action"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs/msg" TYPE FILE FILES
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/ExecuteTrajectoryAction.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/ExecuteTrajectoryActionGoal.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/ExecuteTrajectoryActionResult.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/ExecuteTrajectoryActionFeedback.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/ExecuteTrajectoryGoal.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/ExecuteTrajectoryResult.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/ExecuteTrajectoryFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs/msg" TYPE FILE FILES
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupAction.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupActionGoal.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupActionResult.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupActionFeedback.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupGoal.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupResult.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs/msg" TYPE FILE FILES
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupSequenceAction.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupSequenceActionGoal.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupSequenceActionResult.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupSequenceActionFeedback.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupSequenceGoal.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupSequenceResult.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/MoveGroupSequenceFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs/msg" TYPE FILE FILES
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PickupAction.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PickupActionGoal.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PickupActionResult.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PickupActionFeedback.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PickupGoal.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PickupResult.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PickupFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs/msg" TYPE FILE FILES
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PlaceAction.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PlaceActionGoal.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PlaceActionResult.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PlaceActionFeedback.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PlaceGoal.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PlaceResult.msg"
    "/home/alex/moveit_ws/devel/share/moveit_msgs/msg/PlaceFeedback.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs/msg" TYPE FILE FILES
    "/home/alex/moveit_ws/src/moveit_msgs/msg/AllowedCollisionEntry.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/AllowedCollisionMatrix.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/AttachedCollisionObject.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/BoundingVolume.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/CartesianPoint.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/CartesianTrajectory.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/CartesianTrajectoryPoint.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/CollisionObject.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/ConstraintEvalResult.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/Constraints.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/CostSource.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/ContactInformation.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/DisplayTrajectory.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/DisplayRobotState.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/GenericTrajectory.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/Grasp.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/GripperTranslation.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/JointConstraint.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/JointLimits.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/LinkPadding.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/LinkScale.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/MotionPlanRequest.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/MotionPlanResponse.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/MotionPlanDetailedResponse.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/MotionSequenceItem.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/MotionSequenceRequest.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/MotionSequenceResponse.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/MoveItErrorCodes.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/TrajectoryConstraints.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/ObjectColor.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/OrientationConstraint.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/OrientedBoundingBox.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/PlaceLocation.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/PlannerInterfaceDescription.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/PlannerParams.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/PlanningScene.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/PlanningSceneComponents.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/PlanningSceneWorld.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/PlanningOptions.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/PositionConstraint.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/RobotState.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/RobotTrajectory.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/VisibilityConstraint.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/WorkspaceParameters.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/KinematicSolverInfo.msg"
    "/home/alex/moveit_ws/src/moveit_msgs/msg/PositionIKRequest.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs/srv" TYPE FILE FILES
    "/home/alex/moveit_ws/src/moveit_msgs/srv/GetMotionPlan.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/ExecuteKnownTrajectory.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/GetStateValidity.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/GetCartesianPath.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/GetPlanningScene.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/GraspPlanning.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/ApplyPlanningScene.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/QueryPlannerInterfaces.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/GetMotionSequence.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/GetPositionFK.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/GetPositionIK.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/GetPlannerParams.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/SetPlannerParams.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/UpdatePointcloudOctomap.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/SaveMap.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/LoadMap.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/SaveRobotStateToWarehouse.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/ListRobotStatesInWarehouse.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/GetRobotStateFromWarehouse.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/CheckIfRobotStateExistsInWarehouse.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/RenameRobotStateInWarehouse.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/DeleteRobotStateFromWarehouse.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/ChangeControlDimensions.srv"
    "/home/alex/moveit_ws/src/moveit_msgs/srv/ChangeDriftDimensions.srv"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs/cmake" TYPE FILE FILES "/home/alex/moveit_ws/build/moveit_msgs/catkin_generated/installspace/moveit_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/alex/moveit_ws/devel/include/moveit_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/alex/moveit_ws/devel/share/roseus/ros/moveit_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/alex/moveit_ws/devel/share/common-lisp/ros/moveit_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/alex/moveit_ws/devel/share/gennodejs/ros/moveit_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/alex/moveit_ws/devel/lib/python3/dist-packages/moveit_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/alex/moveit_ws/devel/lib/python3/dist-packages/moveit_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/alex/moveit_ws/build/moveit_msgs/catkin_generated/installspace/moveit_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs/cmake" TYPE FILE FILES "/home/alex/moveit_ws/build/moveit_msgs/catkin_generated/installspace/moveit_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs/cmake" TYPE FILE FILES
    "/home/alex/moveit_ws/build/moveit_msgs/catkin_generated/installspace/moveit_msgsConfig.cmake"
    "/home/alex/moveit_ws/build/moveit_msgs/catkin_generated/installspace/moveit_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/moveit_msgs" TYPE FILE FILES "/home/alex/moveit_ws/src/moveit_msgs/package.xml")
endif()

