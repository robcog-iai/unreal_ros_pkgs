#include "ros/ros.h"
#include "unreal_msgs/SpawnModel.h"
#include "unreal_msgs/Tag.h"
#include "geometry_msgs/Pose.h"
#include <cstdlib>


int main(int argc, char **argv)
{
	ros::init(argc, argv, "spawner_client");


	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<unreal_msgs::SpawnModel>("unreal/spawn_model");

	unreal_msgs::SpawnModel srv;
	srv.request.static_mesh_description.path_to_mesh = "StaticMesh'/Engine/BasicShapes/Sphere.Sphere'";
	srv.request.static_mesh_description.path_to_material = "Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'";

	geometry_msgs::Pose pose;
	pose.position.x = 150;
	pose.position.y = 0;
	pose.position.z = 150;

	pose.orientation.x = 0;
	pose.orientation.y = 0;
	pose.orientation.z = 0;
	pose.orientation.w = 1;


	std::vector<unreal_msgs::Tag> tags;

	unreal_msgs::Tag id;
	id.tag_type = "SemLog";
	id.key = "id";
	id.value = "1234";
	tags.push_back(id);

	unreal_msgs::Tag tag;
	tag.tag_type = "SemLog";
	tag.key = "something";
	tag.value = "something";
	tags.push_back(tag);

	unreal_msgs::Tag tag2;
	tag2.tag_type = "OtherType";
	tag2.key = "something";
	tag2.value = "something";
	tags.push_back(tag2);

	srv.request.static_mesh_description.pose = pose;
	srv.request.static_mesh_description.tags = tags;

	if(client.call(srv))
	{
		if(srv.response.success){
			ROS_INFO("Spawning the Mesh did work!");
		} else {
			ROS_ERROR("Spawning the Mesh did not Work!");
		}
	} else {
		ROS_ERROR("Failed to call service spawner_service");
		return 1;
	}

	return 0;
}
