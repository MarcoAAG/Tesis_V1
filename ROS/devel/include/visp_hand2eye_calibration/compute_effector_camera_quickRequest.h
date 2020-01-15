// Generated by gencpp from file visp_hand2eye_calibration/compute_effector_camera_quickRequest.msg
// DO NOT EDIT!


#ifndef VISP_HAND2EYE_CALIBRATION_MESSAGE_COMPUTE_EFFECTOR_CAMERA_QUICKREQUEST_H
#define VISP_HAND2EYE_CALIBRATION_MESSAGE_COMPUTE_EFFECTOR_CAMERA_QUICKREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <visp_hand2eye_calibration/TransformArray.h>
#include <visp_hand2eye_calibration/TransformArray.h>

namespace visp_hand2eye_calibration
{
template <class ContainerAllocator>
struct compute_effector_camera_quickRequest_
{
  typedef compute_effector_camera_quickRequest_<ContainerAllocator> Type;

  compute_effector_camera_quickRequest_()
    : camera_object()
    , world_effector()  {
    }
  compute_effector_camera_quickRequest_(const ContainerAllocator& _alloc)
    : camera_object(_alloc)
    , world_effector(_alloc)  {
  (void)_alloc;
    }



   typedef  ::visp_hand2eye_calibration::TransformArray_<ContainerAllocator>  _camera_object_type;
  _camera_object_type camera_object;

   typedef  ::visp_hand2eye_calibration::TransformArray_<ContainerAllocator>  _world_effector_type;
  _world_effector_type world_effector;





  typedef boost::shared_ptr< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> const> ConstPtr;

}; // struct compute_effector_camera_quickRequest_

typedef ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<std::allocator<void> > compute_effector_camera_quickRequest;

typedef boost::shared_ptr< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest > compute_effector_camera_quickRequestPtr;
typedef boost::shared_ptr< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest const> compute_effector_camera_quickRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace visp_hand2eye_calibration

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/melodic/share/sensor_msgs/cmake/../msg'], 'visp_hand2eye_calibration': ['/home/marco/Tesis/ROS/src/vision_visp/visp_hand2eye_calibration/msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4ce42b1236ce32724031d598c2a332bf";
  }

  static const char* value(const ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4ce42b1236ce3272ULL;
  static const uint64_t static_value2 = 0x4031d598c2a332bfULL;
};

template<class ContainerAllocator>
struct DataType< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "visp_hand2eye_calibration/compute_effector_camera_quickRequest";
  }

  static const char* value(const ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"\n"
"\n"
"visp_hand2eye_calibration/TransformArray camera_object\n"
"visp_hand2eye_calibration/TransformArray world_effector\n"
"\n"
"================================================================================\n"
"MSG: visp_hand2eye_calibration/TransformArray\n"
"# An array of transforms with a header for global reference.\n"
"\n"
"Header header\n"
"\n"
"geometry_msgs/Transform[] transforms\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Transform\n"
"# This represents the transform between two coordinate frames in free space.\n"
"\n"
"Vector3 translation\n"
"Quaternion rotation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.camera_object);
      stream.next(m.world_effector);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct compute_effector_camera_quickRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::visp_hand2eye_calibration::compute_effector_camera_quickRequest_<ContainerAllocator>& v)
  {
    s << indent << "camera_object: ";
    s << std::endl;
    Printer< ::visp_hand2eye_calibration::TransformArray_<ContainerAllocator> >::stream(s, indent + "  ", v.camera_object);
    s << indent << "world_effector: ";
    s << std::endl;
    Printer< ::visp_hand2eye_calibration::TransformArray_<ContainerAllocator> >::stream(s, indent + "  ", v.world_effector);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VISP_HAND2EYE_CALIBRATION_MESSAGE_COMPUTE_EFFECTOR_CAMERA_QUICKREQUEST_H
