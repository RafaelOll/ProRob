// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from package_master_interfaces:srv/DroneTrajectories.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__STRUCT_H_
#define PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_name'
#include "rosidl_runtime_c/string.h"
// Member 'ri_x'
// Member 'ri_y'
// Member 'rf_x'
// Member 'rf_y'
// Member 'time'
// Member 'epsilon'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/DroneTrajectories in the package package_master_interfaces.
typedef struct package_master_interfaces__srv__DroneTrajectories_Request
{
  rosidl_runtime_c__String__Sequence robot_name;
  rosidl_runtime_c__double__Sequence ri_x;
  rosidl_runtime_c__double__Sequence ri_y;
  rosidl_runtime_c__double__Sequence rf_x;
  rosidl_runtime_c__double__Sequence rf_y;
  rosidl_runtime_c__double__Sequence time;
  rosidl_runtime_c__double__Sequence epsilon;
} package_master_interfaces__srv__DroneTrajectories_Request;

// Struct for a sequence of package_master_interfaces__srv__DroneTrajectories_Request.
typedef struct package_master_interfaces__srv__DroneTrajectories_Request__Sequence
{
  package_master_interfaces__srv__DroneTrajectories_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} package_master_interfaces__srv__DroneTrajectories_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'sequences'
#include "package_master_interfaces/msg/detail/sequence_elements__struct.h"

/// Struct defined in srv/DroneTrajectories in the package package_master_interfaces.
typedef struct package_master_interfaces__srv__DroneTrajectories_Response
{
  package_master_interfaces__msg__SequenceElements__Sequence sequences;
} package_master_interfaces__srv__DroneTrajectories_Response;

// Struct for a sequence of package_master_interfaces__srv__DroneTrajectories_Response.
typedef struct package_master_interfaces__srv__DroneTrajectories_Response__Sequence
{
  package_master_interfaces__srv__DroneTrajectories_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} package_master_interfaces__srv__DroneTrajectories_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__STRUCT_H_
