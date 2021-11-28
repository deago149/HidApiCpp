#pragma once
extern "C"{
    #include "fff.h"
}
#include <gtest/gtest.h>
#include <hid/enumerate.hpp>



class HIDEnumeratorTests : public ::testing::Test
{
private:
    /* data */
public:
    HIDEnumeratorTests(){}
    ~HIDEnumeratorTests(){}
};

TEST_F(HIDEnumeratorTests, ObjectCreationWorks){
    HID::Enumerate DeviceEnumerate;
}


