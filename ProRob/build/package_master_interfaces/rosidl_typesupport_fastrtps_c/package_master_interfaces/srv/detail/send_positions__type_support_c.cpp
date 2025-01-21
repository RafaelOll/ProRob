// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from package_master_interfaces:srv/SendPositions.idl
// generated code does not contain a copyright notice
#include "package_master_interfaces/srv/detail/send_positions__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "package_master_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "package_master_interfaces/srv/detail/send_positions__struct.h"
#include "package_master_interfaces/srv/detail/send_positions__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/primitives_sequence.h"  // positions_x, positions_y, positions_z
#include "rosidl_runtime_c/primitives_sequence_functions.h"  // positions_x, positions_y, positions_z
#include "rosidl_runtime_c/string.h"  // robot_names
#include "rosidl_runtime_c/string_functions.h"  // robot_names

// forward declare type support functions


using _SendPositions_Request__ros_msg_type = package_master_interfaces__srv__SendPositions_Request;

static bool _SendPositions_Request__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SendPositions_Request__ros_msg_type * ros_message = static_cast<const _SendPositions_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_names
  {
    size_t size = ros_message->robot_names.size;
    auto array_ptr = ros_message->robot_names.data;
    cdr << static_cast<uint32_t>(size);
    for (size_t i = 0; i < size; ++i) {
      const rosidl_runtime_c__String * str = &array_ptr[i];
      if (str->capacity == 0 || str->capacity <= str->size) {
        fprintf(stderr, "string capacity not greater than size\n");
        return false;
      }
      if (str->data[str->size] != '\0') {
        fprintf(stderr, "string not null-terminated\n");
        return false;
      }
      cdr << str->data;
    }
  }

  // Field name: positions_x
  {
    size_t size = ros_message->positions_x.size;
    auto array_ptr = ros_message->positions_x.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: positions_y
  {
    size_t size = ros_message->positions_y.size;
    auto array_ptr = ros_message->positions_y.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  // Field name: positions_z
  {
    size_t size = ros_message->positions_z.size;
    auto array_ptr = ros_message->positions_z.data;
    cdr << static_cast<uint32_t>(size);
    cdr.serializeArray(array_ptr, size);
  }

  return true;
}

static bool _SendPositions_Request__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SendPositions_Request__ros_msg_type * ros_message = static_cast<_SendPositions_Request__ros_msg_type *>(untyped_ros_message);
  // Field name: robot_names
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->robot_names.data) {
      rosidl_runtime_c__String__Sequence__fini(&ros_message->robot_names);
    }
    if (!rosidl_runtime_c__String__Sequence__init(&ros_message->robot_names, size)) {
      fprintf(stderr, "failed to create array for field 'robot_names'");
      return false;
    }
    auto array_ptr = ros_message->robot_names.data;
    for (size_t i = 0; i < size; ++i) {
      std::string tmp;
      cdr >> tmp;
      auto & ros_i = array_ptr[i];
      if (!ros_i.data) {
        rosidl_runtime_c__String__init(&ros_i);
      }
      bool succeeded = rosidl_runtime_c__String__assign(
        &ros_i,
        tmp.c_str());
      if (!succeeded) {
        fprintf(stderr, "failed to assign string into field 'robot_names'\n");
        return false;
      }
    }
  }

  // Field name: positions_x
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->positions_x.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->positions_x);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->positions_x, size)) {
      fprintf(stderr, "failed to create array for field 'positions_x'");
      return false;
    }
    auto array_ptr = ros_message->positions_x.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: positions_y
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->positions_y.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->positions_y);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->positions_y, size)) {
      fprintf(stderr, "failed to create array for field 'positions_y'");
      return false;
    }
    auto array_ptr = ros_message->positions_y.data;
    cdr.deserializeArray(array_ptr, size);
  }

  // Field name: positions_z
  {
    uint32_t cdrSize;
    cdr >> cdrSize;
    size_t size = static_cast<size_t>(cdrSize);
    if (ros_message->positions_z.data) {
      rosidl_runtime_c__double__Sequence__fini(&ros_message->positions_z);
    }
    if (!rosidl_runtime_c__double__Sequence__init(&ros_message->positions_z, size)) {
      fprintf(stderr, "failed to create array for field 'positions_z'");
      return false;
    }
    auto array_ptr = ros_message->positions_z.data;
    cdr.deserializeArray(array_ptr, size);
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_package_master_interfaces
size_t get_serialized_size_package_master_interfaces__srv__SendPositions_Request(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SendPositions_Request__ros_msg_type * ros_message = static_cast<const _SendPositions_Request__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name robot_names
  {
    size_t array_size = ros_message->robot_names.size;
    auto array_ptr = ros_message->robot_names.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        (array_ptr[index].size + 1);
    }
  }
  // field.name positions_x
  {
    size_t array_size = ros_message->positions_x.size;
    auto array_ptr = ros_message->positions_x.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name positions_y
  {
    size_t array_size = ros_message->positions_y.size;
    auto array_ptr = ros_message->positions_y.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name positions_z
  {
    size_t array_size = ros_message->positions_z.size;
    auto array_ptr = ros_message->positions_z.data;
    current_alignment += padding +
      eprosima::fastcdr::Cdr::alignment(current_alignment, padding);
    (void)array_ptr;
    size_t item_size = sizeof(array_ptr[0]);
    current_alignment += array_size * item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SendPositions_Request__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_package_master_interfaces__srv__SendPositions_Request(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_package_master_interfaces
size_t max_serialized_size_package_master_interfaces__srv__SendPositions_Request(
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

  // member: robot_names
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
  // member: positions_x
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
  // member: positions_y
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
  // member: positions_z
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
    using DataType = package_master_interfaces__srv__SendPositions_Request;
    is_plain =
      (
      offsetof(DataType, positions_z) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SendPositions_Request__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_package_master_interfaces__srv__SendPositions_Request(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SendPositions_Request = {
  "package_master_interfaces::srv",
  "SendPositions_Request",
  _SendPositions_Request__cdr_serialize,
  _SendPositions_Request__cdr_deserialize,
  _SendPositions_Request__get_serialized_size,
  _SendPositions_Request__max_serialized_size
};

static rosidl_message_type_support_t _SendPositions_Request__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SendPositions_Request,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, package_master_interfaces, srv, SendPositions_Request)() {
  return &_SendPositions_Request__type_support;
}

#if defined(__cplusplus)
}
#endif

// already included above
// #include <cassert>
// already included above
// #include <limits>
// already included above
// #include <string>
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
// already included above
// #include "package_master_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
// already included above
// #include "package_master_interfaces/srv/detail/send_positions__struct.h"
// already included above
// #include "package_master_interfaces/srv/detail/send_positions__functions.h"
// already included above
// #include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif


// forward declare type support functions


using _SendPositions_Response__ros_msg_type = package_master_interfaces__srv__SendPositions_Response;

static bool _SendPositions_Response__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _SendPositions_Response__ros_msg_type * ros_message = static_cast<const _SendPositions_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: ack
  {
    cdr << (ros_message->ack ? true : false);
  }

  return true;
}

static bool _SendPositions_Response__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _SendPositions_Response__ros_msg_type * ros_message = static_cast<_SendPositions_Response__ros_msg_type *>(untyped_ros_message);
  // Field name: ack
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message->ack = tmp ? true : false;
  }

  return true;
}  // NOLINT(readability/fn_size)

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_package_master_interfaces
size_t get_serialized_size_package_master_interfaces__srv__SendPositions_Response(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _SendPositions_Response__ros_msg_type * ros_message = static_cast<const _SendPositions_Response__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name ack
  {
    size_t item_size = sizeof(ros_message->ack);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

static uint32_t _SendPositions_Response__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_package_master_interfaces__srv__SendPositions_Response(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_package_master_interfaces
size_t max_serialized_size_package_master_interfaces__srv__SendPositions_Response(
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

  // member: ack
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = package_master_interfaces__srv__SendPositions_Response;
    is_plain =
      (
      offsetof(DataType, ack) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static size_t _SendPositions_Response__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_package_master_interfaces__srv__SendPositions_Response(
    full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}


static message_type_support_callbacks_t __callbacks_SendPositions_Response = {
  "package_master_interfaces::srv",
  "SendPositions_Response",
  _SendPositions_Response__cdr_serialize,
  _SendPositions_Response__cdr_deserialize,
  _SendPositions_Response__get_serialized_size,
  _SendPositions_Response__max_serialized_size
};

static rosidl_message_type_support_t _SendPositions_Response__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_SendPositions_Response,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, package_master_interfaces, srv, SendPositions_Response)() {
  return &_SendPositions_Response__type_support;
}

#if defined(__cplusplus)
}
#endif

#include "rosidl_typesupport_fastrtps_cpp/service_type_support.h"
#include "rosidl_typesupport_cpp/service_type_support.hpp"
// already included above
// #include "rosidl_typesupport_fastrtps_c/identifier.h"
// already included above
// #include "package_master_interfaces/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "package_master_interfaces/srv/send_positions.h"

#if defined(__cplusplus)
extern "C"
{
#endif

static service_type_support_callbacks_t SendPositions__callbacks = {
  "package_master_interfaces::srv",
  "SendPositions",
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, package_master_interfaces, srv, SendPositions_Request)(),
  ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, package_master_interfaces, srv, SendPositions_Response)(),
};

static rosidl_service_type_support_t SendPositions__handle = {
  rosidl_typesupport_fastrtps_c__identifier,
  &SendPositions__callbacks,
  get_service_typesupport_handle_function,
};

const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, package_master_interfaces, srv, SendPositions)() {
  return &SendPositions__handle;
}

#if defined(__cplusplus)
}
#endif
