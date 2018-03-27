#include "ros/ros.h"
#include "unreal_msgs/SpawnMultipleModels.h"
#include "unreal_msgs/Tag.h"
#include "geometry_msgs/Pose.h"
#include <cstdlib>


int main(int argc, char **argv)
{
	ros::init(argc, argv, "spawn_semantic_map_client");


	ros::NodeHandle n;
	ros::ServiceClient client = n.serviceClient<unreal_msgs::SpawnMultipleModels>("unreal/spawn_multiple_models");


    // creating mesh descripton
    unreal_msgs::MeshDescription mesh_description;
	mesh_description.path_to_mesh = "StaticMesh'/Engine/BasicShapes/Sphere.Sphere'";
    mesh_description.path_to_material = "Material'/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial'";

	//creating model_description, for first modoel
	unreal_msgs::ModelDescription model_description;

	geometry_msgs::Pose pose;
	pose.position.x = 150;
	pose.position.y = 0;
	pose.position.z = 150;

	pose.orientation.x = 0;
	pose.orientation.y = 0;
	pose.orientation.z = 0;
	pose.orientation.w = 1;

	model_description.pose = pose;
	model_description.instance_id.class_name = "Sphere";
	model_description.mesh_description = mesh_description;


    // creating model_description, for second model
	unreal_msgs::ModelDescription model_description2;

	geometry_msgs::Pose pose2;
	pose2.position.x = 300;
	pose2.position.y = 100;
	pose2.position.z = 400;

	pose2.orientation.x = 0;
	pose2.orientation.y = 0;
	pose2.orientation.z = 0;
	pose2.orientation.w = 1;

	model_description2.pose = pose2;
	model_description2.instance_id.class_name = "Sphere";
	model_description2.mesh_description = mesh_description;

    // puting objects into array and service message

    std::vector<unreal_msgs::ModelDescription> model_descriptions;
    model_descriptions.push_back(model_description);
    model_descriptions.push_back(model_description2);

    unreal_msgs::SpawnMultipleModels srv;
    srv.request.model_descriptions = model_descriptions;

    //calling service and evaluating response
	if(client.call(srv))
	{
		if(srv.response.success[0]){
			ROS_INFO("Spawning the first Mesh did work!");
			ROS_INFO("Generated mesh id is: %s", srv.response.instance_ids[0].id);

		} else {
			ROS_ERROR("Spawning the first Mesh did not Work!");
		}
		if(srv.response.success[1]){
			ROS_INFO("Spawning the second Mesh did work!");
			ROS_INFO("Generated mesh id is: %s", srv.response.instance_ids[1].id);
		} else {
			ROS_ERROR("Spawning the second Mesh did not Work!");
		}
	} else {
		ROS_ERROR("Failed to call service spawner_service");
		return 1;
	}

	return 0;
}
