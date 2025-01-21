// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from package_master_interfaces:msg/SequenceElments.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__TRAITS_HPP_
#define PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "package_master_interfaces/msg/detail/sequence_elments__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace package_master_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const SequenceElments & msg,
  std::ostream & out)
{
  out << "{";
  // member: dx
  {
    out << "dx: ";
    rosidl_generator_traits::value_to_yaml(msg.dx, out);
    out << ", ";
  }

  // member: dy
  {
    out << "dy: ";
    rosidl_generator_traits::value_to_yaml(msg.dy, out);
    out << ", ";
  }

  // member: z
  {
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << ", ";
  }

  // member: targettime
  {
    out << "targettime: ";
    rosidl_generator_traits::value_to_yaml(msg.targettime, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const SequenceElments & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: dx
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dx: ";
    rosidl_generator_traits::value_to_yaml(msg.dx, out);
    out << "\n";
  }

  // member: dy
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "dy: ";
    rosidl_generator_traits::value_to_yaml(msg.dy, out);
    out << "\n";
  }

  // member: z
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "z: ";
    rosidl_generator_traits::value_to_yaml(msg.z, out);
    out << "\n";
  }

  // member: targettime
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "targettime: ";
    rosidl_generator_traits::value_to_yaml(msg.targettime, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const SequenceElments & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace package_master_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use package_master_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const package_master_interfaces::msg::SequenceElments & msg,
  std::ostream & out, size_t indentation = 0)
{
  package_master_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use package_master_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const package_master_interfaces::msg::SequenceElments & msg)
{
  return package_master_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<package_master_interfaces::msg::SequenceElments>()
{
  return "package_master_interfaces::msg::SequenceElments";
}

template<>
inline const char * name<package_master_interfaces::msg::SequenceElments>()
{
  return "package_master_interfaces/msg/SequenceElments";
}

template<>
struct has_fixed_size<package_master_interfaces::msg::SequenceElments>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<package_master_interfaces::msg::SequenceElments>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<package_master_interfaces::msg::SequenceElments>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__TRAITS_HPP_
