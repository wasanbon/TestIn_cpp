// -*- C++ -*-
/*!
 * @file  TestIn.cpp
 * @brief TestIn Component
 * @date $Date$
 *
 * $Id$
 */

#include "TestIn_cpp.h"

// Module specification
// <rtc-template block="module_spec">
static const char* testin_spec[] =
  {
    "implementation_id", "TestIn_cpp",
    "type_name",         "TestIn_cpp",
    "description",       "TestIn Component",
    "version",           "1.0.2",
    "vendor",            "Sugar Sweet Robotics",
    "category",          "Test",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
TestIn::TestIn(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
TestIn::~TestIn()
{
}



RTC::ReturnCode_t TestIn::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("in", m_inIn);
  
  // Set OutPort buffer
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t TestIn::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t TestIn::onActivated(RTC::UniqueId ec_id)
{
  fout.open("testout.txt");
  return RTC::RTC_OK;
}



RTC::ReturnCode_t TestIn::onDeactivated(RTC::UniqueId ec_id)
{
  fout.close();
  return RTC::RTC_OK;
}



RTC::ReturnCode_t TestIn::onExecute(RTC::UniqueId ec_id)
{
  if (m_inIn.isNew()) {
    m_inIn.read();
    fout << m_in.data << std::endl;
  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t TestIn::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void TestIn_cppInit(RTC::Manager* manager)
  {
    coil::Properties profile(testin_spec);
    manager->registerFactory(profile,
                             RTC::Create<TestIn>,
                             RTC::Delete<TestIn>);
  }
  
};


