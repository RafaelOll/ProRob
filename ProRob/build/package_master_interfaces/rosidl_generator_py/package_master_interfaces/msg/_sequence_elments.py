# generated from rosidl_generator_py/resource/_idl.py.em
# with input from package_master_interfaces:msg/SequenceElments.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SequenceElments(type):
    """Metaclass of message 'SequenceElments'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('package_master_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'package_master_interfaces.msg.SequenceElments')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__sequence_elments
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__sequence_elments
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__sequence_elments
            cls._TYPE_SUPPORT = module.type_support_msg__msg__sequence_elments
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__sequence_elments

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SequenceElments(metaclass=Metaclass_SequenceElments):
    """Message class 'SequenceElments'."""

    __slots__ = [
        '_dx',
        '_dy',
        '_z',
        '_targettime',
    ]

    _fields_and_field_types = {
        'dx': 'double',
        'dy': 'double',
        'z': 'int64',
        'targettime': 'double',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('int64'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.dx = kwargs.get('dx', float())
        self.dy = kwargs.get('dy', float())
        self.z = kwargs.get('z', int())
        self.targettime = kwargs.get('targettime', float())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.dx != other.dx:
            return False
        if self.dy != other.dy:
            return False
        if self.z != other.z:
            return False
        if self.targettime != other.targettime:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def dx(self):
        """Message field 'dx'."""
        return self._dx

    @dx.setter
    def dx(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dx' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'dx' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._dx = value

    @builtins.property
    def dy(self):
        """Message field 'dy'."""
        return self._dy

    @dy.setter
    def dy(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'dy' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'dy' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._dy = value

    @builtins.property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'z' field must be of type 'int'"
            assert value >= -9223372036854775808 and value < 9223372036854775808, \
                "The 'z' field must be an integer in [-9223372036854775808, 9223372036854775807]"
        self._z = value

    @builtins.property
    def targettime(self):
        """Message field 'targettime'."""
        return self._targettime

    @targettime.setter
    def targettime(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'targettime' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'targettime' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._targettime = value
