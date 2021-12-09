#pragma once
extern "C" {
    #include <fff.h>
    #include <hidapi.h>
}
#include <gtest/gtest.h>
#include <hid/device.hpp>
#include <hid/hidException.hpp>

//DEFINE_FFF_GLOBALS;
//Fake Function Definitions
//Fake Functions Headers

class HIDDeviceTests : public ::testing::Test{
    public:
        HIDDeviceTests(){

        }
        
        ~HIDDeviceTests(){}
};

TEST_F(HIDDeviceTests, ObjectCreationWorks){
    HID::Device Device(NULL);
}