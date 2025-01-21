// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from package_master_interfaces:srv/RobotPositions.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "package_master_interfaces/srv/detail/robot_positions__rosidl_typesupport_introspection_c.h"
#include "package_master_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "package_master_interfaces/srv/detail/robot_positions__functions.h"
#include "package_master_interfaces/srv/detail/robot_positions__struct.h"


// Include directives for member types
// Member `robot_names`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  package_master_interfaces__srv__RobotPositions_Request__init(message_memory);
}

void package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_fini_function(void * message_memory)
{
  package_master_interfaces__srv__RobotPositions_Request__fini(message_memory);
}

size_t package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__size_function__RobotPositions_Request__robot_names(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Request__robot_names(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__get_function__RobotPositions_Request__robot_names(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__fetch_function__RobotPositions_Request__robot_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Request__robot_names(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__assign_function__RobotPositions_Request__robot_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__get_function__RobotPositions_Request__robot_names(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__resize_function__RobotPositions_Request__robot_names(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_message_member_array[1] = {
  {
    "robot_names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces__srv__RobotPositions_Request, robot_names),  // bytes offset in struct
    NULL,  // default value
    package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__size_function__RobotPositions_Request__robot_names,  // size() function pointer
    package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Request__robot_names,  // get_const(index) function pointer
    package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__get_function__RobotPositions_Request__robot_names,  // get(index) function pointer
    package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__fetch_function__RobotPositions_Request__robot_names,  // fetch(index, &value) function pointer
    package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__assign_function__RobotPositions_Request__robot_names,  // assign(index, value) function pointer
    package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__resize_function__RobotPositions_Request__robot_names  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_message_members = {
  "package_master_interfaces__srv",  // message namespace
  "RobotPositions_Request",  // message name
  1,  // number of fields
  sizeof(package_master_interfaces__srv__RobotPositions_Request),
  package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_message_member_array,  // message members
  package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_message_type_support_handle = {
  0,
  &package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_package_master_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, package_master_interfaces, srv, RobotPositions_Request)() {
  if (!package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_message_type_support_handle.typesupport_identifier) {
    package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &package_master_interfaces__srv__RobotPositions_Request__rosidl_typesupport_introspection_c__RobotPositions_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "package_master_interfaces/srv/detail/robot_positions__rosidl_typesupport_introspection_c.h"
// already included above
// #include "package_master_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "package_master_interfaces/srv/detail/robot_positions__functions.h"
// already included above
// #include "package_master_interfaces/srv/detail/robot_positions__struct.h"


// Include directives for member types
// Member `robot_names`
// already included above
// #include "rosidl_runtime_c/string_functions.h"
// Member `positions_x`
// Member `positions_y`
// Member `positions_z`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  package_master_interfaces__srv__RobotPositions_Response__init(message_memory);
}

void package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_fini_function(void * message_memory)
{
  package_master_interfaces__srv__RobotPositions_Response__fini(message_memory);
}

size_t package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__size_function__RobotPositions_Response__robot_names(
  const void * untyped_member)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return member->size;
}

const void * package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__robot_names(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__String__Sequence * member =
    (const rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void * package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__robot_names(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  return &member->data[index];
}

void package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__fetch_function__RobotPositions_Response__robot_names(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const rosidl_runtime_c__String * item =
    ((const rosidl_runtime_c__String *)
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__robot_names(untyped_member, index));
  rosidl_runtime_c__String * value =
    (rosidl_runtime_c__String *)(untyped_value);
  *value = *item;
}

void package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__assign_function__RobotPositions_Response__robot_names(
  void * untyped_member, size_t index, const void * untyped_value)
{
  rosidl_runtime_c__String * item =
    ((rosidl_runtime_c__String *)
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__robot_names(untyped_member, index));
  const rosidl_runtime_c__String * value =
    (const rosidl_runtime_c__String *)(untyped_value);
  *item = *value;
}

bool package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__resize_function__RobotPositions_Response__robot_names(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__String__Sequence * member =
    (rosidl_runtime_c__String__Sequence *)(untyped_member);
  rosidl_runtime_c__String__Sequence__fini(member);
  return rosidl_runtime_c__String__Sequence__init(member, size);
}

size_t package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__size_function__RobotPositions_Response__positions_x(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__positions_x(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__positions_x(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__fetch_function__RobotPositions_Response__positions_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__positions_x(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__assign_function__RobotPositions_Response__positions_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__positions_x(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__resize_function__RobotPositions_Response__positions_x(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__size_function__RobotPositions_Response__positions_y(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__positions_y(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__positions_y(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__fetch_function__RobotPositions_Response__positions_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__positions_y(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__assign_function__RobotPositions_Response__positions_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__positions_y(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__resize_function__RobotPositions_Response__positions_y(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

size_t package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__size_function__RobotPositions_Response__positions_z(
  const void * untyped_member)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return member->size;
}

const void * package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__positions_z(
  const void * untyped_member, size_t index)
{
  const rosidl_runtime_c__double__Sequence * member =
    (const rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void * package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__positions_z(
  void * untyped_member, size_t index)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  return &member->data[index];
}

void package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__fetch_function__RobotPositions_Response__positions_z(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const double * item =
    ((const double *)
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__positions_z(untyped_member, index));
  double * value =
    (double *)(untyped_value);
  *value = *item;
}

void package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__assign_function__RobotPositions_Response__positions_z(
  void * untyped_member, size_t index, const void * untyped_value)
{
  double * item =
    ((double *)
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__positions_z(untyped_member, index));
  const double * value =
    (const double *)(untyped_value);
  *item = *value;
}

bool package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__resize_function__RobotPositions_Response__positions_z(
  void * untyped_member, size_t size)
{
  rosidl_runtime_c__double__Sequence * member =
    (rosidl_runtime_c__double__Sequence *)(untyped_member);
  rosidl_runtime_c__double__Sequence__fini(member);
  return rosidl_runtime_c__double__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_message_member_array[4] = {
  {
    "robot_names",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces__srv__RobotPositions_Response, robot_names),  // bytes offset in struct
    NULL,  // default value
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__size_function__RobotPositions_Response__robot_names,  // size() function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__robot_names,  // get_const(index) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__robot_names,  // get(index) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__fetch_function__RobotPositions_Response__robot_names,  // fetch(index, &value) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__assign_function__RobotPositions_Response__robot_names,  // assign(index, value) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__resize_function__RobotPositions_Response__robot_names  // resize(index) function pointer
  },
  {
    "positions_x",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces__srv__RobotPositions_Response, positions_x),  // bytes offset in struct
    NULL,  // default value
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__size_function__RobotPositions_Response__positions_x,  // size() function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__positions_x,  // get_const(index) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__positions_x,  // get(index) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__fetch_function__RobotPositions_Response__positions_x,  // fetch(index, &value) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__assign_function__RobotPositions_Response__positions_x,  // assign(index, value) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__resize_function__RobotPositions_Response__positions_x  // resize(index) function pointer
  },
  {
    "positions_y",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces__srv__RobotPositions_Response, positions_y),  // bytes offset in struct
    NULL,  // default value
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__size_function__RobotPositions_Response__positions_y,  // size() function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__positions_y,  // get_const(index) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__positions_y,  // get(index) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__fetch_function__RobotPositions_Response__positions_y,  // fetch(index, &value) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__assign_function__RobotPositions_Response__positions_y,  // assign(index, value) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__resize_function__RobotPositions_Response__positions_y  // resize(index) function pointer
  },
  {
    "positions_z",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces__srv__RobotPositions_Response, positions_z),  // bytes offset in struct
    NULL,  // default value
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__size_function__RobotPositions_Response__positions_z,  // size() function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_const_function__RobotPositions_Response__positions_z,  // get_const(index) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__get_function__RobotPositions_Response__positions_z,  // get(index) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__fetch_function__RobotPositions_Response__positions_z,  // fetch(index, &value) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__assign_function__RobotPositions_Response__positions_z,  // assign(index, value) function pointer
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__resize_function__RobotPositions_Response__positions_z  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_message_members = {
  "package_master_interfaces__srv",  // message namespace
  "RobotPositions_Response",  // message name
  4,  // number of fields
  sizeof(package_master_interfaces__srv__RobotPositions_Response),
  package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_message_member_array,  // message members
  package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_message_type_support_handle = {
  0,
  &package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_package_master_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, package_master_interfaces, srv, RobotPositions_Response)() {
  if (!package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_message_type_support_handle.typesupport_identifier) {
    package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &package_master_interfaces__srv__RobotPositions_Response__rosidl_typesupport_introspection_c__RobotPositions_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "package_master_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "package_master_interfaces/srv/detail/robot_positions__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers package_master_interfaces__srv__detail__robot_positions__rosidl_typesupport_introspection_c__RobotPositions_service_members = {
  "package_master_interfaces__srv",  // service namespace
  "RobotPositions",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // package_master_interfaces__srv__detail__robot_positions__rosidl_typesupport_introspection_c__RobotPositions_Request_message_type_support_handle,
  NULL  // response message
  // package_master_interfaces__srv__detail__robot_positions__rosidl_typesupport_introspection_c__RobotPositions_Response_message_type_support_handle
};

static rosidl_service_type_support_t package_master_interfaces__srv__detail__robot_positions__rosidl_typesupport_introspection_c__RobotPositions_service_type_support_handle = {
  0,
  &package_master_interfaces__srv__detail__robot_positions__rosidl_typesupport_introspection_c__RobotPositions_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, package_master_interfaces, srv, RobotPositions_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, package_master_interfaces, srv, RobotPositions_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_package_master_interfaces
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, package_master_interfaces, srv, RobotPositions)() {
  if (!package_master_interfaces__srv__detail__robot_positions__rosidl_typesupport_introspection_c__RobotPositions_service_type_support_handle.typesupport_identifier) {
    package_master_interfaces__srv__detail__robot_positions__rosidl_typesupport_introspection_c__RobotPositions_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)package_master_interfaces__srv__detail__robot_positions__rosidl_typesupport_introspection_c__RobotPositions_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, package_master_interfaces, srv, RobotPositions_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, package_master_interfaces, srv, RobotPositions_Response)()->data;
  }

  return &package_master_interfaces__srv__detail__robot_positions__rosidl_typesupport_introspection_c__RobotPositions_service_type_support_handle;
}
