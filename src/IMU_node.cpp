#include "ros/ros.h"
#include "std_msgs/String.h"
#include "auv_msgs/NavigationStatus.h"


int main(int argc, char **argv)
{
	ros::init(argc, argv, "IMU_node");
	ros::NodeHandle n;

	ros::Publisher orientation_pub = n.advertise<geometry_msgs::Vector3>("/orientation", 10);
	
	geometry_msgs::Vector3 orientation;
	orientation.x = 0.0;
	orientation.y = 0.0;
	orientation.z = 0.0;

	ROS_INFO("orientation of robot");
	ros::Rate loop_rate(10); //1 message per second

	while(ros::ok())
	{		
		orientation_pub.publish(orientation);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
		
