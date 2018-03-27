#include "ros/ros.h"
#include "unreal_msgs/DeleteModel.h"
#include <cstdlib>


int main(int argc, char **argv)
{
	ros::init(argc, argv, "delete_model_client");


	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<unreal_msgs::DeleteModel>("unreal/delete_model");

	unreal_msgs::DeleteModel srv;
	srv.request.instance_id.class_name = "Sphere";
	srv.request.instance_id.id = "1234";

	if(client.call(srv))
	{
		if(srv.response.success){
			ROS_INFO("Model was deleted!");
		} else {
			ROS_ERROR("Deleting model did not Work!");
		}
	} else {
		ROS_ERROR("Failed to call delete_model service");
		return 1;
	}

	return 0;
}
