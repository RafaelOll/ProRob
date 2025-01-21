// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from package_master_interfaces:srv/DroneTrajectories.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__BUILDER_HPP_
#define PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "package_master_interfaces/srv/detail/drone_trajectories__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace package_master_interfaces
{

namespace srv
{

namespace builder
{

class Init_DroneTrajectories_Request_epsilon
{
public:
  explicit Init_DroneTrajectories_Request_epsilon(::package_master_interfaces::srv::DroneTrajectories_Request & msg)
  : msg_(msg)
  {}
  ::package_master_interfaces::srv::DroneTrajectories_Request epsilon(::package_master_interfaces::srv::DroneTrajectories_Request::_epsilon_type arg)
  {
    msg_.epsilon = std::move(arg);
    return std::move(msg_);
  }

private:
  ::package_master_interfaces::srv::DroneTrajectories_Request msg_;
};

class Init_DroneTrajectories_Request_time
{
public:
  explicit Init_DroneTrajectories_Request_time(::package_master_interfaces::srv::DroneTrajectories_Request & msg)
  : msg_(msg)
  {}
  Init_DroneTrajectories_Request_epsilon time(::package_master_interfaces::srv::DroneTrajectories_Request::_time_type arg)
  {
    msg_.time = std::move(arg);
    return Init_DroneTrajectories_Request_epsilon(msg_);
  }

private:
  ::package_master_interfaces::srv::DroneTrajectories_Request msg_;
};

class Init_DroneTrajectories_Request_rf_y
{
public:
  explicit Init_DroneTrajectories_Request_rf_y(::package_master_interfaces::srv::DroneTrajectories_Request & msg)
  : msg_(msg)
  {}
  Init_DroneTrajectories_Request_time rf_y(::package_master_interfaces::srv::DroneTrajectories_Request::_rf_y_type arg)
  {
    msg_.rf_y = std::move(arg);
    return Init_DroneTrajectories_Request_time(msg_);
  }

private:
  ::package_master_interfaces::srv::DroneTrajectories_Request msg_;
};

class Init_DroneTrajectories_Request_rf_x
{
public:
  explicit Init_DroneTrajectories_Request_rf_x(::package_master_interfaces::srv::DroneTrajectories_Request & msg)
  : msg_(msg)
  {}
  Init_DroneTrajectories_Request_rf_y rf_x(::package_master_interfaces::srv::DroneTrajectories_Request::_rf_x_type arg)
  {
    msg_.rf_x = std::move(arg);
    return Init_DroneTrajectories_Request_rf_y(msg_);
  }

private:
  ::package_master_interfaces::srv::DroneTrajectories_Request msg_;
};

class Init_DroneTrajectories_Request_ri_y
{
public:
  explicit Init_DroneTrajectories_Request_ri_y(::package_master_interfaces::srv::DroneTrajectories_Request & msg)
  : msg_(msg)
  {}
  Init_DroneTrajectories_Request_rf_x ri_y(::package_master_interfaces::srv::DroneTrajectories_Request::_ri_y_type arg)
  {
    msg_.ri_y = std::move(arg);
    return Init_DroneTrajectories_Request_rf_x(msg_);
  }

private:
  ::package_master_interfaces::srv::DroneTrajectories_Request msg_;
};

class Init_DroneTrajectories_Request_ri_x
{
public:
  explicit Init_DroneTrajectories_Request_ri_x(::package_master_interfaces::srv::DroneTrajectories_Request & msg)
  : msg_(msg)
  {}
  Init_DroneTrajectories_Request_ri_y ri_x(::package_master_interfaces::srv::DroneTrajectories_Request::_ri_x_type arg)
  {
    msg_.ri_x = std::move(arg);
    return Init_DroneTrajectories_Request_ri_y(msg_);
  }

private:
  ::package_master_interfaces::srv::DroneTrajectories_Request msg_;
};

class Init_DroneTrajectories_Request_robot_name
{
public:
  Init_DroneTrajectories_Request_robot_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DroneTrajectories_Request_ri_x robot_name(::package_master_interfaces::srv::DroneTrajectories_Request::_robot_name_type arg)
  {
    msg_.robot_name = std::move(arg);
    return Init_DroneTrajectories_Request_ri_x(msg_);
  }

private:
  ::package_master_interfaces::srv::DroneTrajectories_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::package_master_interfaces::srv::DroneTrajectories_Request>()
{
  return package_master_interfaces::srv::builder::Init_DroneTrajectories_Request_robot_name();
}

}  // namespace package_master_interfaces


namespace package_master_interfaces
{

namespace srv
{

namespace builder
{

class Init_DroneTrajectories_Response_sequences
{
public:
  Init_DroneTrajectories_Response_sequences()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::package_master_interfaces::srv::DroneTrajectories_Response sequences(::package_master_interfaces::srv::DroneTrajectories_Response::_sequences_type arg)
  {
    msg_.sequences = std::move(arg);
    return std::move(msg_);
  }

private:
  ::package_master_interfaces::srv::DroneTrajectories_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::package_master_interfaces::srv::DroneTrajectories_Response>()
{
  return package_master_interfaces::srv::builder::Init_DroneTrajectories_Response_sequences();
}

}  // namespace package_master_interfaces

#endif  // PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__BUILDER_HPP_
