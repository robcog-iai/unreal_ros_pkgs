cmake_minimum_required(VERSION 2.8.3)
project(unreal_msgs)

find_package(
	catkin REQUIRED COMPONENTS
	roscpp
	std_msgs
  geometry_msgs
	message_generation
)


## Generate messages in the 'msg' folder
add_message_files(
   FILES
   Tag.msg
	 StaticMeshDescription.msg
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  SpawnModel.srv
	SetModelPose.srv
	DeleteModel.srv
	SpawnSemanticMap.srv
)

generate_messages(
  DEPENDENCIES
  std_msgs
  geometry_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(
 include
 ${catkin_INCLUDE_DIRS}
)

add_executable(spawner_client src/example_test_clients/spawner_client.cpp)
target_link_libraries(spawner_client ${catkin_LIBRARIES})
add_dependencies( spawner_client ${PROJECT_NAME}_generate_messages_cpp )

add_executable(spawn_semantic_map_client src/example_test_clients/spawn_semantic_map_client.cpp)
target_link_libraries(spawn_semantic_map_client ${catkin_LIBRARIES})
add_dependencies( spawn_semantic_map_client ${PROJECT_NAME}_generate_messages_cpp )


add_executable(relocation_client src/example_test_clients/relocation_client.cpp)
target_link_libraries(relocation_client ${catkin_LIBRARIES})
add_dependencies( relocation_client ${PROJECT_NAME}_generate_messages_cpp )

add_executable(delete_model_client src/example_test_clients/delete_model_client.cpp)
target_link_libraries(delete_model_client ${catkin_LIBRARIES})
add_dependencies( delete_model_client ${PROJECT_NAME}_generate_messages_cpp )
