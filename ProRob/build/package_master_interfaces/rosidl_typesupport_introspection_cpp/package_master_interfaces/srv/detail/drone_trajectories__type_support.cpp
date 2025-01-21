// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from package_master_interfaces:srv/DroneTrajectories.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "package_master_interfaces/srv/detail/drone_trajectories__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace package_master_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void DroneTrajectories_Request_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) package_master_interfaces::srv::DroneTrajectories_Request(_init);
}

void DroneTrajectories_Request_fini_function(void * message_memory)
{
  auto typed_message = static_cast<package_master_interfaces::srv::DroneTrajectories_Request *>(message_memory);
  typed_message->~DroneTrajectories_Request();
}

size_t size_function__DroneTrajectories_Request__robot_name(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DroneTrajectories_Request__robot_name(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void * get_function__DroneTrajectories_Request__robot_name(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<std::string> *>(untyped_member);
  return &member[index];
}

void fetch_function__DroneTrajectories_Request__robot_name(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const std::string *>(
    get_const_function__DroneTrajectories_Request__robot_name(untyped_member, index));
  auto & value = *reinterpret_cast<std::string *>(untyped_value);
  value = item;
}

void assign_function__DroneTrajectories_Request__robot_name(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<std::string *>(
    get_function__DroneTrajectories_Request__robot_name(untyped_member, index));
  const auto & value = *reinterpret_cast<const std::string *>(untyped_value);
  item = value;
}

void resize_function__DroneTrajectories_Request__robot_name(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<std::string> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DroneTrajectories_Request__ri_x(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DroneTrajectories_Request__ri_x(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__DroneTrajectories_Request__ri_x(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__DroneTrajectories_Request__ri_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__DroneTrajectories_Request__ri_x(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__DroneTrajectories_Request__ri_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__DroneTrajectories_Request__ri_x(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__DroneTrajectories_Request__ri_x(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DroneTrajectories_Request__ri_y(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DroneTrajectories_Request__ri_y(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__DroneTrajectories_Request__ri_y(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__DroneTrajectories_Request__ri_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__DroneTrajectories_Request__ri_y(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__DroneTrajectories_Request__ri_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__DroneTrajectories_Request__ri_y(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__DroneTrajectories_Request__ri_y(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DroneTrajectories_Request__rf_x(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DroneTrajectories_Request__rf_x(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__DroneTrajectories_Request__rf_x(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__DroneTrajectories_Request__rf_x(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__DroneTrajectories_Request__rf_x(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__DroneTrajectories_Request__rf_x(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__DroneTrajectories_Request__rf_x(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__DroneTrajectories_Request__rf_x(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DroneTrajectories_Request__rf_y(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DroneTrajectories_Request__rf_y(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__DroneTrajectories_Request__rf_y(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__DroneTrajectories_Request__rf_y(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__DroneTrajectories_Request__rf_y(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__DroneTrajectories_Request__rf_y(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__DroneTrajectories_Request__rf_y(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__DroneTrajectories_Request__rf_y(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DroneTrajectories_Request__time(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DroneTrajectories_Request__time(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__DroneTrajectories_Request__time(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__DroneTrajectories_Request__time(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__DroneTrajectories_Request__time(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__DroneTrajectories_Request__time(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__DroneTrajectories_Request__time(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__DroneTrajectories_Request__time(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

size_t size_function__DroneTrajectories_Request__epsilon(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<double> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DroneTrajectories_Request__epsilon(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<double> *>(untyped_member);
  return &member[index];
}

void * get_function__DroneTrajectories_Request__epsilon(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<double> *>(untyped_member);
  return &member[index];
}

void fetch_function__DroneTrajectories_Request__epsilon(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const double *>(
    get_const_function__DroneTrajectories_Request__epsilon(untyped_member, index));
  auto & value = *reinterpret_cast<double *>(untyped_value);
  value = item;
}

void assign_function__DroneTrajectories_Request__epsilon(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<double *>(
    get_function__DroneTrajectories_Request__epsilon(untyped_member, index));
  const auto & value = *reinterpret_cast<const double *>(untyped_value);
  item = value;
}

void resize_function__DroneTrajectories_Request__epsilon(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<double> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DroneTrajectories_Request_message_member_array[7] = {
  {
    "robot_name",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces::srv::DroneTrajectories_Request, robot_name),  // bytes offset in struct
    nullptr,  // default value
    size_function__DroneTrajectories_Request__robot_name,  // size() function pointer
    get_const_function__DroneTrajectories_Request__robot_name,  // get_const(index) function pointer
    get_function__DroneTrajectories_Request__robot_name,  // get(index) function pointer
    fetch_function__DroneTrajectories_Request__robot_name,  // fetch(index, &value) function pointer
    assign_function__DroneTrajectories_Request__robot_name,  // assign(index, value) function pointer
    resize_function__DroneTrajectories_Request__robot_name  // resize(index) function pointer
  },
  {
    "ri_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces::srv::DroneTrajectories_Request, ri_x),  // bytes offset in struct
    nullptr,  // default value
    size_function__DroneTrajectories_Request__ri_x,  // size() function pointer
    get_const_function__DroneTrajectories_Request__ri_x,  // get_const(index) function pointer
    get_function__DroneTrajectories_Request__ri_x,  // get(index) function pointer
    fetch_function__DroneTrajectories_Request__ri_x,  // fetch(index, &value) function pointer
    assign_function__DroneTrajectories_Request__ri_x,  // assign(index, value) function pointer
    resize_function__DroneTrajectories_Request__ri_x  // resize(index) function pointer
  },
  {
    "ri_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces::srv::DroneTrajectories_Request, ri_y),  // bytes offset in struct
    nullptr,  // default value
    size_function__DroneTrajectories_Request__ri_y,  // size() function pointer
    get_const_function__DroneTrajectories_Request__ri_y,  // get_const(index) function pointer
    get_function__DroneTrajectories_Request__ri_y,  // get(index) function pointer
    fetch_function__DroneTrajectories_Request__ri_y,  // fetch(index, &value) function pointer
    assign_function__DroneTrajectories_Request__ri_y,  // assign(index, value) function pointer
    resize_function__DroneTrajectories_Request__ri_y  // resize(index) function pointer
  },
  {
    "rf_x",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces::srv::DroneTrajectories_Request, rf_x),  // bytes offset in struct
    nullptr,  // default value
    size_function__DroneTrajectories_Request__rf_x,  // size() function pointer
    get_const_function__DroneTrajectories_Request__rf_x,  // get_const(index) function pointer
    get_function__DroneTrajectories_Request__rf_x,  // get(index) function pointer
    fetch_function__DroneTrajectories_Request__rf_x,  // fetch(index, &value) function pointer
    assign_function__DroneTrajectories_Request__rf_x,  // assign(index, value) function pointer
    resize_function__DroneTrajectories_Request__rf_x  // resize(index) function pointer
  },
  {
    "rf_y",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces::srv::DroneTrajectories_Request, rf_y),  // bytes offset in struct
    nullptr,  // default value
    size_function__DroneTrajectories_Request__rf_y,  // size() function pointer
    get_const_function__DroneTrajectories_Request__rf_y,  // get_const(index) function pointer
    get_function__DroneTrajectories_Request__rf_y,  // get(index) function pointer
    fetch_function__DroneTrajectories_Request__rf_y,  // fetch(index, &value) function pointer
    assign_function__DroneTrajectories_Request__rf_y,  // assign(index, value) function pointer
    resize_function__DroneTrajectories_Request__rf_y  // resize(index) function pointer
  },
  {
    "time",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces::srv::DroneTrajectories_Request, time),  // bytes offset in struct
    nullptr,  // default value
    size_function__DroneTrajectories_Request__time,  // size() function pointer
    get_const_function__DroneTrajectories_Request__time,  // get_const(index) function pointer
    get_function__DroneTrajectories_Request__time,  // get(index) function pointer
    fetch_function__DroneTrajectories_Request__time,  // fetch(index, &value) function pointer
    assign_function__DroneTrajectories_Request__time,  // assign(index, value) function pointer
    resize_function__DroneTrajectories_Request__time  // resize(index) function pointer
  },
  {
    "epsilon",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces::srv::DroneTrajectories_Request, epsilon),  // bytes offset in struct
    nullptr,  // default value
    size_function__DroneTrajectories_Request__epsilon,  // size() function pointer
    get_const_function__DroneTrajectories_Request__epsilon,  // get_const(index) function pointer
    get_function__DroneTrajectories_Request__epsilon,  // get(index) function pointer
    fetch_function__DroneTrajectories_Request__epsilon,  // fetch(index, &value) function pointer
    assign_function__DroneTrajectories_Request__epsilon,  // assign(index, value) function pointer
    resize_function__DroneTrajectories_Request__epsilon  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DroneTrajectories_Request_message_members = {
  "package_master_interfaces::srv",  // message namespace
  "DroneTrajectories_Request",  // message name
  7,  // number of fields
  sizeof(package_master_interfaces::srv::DroneTrajectories_Request),
  DroneTrajectories_Request_message_member_array,  // message members
  DroneTrajectories_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  DroneTrajectories_Request_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DroneTrajectories_Request_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DroneTrajectories_Request_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace package_master_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<package_master_interfaces::srv::DroneTrajectories_Request>()
{
  return &::package_master_interfaces::srv::rosidl_typesupport_introspection_cpp::DroneTrajectories_Request_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, package_master_interfaces, srv, DroneTrajectories_Request)() {
  return &::package_master_interfaces::srv::rosidl_typesupport_introspection_cpp::DroneTrajectories_Request_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include "array"
// already included above
// #include "cstddef"
// already included above
// #include "string"
// already included above
// #include "vector"
// already included above
// #include "rosidl_runtime_c/message_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "package_master_interfaces/srv/detail/drone_trajectories__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/field_types.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace package_master_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

void DroneTrajectories_Response_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) package_master_interfaces::srv::DroneTrajectories_Response(_init);
}

void DroneTrajectories_Response_fini_function(void * message_memory)
{
  auto typed_message = static_cast<package_master_interfaces::srv::DroneTrajectories_Response *>(message_memory);
  typed_message->~DroneTrajectories_Response();
}

size_t size_function__DroneTrajectories_Response__sequences(const void * untyped_member)
{
  const auto * member = reinterpret_cast<const std::vector<package_master_interfaces::msg::SequenceElements> *>(untyped_member);
  return member->size();
}

const void * get_const_function__DroneTrajectories_Response__sequences(const void * untyped_member, size_t index)
{
  const auto & member =
    *reinterpret_cast<const std::vector<package_master_interfaces::msg::SequenceElements> *>(untyped_member);
  return &member[index];
}

void * get_function__DroneTrajectories_Response__sequences(void * untyped_member, size_t index)
{
  auto & member =
    *reinterpret_cast<std::vector<package_master_interfaces::msg::SequenceElements> *>(untyped_member);
  return &member[index];
}

void fetch_function__DroneTrajectories_Response__sequences(
  const void * untyped_member, size_t index, void * untyped_value)
{
  const auto & item = *reinterpret_cast<const package_master_interfaces::msg::SequenceElements *>(
    get_const_function__DroneTrajectories_Response__sequences(untyped_member, index));
  auto & value = *reinterpret_cast<package_master_interfaces::msg::SequenceElements *>(untyped_value);
  value = item;
}

void assign_function__DroneTrajectories_Response__sequences(
  void * untyped_member, size_t index, const void * untyped_value)
{
  auto & item = *reinterpret_cast<package_master_interfaces::msg::SequenceElements *>(
    get_function__DroneTrajectories_Response__sequences(untyped_member, index));
  const auto & value = *reinterpret_cast<const package_master_interfaces::msg::SequenceElements *>(untyped_value);
  item = value;
}

void resize_function__DroneTrajectories_Response__sequences(void * untyped_member, size_t size)
{
  auto * member =
    reinterpret_cast<std::vector<package_master_interfaces::msg::SequenceElements> *>(untyped_member);
  member->resize(size);
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember DroneTrajectories_Response_message_member_array[1] = {
  {
    "sequences",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<package_master_interfaces::msg::SequenceElements>(),  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(package_master_interfaces::srv::DroneTrajectories_Response, sequences),  // bytes offset in struct
    nullptr,  // default value
    size_function__DroneTrajectories_Response__sequences,  // size() function pointer
    get_const_function__DroneTrajectories_Response__sequences,  // get_const(index) function pointer
    get_function__DroneTrajectories_Response__sequences,  // get(index) function pointer
    fetch_function__DroneTrajectories_Response__sequences,  // fetch(index, &value) function pointer
    assign_function__DroneTrajectories_Response__sequences,  // assign(index, value) function pointer
    resize_function__DroneTrajectories_Response__sequences  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers DroneTrajectories_Response_message_members = {
  "package_master_interfaces::srv",  // message namespace
  "DroneTrajectories_Response",  // message name
  1,  // number of fields
  sizeof(package_master_interfaces::srv::DroneTrajectories_Response),
  DroneTrajectories_Response_message_member_array,  // message members
  DroneTrajectories_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  DroneTrajectories_Response_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t DroneTrajectories_Response_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DroneTrajectories_Response_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace package_master_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<package_master_interfaces::srv::DroneTrajectories_Response>()
{
  return &::package_master_interfaces::srv::rosidl_typesupport_introspection_cpp::DroneTrajectories_Response_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, package_master_interfaces, srv, DroneTrajectories_Response)() {
  return &::package_master_interfaces::srv::rosidl_typesupport_introspection_cpp::DroneTrajectories_Response_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_interface/macros.h"
// already included above
// #include "rosidl_typesupport_introspection_cpp/visibility_control.h"
// already included above
// #include "package_master_interfaces/srv/detail/drone_trajectories__struct.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/service_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/service_type_support_decl.hpp"

namespace package_master_interfaces
{

namespace srv
{

namespace rosidl_typesupport_introspection_cpp
{

// this is intentionally not const to allow initialization later to prevent an initialization race
static ::rosidl_typesupport_introspection_cpp::ServiceMembers DroneTrajectories_service_members = {
  "package_master_interfaces::srv",  // service namespace
  "DroneTrajectories",  // service name
  // these two fields are initialized below on the first access
  // see get_service_type_support_handle<package_master_interfaces::srv::DroneTrajectories>()
  nullptr,  // request message
  nullptr  // response message
};

static const rosidl_service_type_support_t DroneTrajectories_service_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &DroneTrajectories_service_members,
  get_service_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace srv

}  // namespace package_master_interfaces


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
get_service_type_support_handle<package_master_interfaces::srv::DroneTrajectories>()
{
  // get a handle to the value to be returned
  auto service_type_support =
    &::package_master_interfaces::srv::rosidl_typesupport_introspection_cpp::DroneTrajectories_service_type_support_handle;
  // get a non-const and properly typed version of the data void *
  auto service_members = const_cast<::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
    static_cast<const ::rosidl_typesupport_introspection_cpp::ServiceMembers *>(
      service_type_support->data));
  // make sure that both the request_members_ and the response_members_ are initialized
  // if they are not, initialize them
  if (
    service_members->request_members_ == nullptr ||
    service_members->response_members_ == nullptr)
  {
    // initialize the request_members_ with the static function from the external library
    service_members->request_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::package_master_interfaces::srv::DroneTrajectories_Request
      >()->data
      );
    // initialize the response_members_ with the static function from the external library
    service_members->response_members_ = static_cast<
      const ::rosidl_typesupport_introspection_cpp::MessageMembers *
      >(
      ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<
        ::package_master_interfaces::srv::DroneTrajectories_Response
      >()->data
      );
  }
  // finally return the properly initialized service_type_support handle
  return service_type_support;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, package_master_interfaces, srv, DroneTrajectories)() {
  return ::rosidl_typesupport_introspection_cpp::get_service_type_support_handle<package_master_interfaces::srv::DroneTrajectories>();
}

#ifdef __cplusplus
}
#endif
