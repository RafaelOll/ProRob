// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from package_master_interfaces:srv/SendPositions.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__SRV__DETAIL__SEND_POSITIONS__TRAITS_HPP_
#define PACKAGE_MASTER_INTERFACES__SRV__DETAIL__SEND_POSITIONS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "package_master_interfaces/srv/detail/send_positions__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace package_master_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SendPositions_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: robot_names
  {
    if (msg.robot_names.size() == 0) {
      out << "robot_names: []";
    } else {
      out << "robot_names: [";
      size_t pending_items = msg.robot_names.size();
      for (auto item : msg.robot_names) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: positions_x
  {
    if (msg.positions_x.size() == 0) {
      out << "positions_x: []";
    } else {
      out << "positions_x: [";
      size_t pending_items = msg.positions_x.size();
      for (auto item : msg.positions_x) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: positions_y
  {
    if (msg.positions_y.size() == 0) {
      out << "positions_y: []";
    } else {
      out << "positions_y: [";
      size_t pending_items = msg.positions_y.size();
      for (auto item : msg.positions_y) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
    out << ", ";
  }

  // member: positions_z
  {
    if (msg.positions_z.size() == 0) {
      out << "positions_z: []";
    } else {
      out << "positions_z: [";
      size_t pending_items = msg.positions_z.size();
      for (auto item : msg.positions_z) {
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
  const SendPositions_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: robot_names
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.robot_names.size() == 0) {
      out << "robot_names: []\n";
    } else {
      out << "robot_names:\n";
      for (auto item : msg.robot_names) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: positions_x
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positions_x.size() == 0) {
      out << "positions_x: []\n";
    } else {
      out << "positions_x:\n";
      for (auto item : msg.positions_x) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: positions_y
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positions_y.size() == 0) {
      out << "positions_y: []\n";
    } else {
      out << "positions_y:\n";
      for (auto item : msg.positions_y) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }

  // member: positions_z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.positions_z.size() == 0) {
      out << "positions_z: []\n";
    } else {
      out << "positions_z:\n";
      for (auto item : msg.positions_z) {
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

inline std::string to_yaml(const SendPositions_Request & msg, bool use_flow_style = false)
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
  const package_master_interfaces::srv::SendPositions_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  package_master_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use package_master_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const package_master_interfaces::srv::SendPositions_Request & msg)
{
  return package_master_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<package_master_interfaces::srv::SendPositions_Request>()
{
  return "package_master_interfaces::srv::SendPositions_Request";
}

template<>
inline const char * name<package_master_interfaces::srv::SendPositions_Request>()
{
  return "package_master_interfaces/srv/SendPositions_Request";
}

template<>
struct has_fixed_size<package_master_interfaces::srv::SendPositions_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<package_master_interfaces::srv::SendPositions_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<package_master_interfaces::srv::SendPositions_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace package_master_interfaces
{

namespace srv
{

inline void to_flow_style_yaml(
  const SendPositions_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: ack
  {
    out << "ack: ";
    rosidl_generator_traits::value_to_yaml(msg.ack, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SendPositions_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: ack
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "ack: ";
    rosidl_generator_traits::value_to_yaml(msg.ack, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SendPositions_Response & msg, bool use_flow_style = false)
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
  const package_master_interfaces::srv::SendPositions_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  package_master_interfaces::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use package_master_interfaces::srv::to_yaml() instead")]]
inline std::string to_yaml(const package_master_interfaces::srv::SendPositions_Response & msg)
{
  return package_master_interfaces::srv::to_yaml(msg);
}

template<>
inline const char * data_type<package_master_interfaces::srv::SendPositions_Response>()
{
  return "package_master_interfaces::srv::SendPositions_Response";
}

template<>
inline const char * name<package_master_interfaces::srv::SendPositions_Response>()
{
  return "package_master_interfaces/srv/SendPositions_Response";
}

template<>
struct has_fixed_size<package_master_interfaces::srv::SendPositions_Response>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<package_master_interfaces::srv::SendPositions_Response>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<package_master_interfaces::srv::SendPositions_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<package_master_interfaces::srv::SendPositions>()
{
  return "package_master_interfaces::srv::SendPositions";
}

template<>
inline const char * name<package_master_interfaces::srv::SendPositions>()
{
  return "package_master_interfaces/srv/SendPositions";
}

template<>
struct has_fixed_size<package_master_interfaces::srv::SendPositions>
  : std::integral_constant<
    bool,
    has_fixed_size<package_master_interfaces::srv::SendPositions_Request>::value &&
    has_fixed_size<package_master_interfaces::srv::SendPositions_Response>::value
  >
{
};

template<>
struct has_bounded_size<package_master_interfaces::srv::SendPositions>
  : std::integral_constant<
    bool,
    has_bounded_size<package_master_interfaces::srv::SendPositions_Request>::value &&
    has_bounded_size<package_master_interfaces::srv::SendPositions_Response>::value
  >
{
};

template<>
struct is_service<package_master_interfaces::srv::SendPositions>
  : std::true_type
{
};

template<>
struct is_service_request<package_master_interfaces::srv::SendPositions_Request>
  : std::true_type
{
};

template<>
struct is_service_response<package_master_interfaces::srv::SendPositions_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PACKAGE_MASTER_INTERFACES__SRV__DETAIL__SEND_POSITIONS__TRAITS_HPP_
