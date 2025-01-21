// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from package_master_interfaces:msg/Num.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_
#define PACKAGE_MASTER_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/Num in the package package_master_interfaces.
typedef struct package_master_interfaces__msg__Num
{
  int64_t num;
} package_master_interfaces__msg__Num;

// Struct for a sequence of package_master_interfaces__msg__Num.
typedef struct package_master_interfaces__msg__Num__Sequence
{
  package_master_interfaces__msg__Num * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} package_master_interfaces__msg__Num__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PACKAGE_MASTER_INTERFACES__MSG__DETAIL__NUM__STRUCT_H_
