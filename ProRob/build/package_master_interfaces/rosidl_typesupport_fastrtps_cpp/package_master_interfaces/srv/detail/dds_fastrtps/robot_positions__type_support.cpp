// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from package_master_interfaces:srv/RobotPositions.idl
// generated code does not contain a copyright notice
#include "package_master_interfaces/srv/detail/robot_positions__rosidl_typesupport_fastrtps_cpp.hpp"
#include "package_master_interfaces/srv/detail/robot_positions__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace package_master_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_package_master_interfaces
cdr_serialize(
  const package_master_interfaces::srv::RobotPositions_Request & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: robot_names
  {
    cdr << ros_message.robot_names;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_package_master_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  package_master_interfaces::srv::RobotPositions_Request & ros_message)
{
  // Member: robot_names
  {
    cdr >> ros_message.robot_names;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_package_master_interfaces
get_serialized_size(
  const package_master_interfaces::srv::RobotPositions_Request & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: robot_names
  {
    size_t array_size = ros_message.robot_names.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.robot_names[index].size() + 1);
    }
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_package_master_interfaces
max_serialized_size_RobotPositions_Request(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: robot_names
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = package_master_interfaces::srv::RobotPositions_Request;
    is_plain =
      (
      offsetof(DataType, robot_names) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RobotPositions_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const package_master_interfaces::srv::RobotPositions_Request *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotPositions_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<package_master_interfaces::srv::RobotPositions_Request *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotPositions_Request__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const package_master_interfaces::srv::RobotPositions_Request *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotPositions_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RobotPositions_Request(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RobotPositions_Request__callbacks = {
  "package_master_interfaces::srv",
  "RobotPositions_Request",
  _RobotPositions_Request__cdr_serialize,
  _RobotPositions_Request__cdr_deserialize,
  _RobotPositions_Request__get_serialized_size,
  _RobotPositions_Request__max_serialized_size
};

static rosidl_message_type_support_t _RobotPositions_Request__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotPositions_Request__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace package_master_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_package_master_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<package_master_interfaces::srv::RobotPositions_Request>()
{
  return &package_master_interfaces::srv::typesupport_fastrtps_cpp::_RobotPositions_Request__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, package_master_interfaces, srv, RobotPositions_Request)() {
  return &package_master_interfaces::srv::typesupport_fastrtps_cpp::_RobotPositions_Request__handle;
}

#ifdef __cplusplus
}
#endif

// already included above
// #include <limits>
// already included above
// #include <stdexcept>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_cpp/message_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
// already included above
// #include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace package_master_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_package_master_interfaces
cdr_serialize(
  const package_master_interfaces::srv::RobotPositions_Response & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: robot_names
  {
    cdr << ros_message.robot_names;
  }
  // Member: positions_x
  {
    cdr << ros_message.positions_x;
  }
  // Member: positions_y
  {
    cdr << ros_message.positions_y;
  }
  // Member: positions_z
  {
    cdr << ros_message.positions_z;
  }
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_package_master_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  package_master_interfaces::srv::RobotPositions_Response & ros_message)
{
  // Member: robot_names
  {
    cdr >> ros_message.robot_names;
  }

  // Member: positions_x
  {
    cdr >> ros_message.positions_x;
  }

  // Member: positions_y
  {
    cdr >> ros_message.positions_y;
  }

  // Member: positions_z
  {
    cdr >> ros_message.positions_z;
  }

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_package_master_interfaces
get_serialized_size(
  const package_master_interfaces::srv::RobotPositions_Response & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: robot_names
  {
    size_t array_size = ros_message.robot_names.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (ros_message.robot_names[index].size() + 1);
    }
  }
  // Member: positions_x
  {
    size_t array_size = ros_message.positions_x.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.positions_x[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: positions_y
  {
    size_t array_size = ros_message.positions_y.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.positions_y[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: positions_z
  {
    size_t array_size = ros_message.positions_z.size();

    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    size_t item_size = sizeof(ros_message.positions_z[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_package_master_interfaces
max_serialized_size_RobotPositions_Response(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: robot_names
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: positions_x
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: positions_y
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  // Member: positions_z
  {
    size_t array_size = 0;
    full_bounded = false;
    is_plain = false;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);

    last_member_size = array_size * sizeof(uint64_t);
    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = package_master_interfaces::srv::RobotPositions_Response;
    is_plain =
      (
      offsetof(DataType, positions_z) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _RobotPositions_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const package_master_interfaces::srv::RobotPositions_Response *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _RobotPositions_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<package_master_interfaces::srv::RobotPositions_Response *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _RobotPositions_Response__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const package_master_interfaces::srv::RobotPositions_Response *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _RobotPositions_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_RobotPositions_Response(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _RobotPositions_Response__callbacks = {
  "package_master_interfaces::srv",
  "RobotPositions_Response",
  _RobotPositions_Response__cdr_serialize,
  _RobotPositions_Response__cdr_deserialize,
  _RobotPositions_Response__get_serialized_size,
  _RobotPositions_Response__max_serialized_size
};

static rosidl_message_type_support_t _RobotPositions_Response__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotPositions_Response__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace package_master_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_package_master_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<package_master_interfaces::srv::RobotPositions_Response>()
{
  return &package_master_interfaces::srv::typesupport_fastrtps_cpp::_RobotPositions_Response__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, package_master_interfaces, srv, RobotPositions_Response)() {
  return &package_master_interfaces::srv::typesupport_fastrtps_cpp::_RobotPositions_Response__handle;
}

#ifdef __cplusplus
}
#endif

#include "rmw/error_handling.h"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/service_type_support_decl.hpp"

namespace package_master_interfaces
{

namespace srv
{

namespace typesupport_fastrtps_cpp
{

static service_type_support_callbacks_t _RobotPositions__callbacks = {
  "package_master_interfaces::srv",
  "RobotPositions",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, package_master_interfaces, srv, RobotPositions_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, package_master_interfaces, srv, RobotPositions_Response)(),
};

static rosidl_service_type_support_t _RobotPositions__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_RobotPositions__callbacks,
  get_service_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace srv

}  // namespace package_master_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_package_master_interfaces
const rosidl_service_type_support_t *
get_service_type_support_handle<package_master_interfaces::srv::RobotPositions>()
{
  return &package_master_interfaces::srv::typesupport_fastrtps_cpp::_RobotPositions__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, package_master_interfaces, srv, RobotPositions)() {
  return &package_master_interfaces::srv::typesupport_fastrtps_cpp::_RobotPositions__handle;
}

#ifdef __cplusplus
}
#endif
