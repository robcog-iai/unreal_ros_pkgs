#include "ros/ros.h"
#include "unreal_msgs/SpawnSemanticMap.h"
#include "unreal_msgs/Tag.h"
#include "geometry_msgs/Pose.h"
#include <cstdlib>


int main(int argc, char **argv)
{
	ros::init(argc, argv, "spawn_semantic_map_client");


	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<unreal_msgs::SpawnSemanticMap>("unreal/spawn_semantic_map");


    // creating first object
    unreal_msgs::StaticMeshDescription object1;

	object1.path_to_mesh = "StaticMesh'/Engine/BasicShapes/Sphere.Sphere'";
    object1.path_to_material = "Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'";

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

	object1.pose = pose;
	object1.tags = tags;

    // creating second object
    unreal_msgs::StaticMeshDescription object2;

	object2.path_to_mesh = "StaticMesh'/Engine/BasicShapes/Sphere.Sphere'";
    object2.path_to_material = "Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'";

	geometry_msgs::Pose pose2;
	pose2.position.x = 300;
	pose2.position.y = 100;
	pose2.position.z = 400;

	pose2.orientation.x = 0;
	pose2.orientation.y = 0;
	pose2.orientation.z = 0;
	pose2.orientation.w = 1;


	std::vector<unreal_msgs::Tag> tags2;

	unreal_msgs::Tag id_2;
	id_2.tag_type = "SemLog";
	id_2.key = "id";
	id_2.value = "2345";
	tags2.push_back(id_2);

	unreal_msgs::Tag tag_2;
	tag_2.tag_type = "SemLog";
	tag_2.key = "something";
	tag_2.value = "something";
	tags2.push_back(tag_2);

	unreal_msgs::Tag tag2_2;
	tag2_2.tag_type = "OtherType";
	tag2_2.key = "something";
	tag2_2.value = "something";
	tags2.push_back(tag2_2);

	object2.pose = pose2;
	object2.tags = tags2;


    // puting objects into array and service message

    std::vector<unreal_msgs::StaticMeshDescription> semantic_map;
    semantic_map.push_back(object1);
    semantic_map.push_back(object2);

    unreal_msgs::SpawnSemanticMap srv;
    srv.request.static_mesh_descriptions = semantic_map;

    //calling service and evaluating response
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
