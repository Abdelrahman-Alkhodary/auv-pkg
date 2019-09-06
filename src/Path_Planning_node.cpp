#include "ros/ros.h"
#include "std_msgs/String.h"
#include "auv_msgs/NavigationStatus.h"
#include "auv_msgs/BodyVelocityRequest.h"

void origin_position_callback(const geographic_msgs::GeoPoint& origin){
    ROS_INFO("Received [%f]", origin.latitude);
}

void orientation_callback(const geometry_msgs::Vector3& orientation){
    ROS_INFO("Received [%f]", orientation.x);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "Path_Planning_node");
	ros::NodeHandle n;

    ros::Subscriber origin_pos_sub = n.subscribe("/origin_position",10, origin_position_callback);
    ros::Subscriber orientation_sub = n.subscribe("/orientation",10, orientation_callback);
    ros::Publisher velocity_pub = n.advertise<geometry_msgs::Twist>("/velocity", 10);
    geometry_msgs::Twist velocity;
    velocity.linear.x = 0;
    velocity.linear.y = 0;
    velocity.linear.z = 0;

    velocity.angular.x = 0;
    velocity.angular.y = 0;
    velocity.angular.z = 0;

    ros::Rate loop_rate(1); //1 message per second
    while(ros::ok())
	{		
		velocity_pub.publish(velocity);
		ros::spinOnce();
		loop_rate.sleep();
	}
	
	return 0;
}
	