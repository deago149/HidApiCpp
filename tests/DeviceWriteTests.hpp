#pragma once 
#include <vector>
#include <iostream>
#include <gtest/gtest.h>
#include <hid/Device.hpp>
#include "fff_hidapi.hpp"



class DeviceWriteTests : public::testing::Test{
    public:
        std::vector<uint8_t> emptyVec;
        std::vector<uint8_t> randVec;
        std::string randomString = "ThisIsARandomString";
        
        HID::Device *TestDevice;
        DeviceWriteTests(){
            randVec = std::vector<uint8_t>(randomString.begin(), randomString.end());
            TestDevice = new HID::Device(this->randomString); 
        };
        ~DeviceWriteTests(){
            RESET_FAKE(hid_write);
            delete TestDevice;
        };
};

TEST_F(DeviceWriteTests, WriteDataCanBeCalled){
    TestDevice->Write(randVec);
}

TEST_F(DeviceWriteTests, ReturnsZeroOnEmptyVector){
    int Expected = 0;
    int Result = TestDevice->Write(emptyVec);
    ASSERT_EQ(Expected, Result);
}

TEST_F(DeviceWriteTests, CallsHIDWrite){
    TestDevice->Write(randVec);
    ASSERT_EQ(hid_write_fake.call_count, 1);
}

TEST_F(DeviceWriteTests, ReturnsNonZeroOnNonEmptyVector){
    hid_write_fake.custom_fake = hid_write_return_length; 
    int Result = TestDevice->Write(randVec);
    ASSERT_GT(Result, 0);
}

TEST_F(DeviceWriteTests, ReturnTheResultOfHidWrite){
    int Expected = 30;
    hid_write_fake.return_val = Expected;
    int Result = TestDevice->Write(randVec);
    ASSERT_EQ(Expected, Result);
}

TEST_F(DeviceWriteTests, SecondArgShouldEqualInputVectorData){
    TestDevice->Write(randVec);
    ASSERT_EQ(hid_write_fake.arg1_val, randVec.data());
}

TEST_F(DeviceWriteTests, ThirdArgShouldEqualVectorSize){
    TestDevice->Write(randVec);
    ASSERT_EQ(hid_write_fake.arg2_val, randVec.size());
}

TEST_F(DeviceWriteTests, FirstArgumentShouldNotEqualNull){
    hid_open_path_fake.custom_fake = hid_open_path_fake_device_return;
    std::string tempPath("hellopath");
    HID::Device LocalDevice(tempPath);
    LocalDevice.Write(randVec);
    ASSERT_TRUE(hid_write_fake.arg0_val != NULL);
}