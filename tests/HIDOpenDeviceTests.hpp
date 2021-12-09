#pragma once
extern "C" {
    #include <fff.h>
    #include <hidapi.h>
}
#include <cstdlib>
#include <gtest/gtest.h>
#include <hid/device.hpp>
#include <hid/hidException.hpp>

class HIDOpenDeviceTests : public ::testing::Test{
    public:
        HIDOpenDeviceTests(){};
        ~HIDOpenDeviceTests(){};
};