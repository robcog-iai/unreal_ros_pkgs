# All fields directly represent values of the PhysicsConstrained.
# And can be looked up here: https://docs.unrealengine.com/en-US/Engine/Physics/Constraints/ConstraintsReference
# Models affected by the constrained
unreal_world_control_msgs/InstanceId first_model
unreal_world_control_msgs/InstanceId second_model
# Constrained Behavior
bool disabel_collision
bool enable_projection
float32 projection_linear_tolerance
float32 projection_angular_tolerance
bool parent_dominates
unreal_world_control_msgs/LinearLimits linear_limits
unreal_world_control_msgs/AngularLimits angular_limits
