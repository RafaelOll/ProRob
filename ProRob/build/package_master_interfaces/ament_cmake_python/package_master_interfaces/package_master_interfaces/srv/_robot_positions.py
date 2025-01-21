# generated from rosidl_generator_py/resource/_idl.py.em
# with input from package_master_interfaces:srv/RobotPositions.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_RobotPositions_Request(type):
    """Metaclass of message 'RobotPositions_Request'."""

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
                'package_master_interfaces.srv.RobotPositions_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__robot_positions__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__robot_positions__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__robot_positions__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__robot_positions__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__robot_positions__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotPositions_Request(metaclass=Metaclass_RobotPositions_Request):
    """Message class 'RobotPositions_Request'."""

    __slots__ = [
        '_robot_names',
    ]

    _fields_and_field_types = {
        'robot_names': 'sequence<string>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.robot_names = kwargs.get('robot_names', [])

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
        if self.robot_names != other.robot_names:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def robot_names(self):
        """Message field 'robot_names'."""
        return self._robot_names

    @robot_names.setter
    def robot_names(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'robot_names' field must be a set or sequence and each value of type 'str'"
        self._robot_names = value


# Import statements for member types

# Member 'positions_x'
# Member 'positions_y'
# Member 'positions_z'
import array  # noqa: E402, I100

# already imported above
# import builtins

import math  # noqa: E402, I100

# already imported above
# import rosidl_parser.definition


class Metaclass_RobotPositions_Response(type):
    """Metaclass of message 'RobotPositions_Response'."""

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
                'package_master_interfaces.srv.RobotPositions_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__robot_positions__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__robot_positions__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__robot_positions__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__robot_positions__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__robot_positions__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class RobotPositions_Response(metaclass=Metaclass_RobotPositions_Response):
    """Message class 'RobotPositions_Response'."""

    __slots__ = [
        '_robot_names',
        '_positions_x',
        '_positions_y',
        '_positions_z',
    ]

    _fields_and_field_types = {
        'robot_names': 'sequence<string>',
        'positions_x': 'sequence<double>',
        'positions_y': 'sequence<double>',
        'positions_z': 'sequence<double>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.BasicType('double')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.robot_names = kwargs.get('robot_names', [])
        self.positions_x = array.array('d', kwargs.get('positions_x', []))
        self.positions_y = array.array('d', kwargs.get('positions_y', []))
        self.positions_z = array.array('d', kwargs.get('positions_z', []))

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
        if self.robot_names != other.robot_names:
            return False
        if self.positions_x != other.positions_x:
            return False
        if self.positions_y != other.positions_y:
            return False
        if self.positions_z != other.positions_z:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def robot_names(self):
        """Message field 'robot_names'."""
        return self._robot_names

    @robot_names.setter
    def robot_names(self, value):
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'robot_names' field must be a set or sequence and each value of type 'str'"
        self._robot_names = value

    @builtins.property
    def positions_x(self):
        """Message field 'positions_x'."""
        return self._positions_x

    @positions_x.setter
    def positions_x(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'positions_x' array.array() must have the type code of 'd'"
            self._positions_x = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'positions_x' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._positions_x = array.array('d', value)

    @builtins.property
    def positions_y(self):
        """Message field 'positions_y'."""
        return self._positions_y

    @positions_y.setter
    def positions_y(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'positions_y' array.array() must have the type code of 'd'"
            self._positions_y = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'positions_y' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._positions_y = array.array('d', value)

    @builtins.property
    def positions_z(self):
        """Message field 'positions_z'."""
        return self._positions_z

    @positions_z.setter
    def positions_z(self, value):
        if isinstance(value, array.array):
            assert value.typecode == 'd', \
                "The 'positions_z' array.array() must have the type code of 'd'"
            self._positions_z = value
            return
        if __debug__:
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, float) for v in value) and
                 all(not (val < -1.7976931348623157e+308 or val > 1.7976931348623157e+308) or math.isinf(val) for val in value)), \
                "The 'positions_z' field must be a set or sequence and each value of type 'float' and each double in [-179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000, 179769313486231570814527423731704356798070567525844996598917476803157260780028538760589558632766878171540458953514382464234321326889464182768467546703537516986049910576551282076245490090389328944075868508455133942304583236903222948165808559332123348274797826204144723168738177180919299881250404026184124858368.000000]"
        self._positions_z = array.array('d', value)


class Metaclass_RobotPositions(type):
    """Metaclass of service 'RobotPositions'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('package_master_interfaces')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'package_master_interfaces.srv.RobotPositions')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__robot_positions

            from package_master_interfaces.srv import _robot_positions
            if _robot_positions.Metaclass_RobotPositions_Request._TYPE_SUPPORT is None:
                _robot_positions.Metaclass_RobotPositions_Request.__import_type_support__()
            if _robot_positions.Metaclass_RobotPositions_Response._TYPE_SUPPORT is None:
                _robot_positions.Metaclass_RobotPositions_Response.__import_type_support__()


class RobotPositions(metaclass=Metaclass_RobotPositions):
    from package_master_interfaces.srv._robot_positions import RobotPositions_Request as Request
    from package_master_interfaces.srv._robot_positions import RobotPositions_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
