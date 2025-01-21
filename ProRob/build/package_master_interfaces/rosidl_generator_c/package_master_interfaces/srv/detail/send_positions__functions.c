// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from package_master_interfaces:srv/SendPositions.idl
// generated code does not contain a copyright notice
#include "package_master_interfaces/srv/detail/send_positions__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `robot_names`
#include "rosidl_runtime_c/string_functions.h"
// Member `positions_x`
// Member `positions_y`
// Member `positions_z`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

bool
package_master_interfaces__srv__SendPositions_Request__init(package_master_interfaces__srv__SendPositions_Request * msg)
{
  if (!msg) {
    return false;
  }
  // robot_names
  if (!rosidl_runtime_c__String__Sequence__init(&msg->robot_names, 0)) {
    package_master_interfaces__srv__SendPositions_Request__fini(msg);
    return false;
  }
  // positions_x
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positions_x, 0)) {
    package_master_interfaces__srv__SendPositions_Request__fini(msg);
    return false;
  }
  // positions_y
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positions_y, 0)) {
    package_master_interfaces__srv__SendPositions_Request__fini(msg);
    return false;
  }
  // positions_z
  if (!rosidl_runtime_c__double__Sequence__init(&msg->positions_z, 0)) {
    package_master_interfaces__srv__SendPositions_Request__fini(msg);
    return false;
  }
  return true;
}

void
package_master_interfaces__srv__SendPositions_Request__fini(package_master_interfaces__srv__SendPositions_Request * msg)
{
  if (!msg) {
    return;
  }
  // robot_names
  rosidl_runtime_c__String__Sequence__fini(&msg->robot_names);
  // positions_x
  rosidl_runtime_c__double__Sequence__fini(&msg->positions_x);
  // positions_y
  rosidl_runtime_c__double__Sequence__fini(&msg->positions_y);
  // positions_z
  rosidl_runtime_c__double__Sequence__fini(&msg->positions_z);
}

bool
package_master_interfaces__srv__SendPositions_Request__are_equal(const package_master_interfaces__srv__SendPositions_Request * lhs, const package_master_interfaces__srv__SendPositions_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // robot_names
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->robot_names), &(rhs->robot_names)))
  {
    return false;
  }
  // positions_x
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positions_x), &(rhs->positions_x)))
  {
    return false;
  }
  // positions_y
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positions_y), &(rhs->positions_y)))
  {
    return false;
  }
  // positions_z
  if (!rosidl_runtime_c__double__Sequence__are_equal(
      &(lhs->positions_z), &(rhs->positions_z)))
  {
    return false;
  }
  return true;
}

bool
package_master_interfaces__srv__SendPositions_Request__copy(
  const package_master_interfaces__srv__SendPositions_Request * input,
  package_master_interfaces__srv__SendPositions_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // robot_names
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->robot_names), &(output->robot_names)))
  {
    return false;
  }
  // positions_x
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positions_x), &(output->positions_x)))
  {
    return false;
  }
  // positions_y
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positions_y), &(output->positions_y)))
  {
    return false;
  }
  // positions_z
  if (!rosidl_runtime_c__double__Sequence__copy(
      &(input->positions_z), &(output->positions_z)))
  {
    return false;
  }
  return true;
}

package_master_interfaces__srv__SendPositions_Request *
package_master_interfaces__srv__SendPositions_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__SendPositions_Request * msg = (package_master_interfaces__srv__SendPositions_Request *)allocator.allocate(sizeof(package_master_interfaces__srv__SendPositions_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(package_master_interfaces__srv__SendPositions_Request));
  bool success = package_master_interfaces__srv__SendPositions_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
package_master_interfaces__srv__SendPositions_Request__destroy(package_master_interfaces__srv__SendPositions_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    package_master_interfaces__srv__SendPositions_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
package_master_interfaces__srv__SendPositions_Request__Sequence__init(package_master_interfaces__srv__SendPositions_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__SendPositions_Request * data = NULL;

  if (size) {
    data = (package_master_interfaces__srv__SendPositions_Request *)allocator.zero_allocate(size, sizeof(package_master_interfaces__srv__SendPositions_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = package_master_interfaces__srv__SendPositions_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        package_master_interfaces__srv__SendPositions_Request__fini(&data[i - 1]);
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
package_master_interfaces__srv__SendPositions_Request__Sequence__fini(package_master_interfaces__srv__SendPositions_Request__Sequence * array)
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
      package_master_interfaces__srv__SendPositions_Request__fini(&array->data[i]);
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

package_master_interfaces__srv__SendPositions_Request__Sequence *
package_master_interfaces__srv__SendPositions_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__SendPositions_Request__Sequence * array = (package_master_interfaces__srv__SendPositions_Request__Sequence *)allocator.allocate(sizeof(package_master_interfaces__srv__SendPositions_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = package_master_interfaces__srv__SendPositions_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
package_master_interfaces__srv__SendPositions_Request__Sequence__destroy(package_master_interfaces__srv__SendPositions_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    package_master_interfaces__srv__SendPositions_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
package_master_interfaces__srv__SendPositions_Request__Sequence__are_equal(const package_master_interfaces__srv__SendPositions_Request__Sequence * lhs, const package_master_interfaces__srv__SendPositions_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!package_master_interfaces__srv__SendPositions_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
package_master_interfaces__srv__SendPositions_Request__Sequence__copy(
  const package_master_interfaces__srv__SendPositions_Request__Sequence * input,
  package_master_interfaces__srv__SendPositions_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(package_master_interfaces__srv__SendPositions_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    package_master_interfaces__srv__SendPositions_Request * data =
      (package_master_interfaces__srv__SendPositions_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!package_master_interfaces__srv__SendPositions_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          package_master_interfaces__srv__SendPositions_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!package_master_interfaces__srv__SendPositions_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


bool
package_master_interfaces__srv__SendPositions_Response__init(package_master_interfaces__srv__SendPositions_Response * msg)
{
  if (!msg) {
    return false;
  }
  // ack
  return true;
}

void
package_master_interfaces__srv__SendPositions_Response__fini(package_master_interfaces__srv__SendPositions_Response * msg)
{
  if (!msg) {
    return;
  }
  // ack
}

bool
package_master_interfaces__srv__SendPositions_Response__are_equal(const package_master_interfaces__srv__SendPositions_Response * lhs, const package_master_interfaces__srv__SendPositions_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // ack
  if (lhs->ack != rhs->ack) {
    return false;
  }
  return true;
}

bool
package_master_interfaces__srv__SendPositions_Response__copy(
  const package_master_interfaces__srv__SendPositions_Response * input,
  package_master_interfaces__srv__SendPositions_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // ack
  output->ack = input->ack;
  return true;
}

package_master_interfaces__srv__SendPositions_Response *
package_master_interfaces__srv__SendPositions_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__SendPositions_Response * msg = (package_master_interfaces__srv__SendPositions_Response *)allocator.allocate(sizeof(package_master_interfaces__srv__SendPositions_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(package_master_interfaces__srv__SendPositions_Response));
  bool success = package_master_interfaces__srv__SendPositions_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
package_master_interfaces__srv__SendPositions_Response__destroy(package_master_interfaces__srv__SendPositions_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    package_master_interfaces__srv__SendPositions_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
package_master_interfaces__srv__SendPositions_Response__Sequence__init(package_master_interfaces__srv__SendPositions_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__SendPositions_Response * data = NULL;

  if (size) {
    data = (package_master_interfaces__srv__SendPositions_Response *)allocator.zero_allocate(size, sizeof(package_master_interfaces__srv__SendPositions_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = package_master_interfaces__srv__SendPositions_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        package_master_interfaces__srv__SendPositions_Response__fini(&data[i - 1]);
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
package_master_interfaces__srv__SendPositions_Response__Sequence__fini(package_master_interfaces__srv__SendPositions_Response__Sequence * array)
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
      package_master_interfaces__srv__SendPositions_Response__fini(&array->data[i]);
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

package_master_interfaces__srv__SendPositions_Response__Sequence *
package_master_interfaces__srv__SendPositions_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__srv__SendPositions_Response__Sequence * array = (package_master_interfaces__srv__SendPositions_Response__Sequence *)allocator.allocate(sizeof(package_master_interfaces__srv__SendPositions_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = package_master_interfaces__srv__SendPositions_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
package_master_interfaces__srv__SendPositions_Response__Sequence__destroy(package_master_interfaces__srv__SendPositions_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    package_master_interfaces__srv__SendPositions_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
package_master_interfaces__srv__SendPositions_Response__Sequence__are_equal(const package_master_interfaces__srv__SendPositions_Response__Sequence * lhs, const package_master_interfaces__srv__SendPositions_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!package_master_interfaces__srv__SendPositions_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
package_master_interfaces__srv__SendPositions_Response__Sequence__copy(
  const package_master_interfaces__srv__SendPositions_Response__Sequence * input,
  package_master_interfaces__srv__SendPositions_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(package_master_interfaces__srv__SendPositions_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    package_master_interfaces__srv__SendPositions_Response * data =
      (package_master_interfaces__srv__SendPositions_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!package_master_interfaces__srv__SendPositions_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          package_master_interfaces__srv__SendPositions_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!package_master_interfaces__srv__SendPositions_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
