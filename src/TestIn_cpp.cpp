﻿// -*- C++ -*-
/*!
 * @file  TestIn_cpp.cpp
 * @brief TestIn Component
 * @date $Date$
 *
 * $Id$
 */

#include "TestIn_cpp.h"

// Module specification
// <rtc-template block="module_spec">
static const char* testin_cpp_spec[] =
  {
    "implementation_id", "TestIn_cpp",
    "type_name",         "TestIn_cpp",
    "description",       "TestIn Component",
    "version",           "1.2.2",
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
TestIn_cpp::TestIn_cpp(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_inIn("in", m_in)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
TestIn_cpp::~TestIn_cpp()
{
}



RTC::ReturnCode_t TestIn_cpp::onInitialize()
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
RTC::ReturnCode_t TestIn_cpp::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn_cpp::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn_cpp::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t TestIn_cpp::onActivated(RTC::UniqueId ec_id)
{
  fout.open("testout.txt");
  return RTC::RTC_OK;
}


RTC::ReturnCode_t TestIn_cpp::onDeactivated(RTC::UniqueId ec_id)
{
  fout.close();
  return RTC::RTC_OK;
}


RTC::ReturnCode_t TestIn_cpp::onExecute(RTC::UniqueId ec_id)
{
  if (m_inIn.isNew()) {
    m_inIn.read();
    fout << m_in.data << std::endl;
  }
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t TestIn_cpp::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn_cpp::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn_cpp::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn_cpp::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t TestIn_cpp::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{

  void TestIn_cppInit(RTC::Manager* manager)
  {
    coil::Properties profile(testin_cpp_spec);
    manager->registerFactory(profile,
                             RTC::Create<TestIn_cpp>,
                             RTC::Delete<TestIn_cpp>);
  }

};


