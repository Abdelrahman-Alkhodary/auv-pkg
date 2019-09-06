#include "ros/ros.h"
#include "std_msgs/String.h"
#include "auv_msgs/NavigationStatus.h"


int main(int argc, char **argv)
{
	ros::init(argc, argv, "GPS_node");
	ros::NodeHandle n;

	ros::Publisher position_pub = n.advertise<geographic_msgs::GeoPoint>("/origin_position", 10);
	
	geographic_msgs::GeoPoint origin;
	origin.latitude = 0.0;
	origin.longitude = 0.0;
	origin.altitude = 0.0;

	ROS_INFO("Origin point of robot");
	ros::Rate loop_rate(1); //1 message per second

	while(ros::ok())
	{		
		position_pub.publish(origin);
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
		
