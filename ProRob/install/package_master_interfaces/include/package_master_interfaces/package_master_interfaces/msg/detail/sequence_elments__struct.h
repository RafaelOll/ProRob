// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from package_master_interfaces:msg/SequenceElments.idl
// generated code does not contain a copyright notice

#ifndef PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__STRUCT_H_
#define PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/SequenceElments in the package package_master_interfaces.
typedef struct package_master_interfaces__msg__SequenceElments
{
  double dx;
  double dy;
  int64_t z;
  double targettime;
} package_master_interfaces__msg__SequenceElments;

// Struct for a sequence of package_master_interfaces__msg__SequenceElments.
typedef struct package_master_interfaces__msg__SequenceElments__Sequence
{
  package_master_interfaces__msg__SequenceElments * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} package_master_interfaces__msg__SequenceElments__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PACKAGE_MASTER_INTERFACES__MSG__DETAIL__SEQUENCE_ELMENTS__STRUCT_H_
