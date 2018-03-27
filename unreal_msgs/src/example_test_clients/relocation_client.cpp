#include "ros/ros.h"
#include "unreal_msgs/SetModelPose.h"
#include "geometry_msgs/Pose.h"
#include <cstdlib>


int main(int argc, char **argv)
{
	ros::init(argc, argv, "relocation_client");


	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<unreal_msgs::SetModelPose>("unreal/set_model_pose");

	unreal_msgs::SetModelPose srv;
	srv.request.instance_id.class_name = "Sphere";
	srv.request.instance_id.id = "1234";

	geometry_msgs::Pose pose;
	pose.position.x = 300;
	pose.position.y = 0;
	pose.position.z = 300;

	pose.orientation.x = 0;
	pose.orientation.y = 0;
	pose.orientation.z = 0;
	pose.orientation.w = 1;

	srv.request.pose = pose;

	if(client.call(srv))
	{
		if(srv.response.success){
			ROS_INFO("Relocating the Mesh did work!");
		} else {
			ROS_ERROR("Relocating the Mesh did not Work!");
		}
	} else {
		ROS_ERROR("Failed to call relocation_service");
		return 1;
	}

	return 0;
}
