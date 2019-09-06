#include "ros/ros.h"
#include "auv_msgs/BodyVelocityRequest.h"

void velocity_callback(const geometry_msgs::Twist& velocity){
    ROS_INFO("Received [%f]", velocity.linear.x);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Thrusters_node");
	ros::NodeHandle n;

    ros::Subscriber velocity_sub = n.subscribe("/velocity",10, velocity_callback);

    ros::spin();

    	
	return 0;
}
	