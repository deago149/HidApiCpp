#pragma once
#include <vector>
#include <gtest/gtest.h>
#include <hid/Device.hpp>
#include "fff_hidapi.hpp"


DEFINE_FFF_GLOBALS;

class DeviceCreationTests : public ::testing::Test{
    public:
        
        std::string path = "ThisIsThePath"; 
        std::wstring serial_number = L"3115515153";
        unsigned short vid = 9944;
        unsigned short pid = 3221;
        DeviceCreationTests(){};
        ~DeviceCreationTests(){
            RESET_FAKE(hid_open);
            RESET_FAKE(hid_open_path);
            RESET_FAKE(hid_close);
        }
    private:
        
};

TEST_F(DeviceCreationTests, CanCreateDeviceWithPath){
    HID::Device dev(path);
}

TEST_F(DeviceCreationTests, CanCreateDeviceWithSerialNumber){
    HID::Device dev(vid, pid, serial_number);
}

TEST_F(DeviceCreationTests, ConstructorCallsHIDOpenPath){
    HID::Device dev(path);
    ASSERT_EQ(hid_open_path_fake.call_count, 1);
}

TEST_F(DeviceCreationTests, ConstructorCallsHIDOpen){
    HID::Device dev(vid, pid,serial_number);
    ASSERT_EQ(hid_open_fake.call_count, 1);
}

TEST_F(DeviceCreationTests, DestructorCallsHIDClose){
    HID::Device* dev = new HID::Device(path);
    delete dev;
    ASSERT_EQ(hid_close_fake.call_count, 1);
}

