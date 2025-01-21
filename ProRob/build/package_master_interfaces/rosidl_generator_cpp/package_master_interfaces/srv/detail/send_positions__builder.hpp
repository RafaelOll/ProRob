// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from package_master_interfaces:srv/SendPositions.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__SRV__DETAIL__SEND_POSITIONS__BUILDER_HPP_
#define PACKAGE_MASTER_INTERFACES__SRV__DETAIL__SEND_POSITIONS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "package_master_interfaces/srv/detail/send_positions__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace package_master_interfaces
{

namespace srv
{

namespace builder
{

class Init_SendPositions_Request_positions_z
{
public:
  explicit Init_SendPositions_Request_positions_z(::package_master_interfaces::srv::SendPositions_Request & msg)
  : msg_(msg)
  {}
  ::package_master_interfaces::srv::SendPositions_Request positions_z(::package_master_interfaces::srv::SendPositions_Request::_positions_z_type arg)
  {
    msg_.positions_z = std::move(arg);
    return std::move(msg_);
  }

private:
  ::package_master_interfaces::srv::SendPositions_Request msg_;
};

class Init_SendPositions_Request_positions_y
{
public:
  explicit Init_SendPositions_Request_positions_y(::package_master_interfaces::srv::SendPositions_Request & msg)
  : msg_(msg)
  {}
  Init_SendPositions_Request_positions_z positions_y(::package_master_interfaces::srv::SendPositions_Request::_positions_y_type arg)
  {
    msg_.positions_y = std::move(arg);
    return Init_SendPositions_Request_positions_z(msg_);
  }

private:
  ::package_master_interfaces::srv::SendPositions_Request msg_;
};

class Init_SendPositions_Request_positions_x
{
public:
  explicit Init_SendPositions_Request_positions_x(::package_master_interfaces::srv::SendPositions_Request & msg)
  : msg_(msg)
  {}
  Init_SendPositions_Request_positions_y positions_x(::package_master_interfaces::srv::SendPositions_Request::_positions_x_type arg)
  {
    msg_.positions_x = std::move(arg);
    return Init_SendPositions_Request_positions_y(msg_);
  }

private:
  ::package_master_interfaces::srv::SendPositions_Request msg_;
};

class Init_SendPositions_Request_robot_names
{
public:
  Init_SendPositions_Request_robot_names()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SendPositions_Request_positions_x robot_names(::package_master_interfaces::srv::SendPositions_Request::_robot_names_type arg)
  {
    msg_.robot_names = std::move(arg);
    return Init_SendPositions_Request_positions_x(msg_);
  }

private:
  ::package_master_interfaces::srv::SendPositions_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::package_master_interfaces::srv::SendPositions_Request>()
{
  return package_master_interfaces::srv::builder::Init_SendPositions_Request_robot_names();
}

}  // namespace package_master_interfaces


namespace package_master_interfaces
{

namespace srv
{

namespace builder
{

class Init_SendPositions_Response_ack
{
public:
  Init_SendPositions_Response_ack()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::package_master_interfaces::srv::SendPositions_Response ack(::package_master_interfaces::srv::SendPositions_Response::_ack_type arg)
  {
    msg_.ack = std::move(arg);
    return std::move(msg_);
  }

private:
  ::package_master_interfaces::srv::SendPositions_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::package_master_interfaces::srv::SendPositions_Response>()
{
  return package_master_interfaces::srv::builder::Init_SendPositions_Response_ack();
}

}  // namespace package_master_interfaces

#endif  // PACKAGE_MASTER_INTERFACES__SRV__DETAIL__SEND_POSITIONS__BUILDER_HPP_
