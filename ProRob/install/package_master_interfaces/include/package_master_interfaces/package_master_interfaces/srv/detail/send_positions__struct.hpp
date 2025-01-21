// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from package_master_interfaces:srv/SendPositions.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__SRV__DETAIL__SEND_POSITIONS__STRUCT_HPP_
#define PACKAGE_MASTER_INTERFACES__SRV__DETAIL__SEND_POSITIONS__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__package_master_interfaces__srv__SendPositions_Request __attribute__((deprecated))
#else
# define DEPRECATED__package_master_interfaces__srv__SendPositions_Request __declspec(deprecated)
#endif

namespace package_master_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SendPositions_Request_
{
  using Type = SendPositions_Request_<ContainerAllocator>;

  explicit SendPositions_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit SendPositions_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _robot_names_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _robot_names_type robot_names;
  using _positions_x_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positions_x_type positions_x;
  using _positions_y_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positions_y_type positions_y;
  using _positions_z_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _positions_z_type positions_z;

  // setters for named parameter idiom
  Type & set__robot_names(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->robot_names = _arg;
    return *this;
  }
  Type & set__positions_x(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positions_x = _arg;
    return *this;
  }
  Type & set__positions_y(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positions_y = _arg;
    return *this;
  }
  Type & set__positions_z(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->positions_z = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__package_master_interfaces__srv__SendPositions_Request
    std::shared_ptr<package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__package_master_interfaces__srv__SendPositions_Request
    std::shared_ptr<package_master_interfaces::srv::SendPositions_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SendPositions_Request_ & other) const
  {
    if (this->robot_names != other.robot_names) {
      return false;
    }
    if (this->positions_x != other.positions_x) {
      return false;
    }
    if (this->positions_y != other.positions_y) {
      return false;
    }
    if (this->positions_z != other.positions_z) {
      return false;
    }
    return true;
  }
  bool operator!=(const SendPositions_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SendPositions_Request_

// alias to use template instance with default allocator
using SendPositions_Request =
  package_master_interfaces::srv::SendPositions_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace package_master_interfaces


#ifndef _WIN32
# define DEPRECATED__package_master_interfaces__srv__SendPositions_Response __attribute__((deprecated))
#else
# define DEPRECATED__package_master_interfaces__srv__SendPositions_Response __declspec(deprecated)
#endif

namespace package_master_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SendPositions_Response_
{
  using Type = SendPositions_Response_<ContainerAllocator>;

  explicit SendPositions_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ack = false;
    }
  }

  explicit SendPositions_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->ack = false;
    }
  }

  // field types and members
  using _ack_type =
    bool;
  _ack_type ack;

  // setters for named parameter idiom
  Type & set__ack(
    const bool & _arg)
  {
    this->ack = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__package_master_interfaces__srv__SendPositions_Response
    std::shared_ptr<package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__package_master_interfaces__srv__SendPositions_Response
    std::shared_ptr<package_master_interfaces::srv::SendPositions_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SendPositions_Response_ & other) const
  {
    if (this->ack != other.ack) {
      return false;
    }
    return true;
  }
  bool operator!=(const SendPositions_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SendPositions_Response_

// alias to use template instance with default allocator
using SendPositions_Response =
  package_master_interfaces::srv::SendPositions_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace package_master_interfaces

namespace package_master_interfaces
{

namespace srv
{

struct SendPositions
{
  using Request = package_master_interfaces::srv::SendPositions_Request;
  using Response = package_master_interfaces::srv::SendPositions_Response;
};

}  // namespace srv

}  // namespace package_master_interfaces

#endif  // PACKAGE_MASTER_INTERFACES__SRV__DETAIL__SEND_POSITIONS__STRUCT_HPP_
