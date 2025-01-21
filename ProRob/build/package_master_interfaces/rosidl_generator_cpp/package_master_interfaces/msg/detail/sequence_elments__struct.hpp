// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from package_master_interfaces:msg/SequenceElments.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__STRUCT_HPP_
#define PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__package_master_interfaces__msg__SequenceElments __attribute__((deprecated))
#else
# define DEPRECATED__package_master_interfaces__msg__SequenceElments __declspec(deprecated)
#endif

namespace package_master_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SequenceElments_
{
  using Type = SequenceElments_<ContainerAllocator>;

  explicit SequenceElments_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dx = 0.0;
      this->dy = 0.0;
      this->z = 0ll;
      this->targettime = 0.0;
    }
  }

  explicit SequenceElments_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->dx = 0.0;
      this->dy = 0.0;
      this->z = 0ll;
      this->targettime = 0.0;
    }
  }

  // field types and members
  using _dx_type =
    double;
  _dx_type dx;
  using _dy_type =
    double;
  _dy_type dy;
  using _z_type =
    int64_t;
  _z_type z;
  using _targettime_type =
    double;
  _targettime_type targettime;

  // setters for named parameter idiom
  Type & set__dx(
    const double & _arg)
  {
    this->dx = _arg;
    return *this;
  }
  Type & set__dy(
    const double & _arg)
  {
    this->dy = _arg;
    return *this;
  }
  Type & set__z(
    const int64_t & _arg)
  {
    this->z = _arg;
    return *this;
  }
  Type & set__targettime(
    const double & _arg)
  {
    this->targettime = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    package_master_interfaces::msg::SequenceElments_<ContainerAllocator> *;
  using ConstRawPtr =
    const package_master_interfaces::msg::SequenceElments_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<package_master_interfaces::msg::SequenceElments_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<package_master_interfaces::msg::SequenceElments_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      package_master_interfaces::msg::SequenceElments_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<package_master_interfaces::msg::SequenceElments_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      package_master_interfaces::msg::SequenceElments_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<package_master_interfaces::msg::SequenceElments_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<package_master_interfaces::msg::SequenceElments_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<package_master_interfaces::msg::SequenceElments_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__package_master_interfaces__msg__SequenceElments
    std::shared_ptr<package_master_interfaces::msg::SequenceElments_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__package_master_interfaces__msg__SequenceElments
    std::shared_ptr<package_master_interfaces::msg::SequenceElments_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SequenceElments_ & other) const
  {
    if (this->dx != other.dx) {
      return false;
    }
    if (this->dy != other.dy) {
      return false;
    }
    if (this->z != other.z) {
      return false;
    }
    if (this->targettime != other.targettime) {
      return false;
    }
    return true;
  }
  bool operator!=(const SequenceElments_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SequenceElments_

// alias to use template instance with default allocator
using SequenceElments =
  package_master_interfaces::msg::SequenceElments_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace package_master_interfaces

#endif  // PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__STRUCT_HPP_
