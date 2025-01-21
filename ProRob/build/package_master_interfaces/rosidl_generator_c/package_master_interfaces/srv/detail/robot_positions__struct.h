// NOLINT: This file starts with a BOM since it contain non-ASCII characters
// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from package_master_interfaces:srv/RobotPositions.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__SRV__DETAIL__ROBOT_POSITIONS__STRUCT_H_
#define PACKAGE_MASTER_INTERFACES__SRV__DETAIL__ROBOT_POSITIONS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'robot_names'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/RobotPositions in the package package_master_interfaces.
typedef struct package_master_interfaces__srv__RobotPositions_Request
{
  /// Liste des noms de robots
  rosidl_runtime_c__String__Sequence robot_names;
} package_master_interfaces__srv__RobotPositions_Request;

// Struct for a sequence of package_master_interfaces__srv__RobotPositions_Request.
typedef struct package_master_interfaces__srv__RobotPositions_Request__Sequence
{
  package_master_interfaces__srv__RobotPositions_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} package_master_interfaces__srv__RobotPositions_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'robot_names'
// already included above
// #include "rosidl_runtime_c/string.h"
// Member 'positions_x'
// Member 'positions_y'
// Member 'positions_z'
#include "rosidl_runtime_c/primitives_sequence.h"

/// Struct defined in srv/RobotPositions in the package package_master_interfaces.
typedef struct package_master_interfaces__srv__RobotPositions_Response
{
  /// Noms des robots (réponse)
  rosidl_runtime_c__String__Sequence robot_names;
  /// Coordonnées X
  rosidl_runtime_c__double__Sequence positions_x;
  /// Coordonnées Y
  rosidl_runtime_c__double__Sequence positions_y;
  /// Coordonnées Z
  rosidl_runtime_c__double__Sequence positions_z;
} package_master_interfaces__srv__RobotPositions_Response;

// Struct for a sequence of package_master_interfaces__srv__RobotPositions_Response.
typedef struct package_master_interfaces__srv__RobotPositions_Response__Sequence
{
  package_master_interfaces__srv__RobotPositions_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} package_master_interfaces__srv__RobotPositions_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PACKAGE_MASTER_INTERFACES__SRV__DETAIL__ROBOT_POSITIONS__STRUCT_H_
