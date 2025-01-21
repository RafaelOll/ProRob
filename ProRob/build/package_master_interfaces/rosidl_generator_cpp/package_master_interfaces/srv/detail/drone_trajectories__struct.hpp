// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from package_master_interfaces:srv/DroneTrajectories.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__STRUCT_HPP_
#define PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__package_master_interfaces__srv__DroneTrajectories_Request __attribute__((deprecated))
#else
# define DEPRECATED__package_master_interfaces__srv__DroneTrajectories_Request __declspec(deprecated)
#endif

namespace package_master_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DroneTrajectories_Request_
{
  using Type = DroneTrajectories_Request_<ContainerAllocator>;

  explicit DroneTrajectories_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DroneTrajectories_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _robot_name_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>>;
  _robot_name_type robot_name;
  using _ri_x_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _ri_x_type ri_x;
  using _ri_y_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _ri_y_type ri_y;
  using _rf_x_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _rf_x_type rf_x;
  using _rf_y_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _rf_y_type rf_y;
  using _time_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _time_type time;
  using _epsilon_type =
    std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>>;
  _epsilon_type epsilon;

  // setters for named parameter idiom
  Type & set__robot_name(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>> & _arg)
  {
    this->robot_name = _arg;
    return *this;
  }
  Type & set__ri_x(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->ri_x = _arg;
    return *this;
  }
  Type & set__ri_y(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->ri_y = _arg;
    return *this;
  }
  Type & set__rf_x(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->rf_x = _arg;
    return *this;
  }
  Type & set__rf_y(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->rf_y = _arg;
    return *this;
  }
  Type & set__time(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->time = _arg;
    return *this;
  }
  Type & set__epsilon(
    const std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> & _arg)
  {
    this->epsilon = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__package_master_interfaces__srv__DroneTrajectories_Request
    std::shared_ptr<package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__package_master_interfaces__srv__DroneTrajectories_Request
    std::shared_ptr<package_master_interfaces::srv::DroneTrajectories_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneTrajectories_Request_ & other) const
  {
    if (this->robot_name != other.robot_name) {
      return false;
    }
    if (this->ri_x != other.ri_x) {
      return false;
    }
    if (this->ri_y != other.ri_y) {
      return false;
    }
    if (this->rf_x != other.rf_x) {
      return false;
    }
    if (this->rf_y != other.rf_y) {
      return false;
    }
    if (this->time != other.time) {
      return false;
    }
    if (this->epsilon != other.epsilon) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneTrajectories_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneTrajectories_Request_

// alias to use template instance with default allocator
using DroneTrajectories_Request =
  package_master_interfaces::srv::DroneTrajectories_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace package_master_interfaces


// Include directives for member types
// Member 'sequences'
#include "package_master_interfaces/msg/detail/sequence_elements__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__package_master_interfaces__srv__DroneTrajectories_Response __attribute__((deprecated))
#else
# define DEPRECATED__package_master_interfaces__srv__DroneTrajectories_Response __declspec(deprecated)
#endif

namespace package_master_interfaces
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DroneTrajectories_Response_
{
  using Type = DroneTrajectories_Response_<ContainerAllocator>;

  explicit DroneTrajectories_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit DroneTrajectories_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _sequences_type =
    std::vector<package_master_interfaces::msg::SequenceElements_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<package_master_interfaces::msg::SequenceElements_<ContainerAllocator>>>;
  _sequences_type sequences;

  // setters for named parameter idiom
  Type & set__sequences(
    const std::vector<package_master_interfaces::msg::SequenceElements_<ContainerAllocator>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<package_master_interfaces::msg::SequenceElements_<ContainerAllocator>>> & _arg)
  {
    this->sequences = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__package_master_interfaces__srv__DroneTrajectories_Response
    std::shared_ptr<package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__package_master_interfaces__srv__DroneTrajectories_Response
    std::shared_ptr<package_master_interfaces::srv::DroneTrajectories_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DroneTrajectories_Response_ & other) const
  {
    if (this->sequences != other.sequences) {
      return false;
    }
    return true;
  }
  bool operator!=(const DroneTrajectories_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DroneTrajectories_Response_

// alias to use template instance with default allocator
using DroneTrajectories_Response =
  package_master_interfaces::srv::DroneTrajectories_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace package_master_interfaces

namespace package_master_interfaces
{

namespace srv
{

struct DroneTrajectories
{
  using Request = package_master_interfaces::srv::DroneTrajectories_Request;
  using Response = package_master_interfaces::srv::DroneTrajectories_Response;
};

}  // namespace srv

}  // namespace package_master_interfaces

#endif  // PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__STRUCT_HPP_
