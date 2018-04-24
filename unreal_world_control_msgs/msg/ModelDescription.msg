# This message contains everything needed
# to describe a model for the unreal world.

# The instance_id is used to identify the described model
unreal_world_control_msgs/InstanceId instance_id

# The mesh_description is optional.
# If the mesh_description is not set the class_name and
# namespace of the instance_id will be used to determin
# where the assets are expected to be.
# It is also possible to set just one of the two
# to a specific asset.
# The expected paths are
#   StaticMesh: Models/namespace/class_name/SM_Class.uasset
#   Material: Models/namespace/class_name/M_Class.uasset
unreal_world_control_msgs/MeshDescription mesh_description

# Pose the model is supposed to have
geometry_msgs/Pose pose

# UTags that the should be set to Model
unreal_world_control_msgs/Tag[] tags

# true if the model is static (physics are not enabled)
bool is_static # default is true
