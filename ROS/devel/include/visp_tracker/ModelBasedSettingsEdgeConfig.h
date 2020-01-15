//#line 2 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"
// *********************************************************
//
// File autogenerated for the visp_tracker package
// by the dynamic_reconfigure package.
// Please do not edit.
//
// ********************************************************/

#ifndef __visp_tracker__MODELBASEDSETTINGSEDGECONFIG_H__
#define __visp_tracker__MODELBASEDSETTINGSEDGECONFIG_H__

#if __cplusplus >= 201103L
#define DYNAMIC_RECONFIGURE_FINAL final
#else
#define DYNAMIC_RECONFIGURE_FINAL
#endif

#include <dynamic_reconfigure/config_tools.h>
#include <limits>
#include <ros/node_handle.h>
#include <dynamic_reconfigure/ConfigDescription.h>
#include <dynamic_reconfigure/ParamDescription.h>
#include <dynamic_reconfigure/Group.h>
#include <dynamic_reconfigure/config_init_mutex.h>
#include <boost/any.hpp>

namespace visp_tracker
{
  class ModelBasedSettingsEdgeConfigStatics;

  class ModelBasedSettingsEdgeConfig
  {
  public:
    class AbstractParamDescription : public dynamic_reconfigure::ParamDescription
    {
    public:
      AbstractParamDescription(std::string n, std::string t, uint32_t l,
          std::string d, std::string e)
      {
        name = n;
        type = t;
        level = l;
        description = d;
        edit_method = e;
      }

      virtual void clamp(ModelBasedSettingsEdgeConfig &config, const ModelBasedSettingsEdgeConfig &max, const ModelBasedSettingsEdgeConfig &min) const = 0;
      virtual void calcLevel(uint32_t &level, const ModelBasedSettingsEdgeConfig &config1, const ModelBasedSettingsEdgeConfig &config2) const = 0;
      virtual void fromServer(const ros::NodeHandle &nh, ModelBasedSettingsEdgeConfig &config) const = 0;
      virtual void toServer(const ros::NodeHandle &nh, const ModelBasedSettingsEdgeConfig &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, ModelBasedSettingsEdgeConfig &config) const = 0;
      virtual void toMessage(dynamic_reconfigure::Config &msg, const ModelBasedSettingsEdgeConfig &config) const = 0;
      virtual void getValue(const ModelBasedSettingsEdgeConfig &config, boost::any &val) const = 0;
    };

    typedef boost::shared_ptr<AbstractParamDescription> AbstractParamDescriptionPtr;
    typedef boost::shared_ptr<const AbstractParamDescription> AbstractParamDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template <class T>
    class ParamDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractParamDescription
    {
    public:
      ParamDescription(std::string a_name, std::string a_type, uint32_t a_level,
          std::string a_description, std::string a_edit_method, T ModelBasedSettingsEdgeConfig::* a_f) :
        AbstractParamDescription(a_name, a_type, a_level, a_description, a_edit_method),
        field(a_f)
      {}

      T (ModelBasedSettingsEdgeConfig::* field);

      virtual void clamp(ModelBasedSettingsEdgeConfig &config, const ModelBasedSettingsEdgeConfig &max, const ModelBasedSettingsEdgeConfig &min) const
      {
        if (config.*field > max.*field)
          config.*field = max.*field;

        if (config.*field < min.*field)
          config.*field = min.*field;
      }

      virtual void calcLevel(uint32_t &comb_level, const ModelBasedSettingsEdgeConfig &config1, const ModelBasedSettingsEdgeConfig &config2) const
      {
        if (config1.*field != config2.*field)
          comb_level |= level;
      }

      virtual void fromServer(const ros::NodeHandle &nh, ModelBasedSettingsEdgeConfig &config) const
      {
        nh.getParam(name, config.*field);
      }

      virtual void toServer(const ros::NodeHandle &nh, const ModelBasedSettingsEdgeConfig &config) const
      {
        nh.setParam(name, config.*field);
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, ModelBasedSettingsEdgeConfig &config) const
      {
        return dynamic_reconfigure::ConfigTools::getParameter(msg, name, config.*field);
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const ModelBasedSettingsEdgeConfig &config) const
      {
        dynamic_reconfigure::ConfigTools::appendParameter(msg, name, config.*field);
      }

      virtual void getValue(const ModelBasedSettingsEdgeConfig &config, boost::any &val) const
      {
        val = config.*field;
      }
    };

    class AbstractGroupDescription : public dynamic_reconfigure::Group
    {
      public:
      AbstractGroupDescription(std::string n, std::string t, int p, int i, bool s)
      {
        name = n;
        type = t;
        parent = p;
        state = s;
        id = i;
      }

      std::vector<AbstractParamDescriptionConstPtr> abstract_parameters;
      bool state;

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &config) const = 0;
      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &config) const =0;
      virtual void updateParams(boost::any &cfg, ModelBasedSettingsEdgeConfig &top) const= 0;
      virtual void setInitialState(boost::any &cfg) const = 0;


      void convertParams()
      {
        for(std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = abstract_parameters.begin(); i != abstract_parameters.end(); ++i)
        {
          parameters.push_back(dynamic_reconfigure::ParamDescription(**i));
        }
      }
    };

    typedef boost::shared_ptr<AbstractGroupDescription> AbstractGroupDescriptionPtr;
    typedef boost::shared_ptr<const AbstractGroupDescription> AbstractGroupDescriptionConstPtr;

    // Final keyword added to class because it has virtual methods and inherits
    // from a class with a non-virtual destructor.
    template<class T, class PT>
    class GroupDescription DYNAMIC_RECONFIGURE_FINAL : public AbstractGroupDescription
    {
    public:
      GroupDescription(std::string a_name, std::string a_type, int a_parent, int a_id, bool a_s, T PT::* a_f) : AbstractGroupDescription(a_name, a_type, a_parent, a_id, a_s), field(a_f)
      {
      }

      GroupDescription(const GroupDescription<T, PT>& g): AbstractGroupDescription(g.name, g.type, g.parent, g.id, g.state), field(g.field), groups(g.groups)
      {
        parameters = g.parameters;
        abstract_parameters = g.abstract_parameters;
      }

      virtual bool fromMessage(const dynamic_reconfigure::Config &msg, boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        if(!dynamic_reconfigure::ConfigTools::getGroupState(msg, name, (*config).*field))
          return false;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          if(!(*i)->fromMessage(msg, n))
            return false;
        }

        return true;
      }

      virtual void setInitialState(boost::any &cfg) const
      {
        PT* config = boost::any_cast<PT*>(cfg);
        T* group = &((*config).*field);
        group->state = state;

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = boost::any(&((*config).*field));
          (*i)->setInitialState(n);
        }

      }

      virtual void updateParams(boost::any &cfg, ModelBasedSettingsEdgeConfig &top) const
      {
        PT* config = boost::any_cast<PT*>(cfg);

        T* f = &((*config).*field);
        f->setParams(top, abstract_parameters);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          boost::any n = &((*config).*field);
          (*i)->updateParams(n, top);
        }
      }

      virtual void toMessage(dynamic_reconfigure::Config &msg, const boost::any &cfg) const
      {
        const PT config = boost::any_cast<PT>(cfg);
        dynamic_reconfigure::ConfigTools::appendGroup<T>(msg, name, id, parent, config.*field);

        for(std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = groups.begin(); i != groups.end(); ++i)
        {
          (*i)->toMessage(msg, config.*field);
        }
      }

      T (PT::* field);
      std::vector<ModelBasedSettingsEdgeConfig::AbstractGroupDescriptionConstPtr> groups;
    };

class DEFAULT
{
  public:
    DEFAULT()
    {
      state = true;
      name = "Default";
    }

    void setParams(ModelBasedSettingsEdgeConfig &config, const std::vector<AbstractParamDescriptionConstPtr> params)
    {
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator _i = params.begin(); _i != params.end(); ++_i)
      {
        boost::any val;
        (*_i)->getValue(config, val);

        if("angle_appear"==(*_i)->name){angle_appear = boost::any_cast<double>(val);}
        if("angle_disappear"==(*_i)->name){angle_disappear = boost::any_cast<double>(val);}
        if("mask_size"==(*_i)->name){mask_size = boost::any_cast<int>(val);}
        if("range"==(*_i)->name){range = boost::any_cast<int>(val);}
        if("threshold"==(*_i)->name){threshold = boost::any_cast<double>(val);}
        if("mu1"==(*_i)->name){mu1 = boost::any_cast<double>(val);}
        if("mu2"==(*_i)->name){mu2 = boost::any_cast<double>(val);}
        if("sample_step"==(*_i)->name){sample_step = boost::any_cast<double>(val);}
        if("strip"==(*_i)->name){strip = boost::any_cast<int>(val);}
        if("first_threshold"==(*_i)->name){first_threshold = boost::any_cast<double>(val);}
      }
    }

    double angle_appear;
double angle_disappear;
int mask_size;
int range;
double threshold;
double mu1;
double mu2;
double sample_step;
int strip;
double first_threshold;

    bool state;
    std::string name;

    
}groups;



//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double angle_appear;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double angle_disappear;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int mask_size;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int range;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double threshold;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double mu1;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double mu2;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double sample_step;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      int strip;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      double first_threshold;
//#line 228 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

    bool __fromMessage__(dynamic_reconfigure::Config &msg)
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();

      int count = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        if ((*i)->fromMessage(msg, *this))
          count++;

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i ++)
      {
        if ((*i)->id == 0)
        {
          boost::any n = boost::any(this);
          (*i)->updateParams(n, *this);
          (*i)->fromMessage(msg, n);
        }
      }

      if (count != dynamic_reconfigure::ConfigTools::size(msg))
      {
        ROS_ERROR("ModelBasedSettingsEdgeConfig::__fromMessage__ called with an unexpected parameter.");
        ROS_ERROR("Booleans:");
        for (unsigned int i = 0; i < msg.bools.size(); i++)
          ROS_ERROR("  %s", msg.bools[i].name.c_str());
        ROS_ERROR("Integers:");
        for (unsigned int i = 0; i < msg.ints.size(); i++)
          ROS_ERROR("  %s", msg.ints[i].name.c_str());
        ROS_ERROR("Doubles:");
        for (unsigned int i = 0; i < msg.doubles.size(); i++)
          ROS_ERROR("  %s", msg.doubles[i].name.c_str());
        ROS_ERROR("Strings:");
        for (unsigned int i = 0; i < msg.strs.size(); i++)
          ROS_ERROR("  %s", msg.strs[i].name.c_str());
        // @todo Check that there are no duplicates. Make this error more
        // explicit.
        return false;
      }
      return true;
    }

    // This version of __toMessage__ is used during initialization of
    // statics when __getParamDescriptions__ can't be called yet.
    void __toMessage__(dynamic_reconfigure::Config &msg, const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__, const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__) const
    {
      dynamic_reconfigure::ConfigTools::clear(msg);
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toMessage(msg, *this);

      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        if((*i)->id == 0)
        {
          (*i)->toMessage(msg, *this);
        }
      }
    }

    void __toMessage__(dynamic_reconfigure::Config &msg) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      __toMessage__(msg, __param_descriptions__, __group_descriptions__);
    }

    void __toServer__(const ros::NodeHandle &nh) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->toServer(nh, *this);
    }

    void __fromServer__(const ros::NodeHandle &nh)
    {
      static bool setup=false;

      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->fromServer(nh, *this);

      const std::vector<AbstractGroupDescriptionConstPtr> &__group_descriptions__ = __getGroupDescriptions__();
      for (std::vector<AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); i++){
        if (!setup && (*i)->id == 0) {
          setup = true;
          boost::any n = boost::any(this);
          (*i)->setInitialState(n);
        }
      }
    }

    void __clamp__()
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      const ModelBasedSettingsEdgeConfig &__max__ = __getMax__();
      const ModelBasedSettingsEdgeConfig &__min__ = __getMin__();
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->clamp(*this, __max__, __min__);
    }

    uint32_t __level__(const ModelBasedSettingsEdgeConfig &config) const
    {
      const std::vector<AbstractParamDescriptionConstPtr> &__param_descriptions__ = __getParamDescriptions__();
      uint32_t level = 0;
      for (std::vector<AbstractParamDescriptionConstPtr>::const_iterator i = __param_descriptions__.begin(); i != __param_descriptions__.end(); ++i)
        (*i)->calcLevel(level, config, *this);
      return level;
    }

    static const dynamic_reconfigure::ConfigDescription &__getDescriptionMessage__();
    static const ModelBasedSettingsEdgeConfig &__getDefault__();
    static const ModelBasedSettingsEdgeConfig &__getMax__();
    static const ModelBasedSettingsEdgeConfig &__getMin__();
    static const std::vector<AbstractParamDescriptionConstPtr> &__getParamDescriptions__();
    static const std::vector<AbstractGroupDescriptionConstPtr> &__getGroupDescriptions__();

  private:
    static const ModelBasedSettingsEdgeConfigStatics *__get_statics__();
  };

  template <> // Max and min are ignored for strings.
  inline void ModelBasedSettingsEdgeConfig::ParamDescription<std::string>::clamp(ModelBasedSettingsEdgeConfig &config, const ModelBasedSettingsEdgeConfig &max, const ModelBasedSettingsEdgeConfig &min) const
  {
    (void) config;
    (void) min;
    (void) max;
    return;
  }

  class ModelBasedSettingsEdgeConfigStatics
  {
    friend class ModelBasedSettingsEdgeConfig;

    ModelBasedSettingsEdgeConfigStatics()
    {
ModelBasedSettingsEdgeConfig::GroupDescription<ModelBasedSettingsEdgeConfig::DEFAULT, ModelBasedSettingsEdgeConfig> Default("Default", "", 0, 0, true, &ModelBasedSettingsEdgeConfig::groups);
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.angle_appear = 0.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.angle_appear = 90.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.angle_appear = 65.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("angle_appear", "double", 0, "Maximal angle value to consider an appearing face", "", &ModelBasedSettingsEdgeConfig::angle_appear)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("angle_appear", "double", 0, "Maximal angle value to consider an appearing face", "", &ModelBasedSettingsEdgeConfig::angle_appear)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.angle_disappear = 0.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.angle_disappear = 90.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.angle_disappear = 75.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("angle_disappear", "double", 0, "Minimal angle value to consider that a face disappear", "", &ModelBasedSettingsEdgeConfig::angle_disappear)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("angle_disappear", "double", 0, "Minimal angle value to consider that a face disappear", "", &ModelBasedSettingsEdgeConfig::angle_disappear)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.mask_size = 3;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.mask_size = 15;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.mask_size = 7;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<int>("mask_size", "int", 0, "mask size", "", &ModelBasedSettingsEdgeConfig::mask_size)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<int>("mask_size", "int", 0, "mask size", "", &ModelBasedSettingsEdgeConfig::mask_size)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.range = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.range = 50;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.range = 5;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<int>("range", "int", 0, "range", "", &ModelBasedSettingsEdgeConfig::range)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<int>("range", "int", 0, "range", "", &ModelBasedSettingsEdgeConfig::range)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.threshold = 0.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.threshold = 20000.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.threshold = 2000.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("threshold", "double", 0, "threshold", "", &ModelBasedSettingsEdgeConfig::threshold)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("threshold", "double", 0, "threshold", "", &ModelBasedSettingsEdgeConfig::threshold)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.mu1 = 0.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.mu1 = 1.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.mu1 = 0.5;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("mu1", "double", 0, "contrast continuity (mu1)", "", &ModelBasedSettingsEdgeConfig::mu1)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("mu1", "double", 0, "contrast continuity (mu1)", "", &ModelBasedSettingsEdgeConfig::mu1)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.mu2 = 0.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.mu2 = 1.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.mu2 = 0.5;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("mu2", "double", 0, "contrast continuity (mu2)", "", &ModelBasedSettingsEdgeConfig::mu2)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("mu2", "double", 0, "contrast continuity (mu2)", "", &ModelBasedSettingsEdgeConfig::mu2)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.sample_step = 1.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.sample_step = 50.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.sample_step = 3.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("sample_step", "double", 0, "sample step", "", &ModelBasedSettingsEdgeConfig::sample_step)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("sample_step", "double", 0, "sample step", "", &ModelBasedSettingsEdgeConfig::sample_step)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.strip = 0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.strip = 10;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.strip = 2;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<int>("strip", "int", 0, "strip", "", &ModelBasedSettingsEdgeConfig::strip)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<int>("strip", "int", 0, "strip", "", &ModelBasedSettingsEdgeConfig::strip)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __min__.first_threshold = 0.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __max__.first_threshold = 1.0;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __default__.first_threshold = 0.4;
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.abstract_parameters.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("first_threshold", "double", 0, "good samples remaining threshold before reinitialization (edge)", "", &ModelBasedSettingsEdgeConfig::first_threshold)));
//#line 291 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __param_descriptions__.push_back(ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::ParamDescription<double>("first_threshold", "double", 0, "good samples remaining threshold before reinitialization (edge)", "", &ModelBasedSettingsEdgeConfig::first_threshold)));
//#line 246 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      Default.convertParams();
//#line 246 "/opt/ros/melodic/lib/python2.7/dist-packages/dynamic_reconfigure/parameter_generator_catkin.py"
      __group_descriptions__.push_back(ModelBasedSettingsEdgeConfig::AbstractGroupDescriptionConstPtr(new ModelBasedSettingsEdgeConfig::GroupDescription<ModelBasedSettingsEdgeConfig::DEFAULT, ModelBasedSettingsEdgeConfig>(Default)));
//#line 366 "/opt/ros/melodic/share/dynamic_reconfigure/cmake/../templates/ConfigType.h.template"

      for (std::vector<ModelBasedSettingsEdgeConfig::AbstractGroupDescriptionConstPtr>::const_iterator i = __group_descriptions__.begin(); i != __group_descriptions__.end(); ++i)
      {
        __description_message__.groups.push_back(**i);
      }
      __max__.__toMessage__(__description_message__.max, __param_descriptions__, __group_descriptions__);
      __min__.__toMessage__(__description_message__.min, __param_descriptions__, __group_descriptions__);
      __default__.__toMessage__(__description_message__.dflt, __param_descriptions__, __group_descriptions__);
    }
    std::vector<ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr> __param_descriptions__;
    std::vector<ModelBasedSettingsEdgeConfig::AbstractGroupDescriptionConstPtr> __group_descriptions__;
    ModelBasedSettingsEdgeConfig __max__;
    ModelBasedSettingsEdgeConfig __min__;
    ModelBasedSettingsEdgeConfig __default__;
    dynamic_reconfigure::ConfigDescription __description_message__;

    static const ModelBasedSettingsEdgeConfigStatics *get_instance()
    {
      // Split this off in a separate function because I know that
      // instance will get initialized the first time get_instance is
      // called, and I am guaranteeing that get_instance gets called at
      // most once.
      static ModelBasedSettingsEdgeConfigStatics instance;
      return &instance;
    }
  };

  inline const dynamic_reconfigure::ConfigDescription &ModelBasedSettingsEdgeConfig::__getDescriptionMessage__()
  {
    return __get_statics__()->__description_message__;
  }

  inline const ModelBasedSettingsEdgeConfig &ModelBasedSettingsEdgeConfig::__getDefault__()
  {
    return __get_statics__()->__default__;
  }

  inline const ModelBasedSettingsEdgeConfig &ModelBasedSettingsEdgeConfig::__getMax__()
  {
    return __get_statics__()->__max__;
  }

  inline const ModelBasedSettingsEdgeConfig &ModelBasedSettingsEdgeConfig::__getMin__()
  {
    return __get_statics__()->__min__;
  }

  inline const std::vector<ModelBasedSettingsEdgeConfig::AbstractParamDescriptionConstPtr> &ModelBasedSettingsEdgeConfig::__getParamDescriptions__()
  {
    return __get_statics__()->__param_descriptions__;
  }

  inline const std::vector<ModelBasedSettingsEdgeConfig::AbstractGroupDescriptionConstPtr> &ModelBasedSettingsEdgeConfig::__getGroupDescriptions__()
  {
    return __get_statics__()->__group_descriptions__;
  }

  inline const ModelBasedSettingsEdgeConfigStatics *ModelBasedSettingsEdgeConfig::__get_statics__()
  {
    const static ModelBasedSettingsEdgeConfigStatics *statics;

    if (statics) // Common case
      return statics;

    boost::mutex::scoped_lock lock(dynamic_reconfigure::__init_mutex__);

    if (statics) // In case we lost a race.
      return statics;

    statics = ModelBasedSettingsEdgeConfigStatics::get_instance();

    return statics;
  }


}

#undef DYNAMIC_RECONFIGURE_FINAL

#endif // __MODELBASEDSETTINGSEDGERECONFIGURATOR_H__
