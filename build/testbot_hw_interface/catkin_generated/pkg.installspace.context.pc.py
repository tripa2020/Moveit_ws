# generated from catkin/cmake/template/pkg.context.pc.in
CATKIN_PACKAGE_PREFIX = ""
PROJECT_PKG_CONFIG_INCLUDE_DIRS = "${prefix}/include".split(';') if "${prefix}/include" != "" else []
PROJECT_CATKIN_DEPENDS = "controller_manager;hardware_interface;roscpp;rospy;sensor_msgs;std_msgs".replace(';', ' ')
PKG_CONFIG_LIBRARIES_WITH_PREFIX = "-ltestbot_hw_interface".split(';') if "-ltestbot_hw_interface" != "" else []
PROJECT_NAME = "testbot_hw_interface"
PROJECT_SPACE_DIR = "/home/alex/moveit_ws/install"
PROJECT_VERSION = "0.0.0"
