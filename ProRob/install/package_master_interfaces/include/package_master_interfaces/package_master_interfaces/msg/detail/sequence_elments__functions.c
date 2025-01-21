// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from package_master_interfaces:msg/SequenceElments.idl
// generated code does not contain a copyright notice
#include "package_master_interfaces/msg/detail/sequence_elments__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
package_master_interfaces__msg__SequenceElments__init(package_master_interfaces__msg__SequenceElments * msg)
{
  if (!msg) {
    return false;
  }
  // dx
  // dy
  // z
  // targettime
  return true;
}

void
package_master_interfaces__msg__SequenceElments__fini(package_master_interfaces__msg__SequenceElments * msg)
{
  if (!msg) {
    return;
  }
  // dx
  // dy
  // z
  // targettime
}

bool
package_master_interfaces__msg__SequenceElments__are_equal(const package_master_interfaces__msg__SequenceElments * lhs, const package_master_interfaces__msg__SequenceElments * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // dx
  if (lhs->dx != rhs->dx) {
    return false;
  }
  // dy
  if (lhs->dy != rhs->dy) {
    return false;
  }
  // z
  if (lhs->z != rhs->z) {
    return false;
  }
  // targettime
  if (lhs->targettime != rhs->targettime) {
    return false;
  }
  return true;
}

bool
package_master_interfaces__msg__SequenceElments__copy(
  const package_master_interfaces__msg__SequenceElments * input,
  package_master_interfaces__msg__SequenceElments * output)
{
  if (!input || !output) {
    return false;
  }
  // dx
  output->dx = input->dx;
  // dy
  output->dy = input->dy;
  // z
  output->z = input->z;
  // targettime
  output->targettime = input->targettime;
  return true;
}

package_master_interfaces__msg__SequenceElments *
package_master_interfaces__msg__SequenceElments__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__msg__SequenceElments * msg = (package_master_interfaces__msg__SequenceElments *)allocator.allocate(sizeof(package_master_interfaces__msg__SequenceElments), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(package_master_interfaces__msg__SequenceElments));
  bool success = package_master_interfaces__msg__SequenceElments__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
package_master_interfaces__msg__SequenceElments__destroy(package_master_interfaces__msg__SequenceElments * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    package_master_interfaces__msg__SequenceElments__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
package_master_interfaces__msg__SequenceElments__Sequence__init(package_master_interfaces__msg__SequenceElments__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__msg__SequenceElments * data = NULL;

  if (size) {
    data = (package_master_interfaces__msg__SequenceElments *)allocator.zero_allocate(size, sizeof(package_master_interfaces__msg__SequenceElments), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = package_master_interfaces__msg__SequenceElments__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        package_master_interfaces__msg__SequenceElments__fini(&data[i - 1]);
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
package_master_interfaces__msg__SequenceElments__Sequence__fini(package_master_interfaces__msg__SequenceElments__Sequence * array)
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
      package_master_interfaces__msg__SequenceElments__fini(&array->data[i]);
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

package_master_interfaces__msg__SequenceElments__Sequence *
package_master_interfaces__msg__SequenceElments__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  package_master_interfaces__msg__SequenceElments__Sequence * array = (package_master_interfaces__msg__SequenceElments__Sequence *)allocator.allocate(sizeof(package_master_interfaces__msg__SequenceElments__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = package_master_interfaces__msg__SequenceElments__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
package_master_interfaces__msg__SequenceElments__Sequence__destroy(package_master_interfaces__msg__SequenceElments__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    package_master_interfaces__msg__SequenceElments__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
package_master_interfaces__msg__SequenceElments__Sequence__are_equal(const package_master_interfaces__msg__SequenceElments__Sequence * lhs, const package_master_interfaces__msg__SequenceElments__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!package_master_interfaces__msg__SequenceElments__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
package_master_interfaces__msg__SequenceElments__Sequence__copy(
  const package_master_interfaces__msg__SequenceElments__Sequence * input,
  package_master_interfaces__msg__SequenceElments__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(package_master_interfaces__msg__SequenceElments);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    package_master_interfaces__msg__SequenceElments * data =
      (package_master_interfaces__msg__SequenceElments *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!package_master_interfaces__msg__SequenceElments__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          package_master_interfaces__msg__SequenceElments__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!package_master_interfaces__msg__SequenceElments__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
