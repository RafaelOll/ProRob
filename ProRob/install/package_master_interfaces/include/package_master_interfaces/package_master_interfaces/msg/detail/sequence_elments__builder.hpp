// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from package_master_interfaces:msg/SequenceElments.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__BUILDER_HPP_
#define PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "package_master_interfaces/msg/detail/sequence_elments__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace package_master_interfaces
{

namespace msg
{

namespace builder
{

class Init_SequenceElments_targettime
{
public:
  explicit Init_SequenceElments_targettime(::package_master_interfaces::msg::SequenceElments & msg)
  : msg_(msg)
  {}
  ::package_master_interfaces::msg::SequenceElments targettime(::package_master_interfaces::msg::SequenceElments::_targettime_type arg)
  {
    msg_.targettime = std::move(arg);
    return std::move(msg_);
  }

private:
  ::package_master_interfaces::msg::SequenceElments msg_;
};

class Init_SequenceElments_z
{
public:
  explicit Init_SequenceElments_z(::package_master_interfaces::msg::SequenceElments & msg)
  : msg_(msg)
  {}
  Init_SequenceElments_targettime z(::package_master_interfaces::msg::SequenceElments::_z_type arg)
  {
    msg_.z = std::move(arg);
    return Init_SequenceElments_targettime(msg_);
  }

private:
  ::package_master_interfaces::msg::SequenceElments msg_;
};

class Init_SequenceElments_dy
{
public:
  explicit Init_SequenceElments_dy(::package_master_interfaces::msg::SequenceElments & msg)
  : msg_(msg)
  {}
  Init_SequenceElments_z dy(::package_master_interfaces::msg::SequenceElments::_dy_type arg)
  {
    msg_.dy = std::move(arg);
    return Init_SequenceElments_z(msg_);
  }

private:
  ::package_master_interfaces::msg::SequenceElments msg_;
};

class Init_SequenceElments_dx
{
public:
  Init_SequenceElments_dx()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SequenceElments_dy dx(::package_master_interfaces::msg::SequenceElments::_dx_type arg)
  {
    msg_.dx = std::move(arg);
    return Init_SequenceElments_dy(msg_);
  }

private:
  ::package_master_interfaces::msg::SequenceElments msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::package_master_interfaces::msg::SequenceElments>()
{
  return package_master_interfaces::msg::builder::Init_SequenceElments_dx();
}

}  // namespace package_master_interfaces

#endif  // PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__BUILDER_HPP_
