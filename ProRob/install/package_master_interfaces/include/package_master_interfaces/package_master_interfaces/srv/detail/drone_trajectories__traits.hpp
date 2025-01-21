// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from package_master_interfaces:srv/DroneTrajectories.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__TRAITS_HPP_
#define PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "package_master_interfaces/srv/detail/drone_trajectories__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace package_master_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneTrajectories_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_name
  {
    if (msg.robot_name.size() == 0) {
      out << "robot_name: []";
    } else {
      out << "robot_name: [";
      size_t pending_items = msg.robot_name.size();
      for (auto item : msg.robot_name) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: ri_x
  {
    if (msg.ri_x.size() == 0) {
      out << "ri_x: []";
    } else {
      out << "ri_x: [";
      size_t pending_items = msg.ri_x.size();
      for (auto item : msg.ri_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: ri_y
  {
    if (msg.ri_y.size() == 0) {
      out << "ri_y: []";
    } else {
      out << "ri_y: [";
      size_t pending_items = msg.ri_y.size();
      for (auto item : msg.ri_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: rf_x
  {
    if (msg.rf_x.size() == 0) {
      out << "rf_x: []";
    } else {
      out << "rf_x: [";
      size_t pending_items = msg.rf_x.size();
      for (auto item : msg.rf_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: rf_y
  {
    if (msg.rf_y.size() == 0) {
      out << "rf_y: []";
    } else {
      out << "rf_y: [";
      size_t pending_items = msg.rf_y.size();
      for (auto item : msg.rf_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: time
  {
    if (msg.time.size() == 0) {
      out << "time: []";
    } else {
      out << "time: [";
      size_t pending_items = msg.time.size();
      for (auto item : msg.time) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: epsilon
  {
    if (msg.epsilon.size() == 0) {
      out << "epsilon: []";
    } else {
      out << "epsilon: [";
      size_t pending_items = msg.epsilon.size();
      for (auto item : msg.epsilon) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneTrajectories_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_name
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robot_name.size() == 0) {
      out << "robot_name: []\n";
    } else {
      out << "robot_name:\n";
      for (auto item : msg.robot_name) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: ri_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ri_x.size() == 0) {
      out << "ri_x: []\n";
    } else {
      out << "ri_x:\n";
      for (auto item : msg.ri_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: ri_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.ri_y.size() == 0) {
      out << "ri_y: []\n";
    } else {
      out << "ri_y:\n";
      for (auto item : msg.ri_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: rf_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.rf_x.size() == 0) {
      out << "rf_x: []\n";
    } else {
      out << "rf_x:\n";
      for (auto item : msg.rf_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: rf_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.rf_y.size() == 0) {
      out << "rf_y: []\n";
    } else {
      out << "rf_y:\n";
      for (auto item : msg.rf_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.time.size() == 0) {
      out << "time: []\n";
    } else {
      out << "time:\n";
      for (auto item : msg.time) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: epsilon
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.epsilon.size() == 0) {
      out << "epsilon: []\n";
    } else {
      out << "epsilon:\n";
      for (auto item : msg.epsilon) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneTrajectories_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace package_master_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use package_master_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const package_master_interfaces::srv::DroneTrajectories_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  package_master_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use package_master_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const package_master_interfaces::srv::DroneTrajectories_Request & msg)
{
  return package_master_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<package_master_interfaces::srv::DroneTrajectories_Request>()
{
  return "package_master_interfaces::srv::DroneTrajectories_Request";
}

template<>
inline const char * name<package_master_interfaces::srv::DroneTrajectories_Request>()
{
  return "package_master_interfaces/srv/DroneTrajectories_Request";
}

template<>
struct has_fixed_size<package_master_interfaces::srv::DroneTrajectories_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<package_master_interfaces::srv::DroneTrajectories_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<package_master_interfaces::srv::DroneTrajectories_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

// Include directives for member types
// Member 'sequences'
#include "package_master_interfaces/msg/detail/sequence_elements__traits.hpp"

namespace package_master_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const DroneTrajectories_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: sequences
  {
    if (msg.sequences.size() == 0) {
      out << "sequences: []";
    } else {
      out << "sequences: [";
      size_t pending_items = msg.sequences.size();
      for (auto item : msg.sequences) {
        to_flow_style_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const DroneTrajectories_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: sequences
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.sequences.size() == 0) {
      out << "sequences: []\n";
    } else {
      out << "sequences:\n";
      for (auto item : msg.sequences) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "-\n";
        to_block_style_yaml(item, out, indentation + 2);
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const DroneTrajectories_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace package_master_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use package_master_interfaces::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const package_master_interfaces::srv::DroneTrajectories_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  package_master_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use package_master_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const package_master_interfaces::srv::DroneTrajectories_Response & msg)
{
  return package_master_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<package_master_interfaces::srv::DroneTrajectories_Response>()
{
  return "package_master_interfaces::srv::DroneTrajectories_Response";
}

template<>
inline const char * name<package_master_interfaces::srv::DroneTrajectories_Response>()
{
  return "package_master_interfaces/srv/DroneTrajectories_Response";
}

template<>
struct has_fixed_size<package_master_interfaces::srv::DroneTrajectories_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<package_master_interfaces::srv::DroneTrajectories_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<package_master_interfaces::srv::DroneTrajectories_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<package_master_interfaces::srv::DroneTrajectories>()
{
  return "package_master_interfaces::srv::DroneTrajectories";
}

template<>
inline const char * name<package_master_interfaces::srv::DroneTrajectories>()
{
  return "package_master_interfaces/srv/DroneTrajectories";
}

template<>
struct has_fixed_size<package_master_interfaces::srv::DroneTrajectories>
  : std::integral_constant<
    bool,
    has_fixed_size<package_master_interfaces::srv::DroneTrajectories_Request>::value &&
    has_fixed_size<package_master_interfaces::srv::DroneTrajectories_Response>::value
  >
{
};

template<>
struct has_bounded_size<package_master_interfaces::srv::DroneTrajectories>
  : std::integral_constant<
    bool,
    has_bounded_size<package_master_interfaces::srv::DroneTrajectories_Request>::value &&
    has_bounded_size<package_master_interfaces::srv::DroneTrajectories_Response>::value
  >
{
};

template<>
struct is_service<package_master_interfaces::srv::DroneTrajectories>
  : std::true_type
{
};

template<>
struct is_service_request<package_master_interfaces::srv::DroneTrajectories_Request>
  : std::true_type
{
};

template<>
struct is_service_response<package_master_interfaces::srv::DroneTrajectories_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PACKAGE_MASTER_INTERFACES__SRV__DETAIL__DRONE_TRAJECTORIES__TRAITS_HPP_
