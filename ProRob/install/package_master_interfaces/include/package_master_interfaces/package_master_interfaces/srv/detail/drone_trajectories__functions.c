// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from package_master_interfaces:srv/DroneTrajectories.idl
// generated code does not contain a copyright notice
#include "package_master_interfaces/srv/detail/drone_trajectories__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `robot_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `ri_x`
// Member `ri_y`
// Member `rf_x`
// Member `rf_y`
// Member `time`
// Member `epsilon`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
package_master_interfaces__srv__DroneTrajectories_Request__init(package_master_interfaces__srv__DroneTrajectories_Request * msg)
{
  if (!msg) {
    return false;
  }
  // robot_name
  if (!rosidl_runtime_c__String__Sequence__init(&msg->robot_name, 0)) {
    package_master_interfaces__srv__DroneTrajectories_Request__fini(msg);
    return false;
  }
  // ri_x
  if (!rosidl_runtime_c__double__Sequence__init(&msg->ri_x, 0)) {
    package_master_interfaces__srv__DroneTrajectories_Request__fini(msg);
    return false;
  }
  // ri_y
  if (!rosidl_runtime_c__double__Sequence__init(&msg->ri_y, 0)) {
    package_master_interfaces__srv__DroneTrajectories_Request__fini(msg);
    return false;
  }
  // rf_x
  if (!rosidl_runtime_c__double__Sequence__init(&msg->rf_x, 0)) {
    package_master_interfaces__srv__DroneTrajectories_Request__fini(msg);
    return false;
  }
  // rf_y
  if (!rosidl_runtime_c__double__Sequence__init(&msg->rf_y, 0)) {
    package_master_interfaces__srv__DroneTrajectories_Request__fini(msg);
    return false;
  }
  // time
  if (!rosidl_runtime_c__double__Sequence__init(&msg->time, 0)) {
    package_master_interfaces__srv__DroneTrajectories_Request__fini(msg);
    return false;
  }
  // epsilon
  if (!rosidl_runtime_c__double__Sequence__init(&msg->epsilon, 0)) {
    package_master_interfaces__srv__DroneTrajectories_Request__fini(msg);
    return false;
  }
  return true;
}

void
package_master_interfaces__srv__DroneTrajectories_Request__fini(package_master_interfaces__srv__DroneTrajectories_Request * msg)
{
  if (!msg) {
    return;
  }
  // robot_name
  rosidl_runtime_c__String__Sequence__fini(&msg->robot_name);
  // ri_x
  rosidl_runtime_c__double__Sequence__fini(&msg->ri_x);
  // ri_y
  rosidl_runtime_c__double__Sequence__fini(&msg->ri_y);
  // rf_x
  rosidl_runtime_c__double__Sequence__fini(&msg->rf_x);
  // rf_y
  rosidl_runtime_c__double__Sequence__fini(&msg->rf_y);
  // time
  rosidl_runtime_c__double__Sequence__fini(&msg->time);
  // epsilon
  rosidl_runtime_c__double__Sequence__fini(&msg->epsilon);
}

bool
package_master_interfaces__srv__DroneTrajectories_Request__are_equal(const package_master_interfaces__srv__DroneTrajectories_Request * lhs, const package_master_interfaces__srv__DroneTrajectories_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_name
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->robot_name), &(rhs->robot_name)))
  {
    return false;
  }
  // ri_x
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->ri_x), &(rhs->ri_x)))
  {
    return false;
  }
  // ri_y
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->ri_y), &(rhs->ri_y)))
  {
    return false;
  }
  // rf_x
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->rf_x), &(rhs->rf_x)))
  {
    return false;
  }
  // rf_y
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->rf_y), &(rhs->rf_y)))
  {
    return false;
  }
  // time
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->time), &(rhs->time)))
  {
    return false;
  }
  // epsilon
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->epsilon), &(rhs->epsilon)))
  {
    return false;
  }
  return true;
}

bool
package_master_interfaces__srv__DroneTrajectories_Request__copy(
  const package_master_interfaces__srv__DroneTrajectories_Request * input,
  package_master_interfaces__srv__DroneTrajectories_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_name
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->robot_name), &(output->robot_name)))
  {
    return false;
  }
  // ri_x
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->ri_x), &(output->ri_x)))
  {
    return false;
  }
  // ri_y
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->ri_y), &(output->ri_y)))
  {
    return false;
  }
  // rf_x
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->rf_x), &(output->rf_x)))
  {
    return false;
  }
  // rf_y
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->rf_y), &(output->rf_y)))
  {
    return false;
  }
  // time
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->time), &(output->time)))
  {
    return false;
  }
  // epsilon
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->epsilon), &(output->epsilon)))
  {
    return false;
  }
  return true;
}

package_master_interfaces__srv__DroneTrajectories_Request *
package_master_interfaces__srv__DroneTrajectories_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__DroneTrajectories_Request * msg = (package_master_interfaces__srv__DroneTrajectories_Request *)allocator.allocate(sizeof(package_master_interfaces__srv__DroneTrajectories_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(package_master_interfaces__srv__DroneTrajectories_Request));
  bool success = package_master_interfaces__srv__DroneTrajectories_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
package_master_interfaces__srv__DroneTrajectories_Request__destroy(package_master_interfaces__srv__DroneTrajectories_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    package_master_interfaces__srv__DroneTrajectories_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
package_master_interfaces__srv__DroneTrajectories_Request__Sequence__init(package_master_interfaces__srv__DroneTrajectories_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__DroneTrajectories_Request * data = NULL;

  if (size) {
    data = (package_master_interfaces__srv__DroneTrajectories_Request *)allocator.zero_allocate(size, sizeof(package_master_interfaces__srv__DroneTrajectories_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = package_master_interfaces__srv__DroneTrajectories_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        package_master_interfaces__srv__DroneTrajectories_Request__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
package_master_interfaces__srv__DroneTrajectories_Request__Sequence__fini(package_master_interfaces__srv__DroneTrajectories_Request__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      package_master_interfaces__srv__DroneTrajectories_Request__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

package_master_interfaces__srv__DroneTrajectories_Request__Sequence *
package_master_interfaces__srv__DroneTrajectories_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__DroneTrajectories_Request__Sequence * array = (package_master_interfaces__srv__DroneTrajectories_Request__Sequence *)allocator.allocate(sizeof(package_master_interfaces__srv__DroneTrajectories_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = package_master_interfaces__srv__DroneTrajectories_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
package_master_interfaces__srv__DroneTrajectories_Request__Sequence__destroy(package_master_interfaces__srv__DroneTrajectories_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    package_master_interfaces__srv__DroneTrajectories_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
package_master_interfaces__srv__DroneTrajectories_Request__Sequence__are_equal(const package_master_interfaces__srv__DroneTrajectories_Request__Sequence * lhs, const package_master_interfaces__srv__DroneTrajectories_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!package_master_interfaces__srv__DroneTrajectories_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
package_master_interfaces__srv__DroneTrajectories_Request__Sequence__copy(
  const package_master_interfaces__srv__DroneTrajectories_Request__Sequence * input,
  package_master_interfaces__srv__DroneTrajectories_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(package_master_interfaces__srv__DroneTrajectories_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    package_master_interfaces__srv__DroneTrajectories_Request * data =
      (package_master_interfaces__srv__DroneTrajectories_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!package_master_interfaces__srv__DroneTrajectories_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          package_master_interfaces__srv__DroneTrajectories_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!package_master_interfaces__srv__DroneTrajectories_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `sequences`
#include "package_master_interfaces/msg/detail/sequence_elements__functions.h"

bool
package_master_interfaces__srv__DroneTrajectories_Response__init(package_master_interfaces__srv__DroneTrajectories_Response * msg)
{
  if (!msg) {
    return false;
  }
  // sequences
  if (!package_master_interfaces__msg__SequenceElements__Sequence__init(&msg->sequences, 0)) {
    package_master_interfaces__srv__DroneTrajectories_Response__fini(msg);
    return false;
  }
  return true;
}

void
package_master_interfaces__srv__DroneTrajectories_Response__fini(package_master_interfaces__srv__DroneTrajectories_Response * msg)
{
  if (!msg) {
    return;
  }
  // sequences
  package_master_interfaces__msg__SequenceElements__Sequence__fini(&msg->sequences);
}

bool
package_master_interfaces__srv__DroneTrajectories_Response__are_equal(const package_master_interfaces__srv__DroneTrajectories_Response * lhs, const package_master_interfaces__srv__DroneTrajectories_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // sequences
  if (!package_master_interfaces__msg__SequenceElements__Sequence__are_equal(
      &(lhs->sequences), &(rhs->sequences)))
  {
    return false;
  }
  return true;
}

bool
package_master_interfaces__srv__DroneTrajectories_Response__copy(
  const package_master_interfaces__srv__DroneTrajectories_Response * input,
  package_master_interfaces__srv__DroneTrajectories_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // sequences
  if (!package_master_interfaces__msg__SequenceElements__Sequence__copy(
      &(input->sequences), &(output->sequences)))
  {
    return false;
  }
  return true;
}

package_master_interfaces__srv__DroneTrajectories_Response *
package_master_interfaces__srv__DroneTrajectories_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__DroneTrajectories_Response * msg = (package_master_interfaces__srv__DroneTrajectories_Response *)allocator.allocate(sizeof(package_master_interfaces__srv__DroneTrajectories_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(package_master_interfaces__srv__DroneTrajectories_Response));
  bool success = package_master_interfaces__srv__DroneTrajectories_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
package_master_interfaces__srv__DroneTrajectories_Response__destroy(package_master_interfaces__srv__DroneTrajectories_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    package_master_interfaces__srv__DroneTrajectories_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
package_master_interfaces__srv__DroneTrajectories_Response__Sequence__init(package_master_interfaces__srv__DroneTrajectories_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__DroneTrajectories_Response * data = NULL;

  if (size) {
    data = (package_master_interfaces__srv__DroneTrajectories_Response *)allocator.zero_allocate(size, sizeof(package_master_interfaces__srv__DroneTrajectories_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = package_master_interfaces__srv__DroneTrajectories_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        package_master_interfaces__srv__DroneTrajectories_Response__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
package_master_interfaces__srv__DroneTrajectories_Response__Sequence__fini(package_master_interfaces__srv__DroneTrajectories_Response__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      package_master_interfaces__srv__DroneTrajectories_Response__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

package_master_interfaces__srv__DroneTrajectories_Response__Sequence *
package_master_interfaces__srv__DroneTrajectories_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__DroneTrajectories_Response__Sequence * array = (package_master_interfaces__srv__DroneTrajectories_Response__Sequence *)allocator.allocate(sizeof(package_master_interfaces__srv__DroneTrajectories_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = package_master_interfaces__srv__DroneTrajectories_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
package_master_interfaces__srv__DroneTrajectories_Response__Sequence__destroy(package_master_interfaces__srv__DroneTrajectories_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    package_master_interfaces__srv__DroneTrajectories_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
package_master_interfaces__srv__DroneTrajectories_Response__Sequence__are_equal(const package_master_interfaces__srv__DroneTrajectories_Response__Sequence * lhs, const package_master_interfaces__srv__DroneTrajectories_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!package_master_interfaces__srv__DroneTrajectories_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
package_master_interfaces__srv__DroneTrajectories_Response__Sequence__copy(
  const package_master_interfaces__srv__DroneTrajectories_Response__Sequence * input,
  package_master_interfaces__srv__DroneTrajectories_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(package_master_interfaces__srv__DroneTrajectories_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    package_master_interfaces__srv__DroneTrajectories_Response * data =
      (package_master_interfaces__srv__DroneTrajectories_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!package_master_interfaces__srv__DroneTrajectories_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          package_master_interfaces__srv__DroneTrajectories_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!package_master_interfaces__srv__DroneTrajectories_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
