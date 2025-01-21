// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from package_master_interfaces:srv/AddThreeInts.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__SRV__DETAIL__ADD_THREE_INTS__BUILDER_HPP_
#define PACKAGE_MASTER_INTERFACES__SRV__DETAIL__ADD_THREE_INTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "package_master_interfaces/srv/detail/add_three_ints__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace package_master_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddThreeInts_Request_c
{
public:
  explicit Init_AddThreeInts_Request_c(::package_master_interfaces::srv::AddThreeInts_Request & msg)
  : msg_(msg)
  {}
  ::package_master_interfaces::srv::AddThreeInts_Request c(::package_master_interfaces::srv::AddThreeInts_Request::_c_type arg)
  {
    msg_.c = std::move(arg);
    return std::move(msg_);
  }

private:
  ::package_master_interfaces::srv::AddThreeInts_Request msg_;
};

class Init_AddThreeInts_Request_b
{
public:
  explicit Init_AddThreeInts_Request_b(::package_master_interfaces::srv::AddThreeInts_Request & msg)
  : msg_(msg)
  {}
  Init_AddThreeInts_Request_c b(::package_master_interfaces::srv::AddThreeInts_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return Init_AddThreeInts_Request_c(msg_);
  }

private:
  ::package_master_interfaces::srv::AddThreeInts_Request msg_;
};

class Init_AddThreeInts_Request_a
{
public:
  Init_AddThreeInts_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddThreeInts_Request_b a(::package_master_interfaces::srv::AddThreeInts_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_AddThreeInts_Request_b(msg_);
  }

private:
  ::package_master_interfaces::srv::AddThreeInts_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::package_master_interfaces::srv::AddThreeInts_Request>()
{
  return package_master_interfaces::srv::builder::Init_AddThreeInts_Request_a();
}

}  // namespace package_master_interfaces


namespace package_master_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddThreeInts_Response_sum
{
public:
  Init_AddThreeInts_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::package_master_interfaces::srv::AddThreeInts_Response sum(::package_master_interfaces::srv::AddThreeInts_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::package_master_interfaces::srv::AddThreeInts_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::package_master_interfaces::srv::AddThreeInts_Response>()
{
  return package_master_interfaces::srv::builder::Init_AddThreeInts_Response_sum();
}

}  // namespace package_master_interfaces

#endif  // PACKAGE_MASTER_INTERFACES__SRV__DETAIL__ADD_THREE_INTS__BUILDER_HPP_
