// Generated by gencpp from file visp_tracker/InitRequest.msg
// DO NOT EDIT!


#ifndef VISP_TRACKER_MESSAGE_INITREQUEST_H
#define VISP_TRACKER_MESSAGE_INITREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <geometry_msgs/Transform.h>
#include <visp_tracker/TrackerSettings.h>
#include <visp_tracker/MovingEdgeSettings.h>
#include <visp_tracker/KltSettings.h>

namespace visp_tracker
{
template <class ContainerAllocator>
struct InitRequest_
{
  typedef InitRequest_<ContainerAllocator> Type;

  InitRequest_()
    : initial_cMo()
    , tracker_param()
    , moving_edge()
    , klt_param()  {
    }
  InitRequest_(const ContainerAllocator& _alloc)
    : initial_cMo(_alloc)
    , tracker_param(_alloc)
    , moving_edge(_alloc)
    , klt_param(_alloc)  {
  (void)_alloc;
    }



   typedef  ::geometry_msgs::Transform_<ContainerAllocator>  _initial_cMo_type;
  _initial_cMo_type initial_cMo;

   typedef  ::visp_tracker::TrackerSettings_<ContainerAllocator>  _tracker_param_type;
  _tracker_param_type tracker_param;

   typedef  ::visp_tracker::MovingEdgeSettings_<ContainerAllocator>  _moving_edge_type;
  _moving_edge_type moving_edge;

   typedef  ::visp_tracker::KltSettings_<ContainerAllocator>  _klt_param_type;
  _klt_param_type klt_param;





  typedef boost::shared_ptr< ::visp_tracker::InitRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::visp_tracker::InitRequest_<ContainerAllocator> const> ConstPtr;

}; // struct InitRequest_

typedef ::visp_tracker::InitRequest_<std::allocator<void> > InitRequest;

typedef boost::shared_ptr< ::visp_tracker::InitRequest > InitRequestPtr;
typedef boost::shared_ptr< ::visp_tracker::InitRequest const> InitRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::visp_tracker::InitRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::visp_tracker::InitRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace visp_tracker

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': True, 'IsMessage': True, 'HasHeader': False}
// {'std_msgs': ['/opt/ros/melodic/share/std_msgs/cmake/../msg'], 'sensor_msgs': ['/opt/ros/melodic/share/sensor_msgs/cmake/../msg'], 'geometry_msgs': ['/opt/ros/melodic/share/geometry_msgs/cmake/../msg'], 'visp_tracker': ['/home/marco/Tesis/ROS/src/vision_visp/visp_tracker/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::visp_tracker::InitRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::visp_tracker::InitRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visp_tracker::InitRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visp_tracker::InitRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visp_tracker::InitRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visp_tracker::InitRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::visp_tracker::InitRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "72f45c4391731722797b61d639ff8889";
  }

  static const char* value(const ::visp_tracker::InitRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x72f45c4391731722ULL;
  static const uint64_t static_value2 = 0x797b61d639ff8889ULL;
};

template<class ContainerAllocator>
struct DataType< ::visp_tracker::InitRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "visp_tracker/InitRequest";
  }

  static const char* value(const ::visp_tracker::InitRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::visp_tracker::InitRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"\n"
"geometry_msgs/Transform initial_cMo\n"
"\n"
"\n"
"TrackerSettings tracker_param\n"
"\n"
"\n"
"MovingEdgeSettings moving_edge\n"
"\n"
"\n"
"KltSettings klt_param\n"
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
"\n"
"================================================================================\n"
"MSG: visp_tracker/TrackerSettings\n"
"# This message contains tracking parameters.\n"
"#\n"
"# These parameters determine how precise, how fast and how\n"
"# reliable will be the tracking.\n"
"#\n"
"# It should be tuned carefully and can be changed dynamically.\n"
"#\n"
"# For more details, see the ViSP documentation:\n"
"# http://www.irisa.fr/lagadic/visp/publication.html\n"
"\n"
"# Common Tracker Parameters.\n"
"float64 angle_appear    # Angle to test faces apparition\n"
"float64 angle_disappear # Angle to test faces disparition\n"
"\n"
"\n"
"================================================================================\n"
"MSG: visp_tracker/MovingEdgeSettings\n"
"# This message contains tracking parameters.\n"
"#\n"
"# These parameters determine how precise, how fast and how\n"
"# reliable will be the tracking.\n"
"#\n"
"# It should be tuned carefully and can be changed dynamically.\n"
"#\n"
"# For more details, see the ViSP documentation:\n"
"# http://www.irisa.fr/lagadic/visp/publication.html\n"
"\n"
"\n"
"# Moving edge parameters.\n"
"\n"
"int64 mask_size    # Mask size (in pixel) used to compute the image gradient\n"
"                   # and determine the object contour.\n"
"		   # A larger mask size is better for larger images.\n"
"		   # 3 pixels is enough for 640x480 images.\n"
"                   # Increasing this value makes the tracking slower.\n"
"		   #\n"
"		   # Caution: this value cannot be changed dynamically\n"
"		   # without resetting the tracking.\n"
"\n"
"int64 range        # Maximum seek distance on both sides of the reference pixel.\n"
"      		   # It should match the maximum distance in pixel between\n"
"		   # the current position of the feature projection and\n"
"		   # its next position.\n"
"		   # I.e. if the object moves fast and your tracking\n"
"		   # frequency is low, this value should be increased.\n"
"                   # Increasing this value makes the tracking slower.\n"
"\n"
"float64 threshold  # Value used to determine if a moving edge is valid\n"
"		   # or not.\n"
"\n"
"float64 mu1        # Minimum image contrast allowed to detect a contour.\n"
"float64 mu2        # Maximum image contrast allowed to detect a contour.\n"
"\n"
"int64 sample_step   # Minimum distance in pixel between two\n"
"      		    # discretization points.\n"
"      		    # It avoids having too many discretization points when\n"
"		    # the tracked object is far away (and its projection\n"
"		    # in the image is small).\n"
"		    # Increasing this value makes the tracking *faster*.\n"
"\n"
"int64 strip             # How many pixels are ignored around the borders.\n"
"\n"
"\n"
"# Tracker parameters.\n"
"\n"
"float64 first_threshold # What proportion of points should be valid to\n"
"                        # acccept an initial pose.\n"
"			# Value should be between 0 et 1.\n"
"\n"
"\n"
"================================================================================\n"
"MSG: visp_tracker/KltSettings\n"
"# This message contains tracking parameters.\n"
"#\n"
"# These parameters determine how precise, how fast and how\n"
"# reliable will be the tracking.\n"
"#\n"
"# It should be tuned carefully and can be changed dynamically.\n"
"#\n"
"# For more details, see the ViSP documentation:\n"
"# http://www.irisa.fr/lagadic/visp/publication.html\n"
"\n"
"# Klt Parameters.\n"
"\n"
"int64 max_features      # Maximum number of features\n"
"int64 window_size       # Window size\n"
"float64 quality         # Quality of the tracker\n"
"float64 min_distance      # Minimum distance betwenn two points\n"
"float64 harris          # Harris free parameters\n"
"int64 size_block        # Block size\n"
"int64 pyramid_lvl       # Pyramid levels\n"
"int64 mask_border       # Mask Border\n"
"\n"
;
  }

  static const char* value(const ::visp_tracker::InitRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::visp_tracker::InitRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.initial_cMo);
      stream.next(m.tracker_param);
      stream.next(m.moving_edge);
      stream.next(m.klt_param);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct InitRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::visp_tracker::InitRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::visp_tracker::InitRequest_<ContainerAllocator>& v)
  {
    s << indent << "initial_cMo: ";
    s << std::endl;
    Printer< ::geometry_msgs::Transform_<ContainerAllocator> >::stream(s, indent + "  ", v.initial_cMo);
    s << indent << "tracker_param: ";
    s << std::endl;
    Printer< ::visp_tracker::TrackerSettings_<ContainerAllocator> >::stream(s, indent + "  ", v.tracker_param);
    s << indent << "moving_edge: ";
    s << std::endl;
    Printer< ::visp_tracker::MovingEdgeSettings_<ContainerAllocator> >::stream(s, indent + "  ", v.moving_edge);
    s << indent << "klt_param: ";
    s << std::endl;
    Printer< ::visp_tracker::KltSettings_<ContainerAllocator> >::stream(s, indent + "  ", v.klt_param);
  }
};

} // namespace message_operations
} // namespace ros

#endif // VISP_TRACKER_MESSAGE_INITREQUEST_H
