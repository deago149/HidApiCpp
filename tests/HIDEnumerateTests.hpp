#pragma once
extern "C" {
    #include <fff.h>
    #include <hidapi.h>
}
#include <cstdlib>
#include <gtest/gtest.h>
#include <hid/enumerate.hpp>
#include <hid/hidException.hpp>


DEFINE_FFF_GLOBALS;
//Fake Function Definitions
FAKE_VALUE_FUNC(int, hid_init);
FAKE_VALUE_FUNC(int, hid_exit);
FAKE_VALUE_FUNC(hid_device_info*, hid_enumerate, unsigned short, unsigned short)
//Fake Functions Headers
hid_device_info * HID_Enumerate_Multiple(unsigned short vid, unsigned short pid);
hid_device_info * HID_Enumerate_Single(unsigned short vid, unsigned short pid);

hid_device_info * HID_Enumerate_Multiple(unsigned short vid, unsigned short pid){
    const short DEVICE_LENGTH = 10;
    hid_device_info *StartDevice, *CurrentDevice;
    StartDevice = (hid_device_info*)malloc(sizeof(hid_device_info));
    CurrentDevice = StartDevice;
    for (size_t i = 0; i < DEVICE_LENGTH; i++)
    {
        CurrentDevice->vendor_id = 20;
        CurrentDevice->product_id = 80;
        CurrentDevice->release_number = i;
        CurrentDevice->usage_page = 99;
        CurrentDevice->usage = ((i%2) != 1) ? 1 : 0;
        CurrentDevice->manufacturer_string = NULL;
        CurrentDevice->serial_number = NULL;
        CurrentDevice->product_string= NULL;
        CurrentDevice->interface_number = 88;
        CurrentDevice->next = (hid_device_info*)malloc(sizeof(hid_device_info));
        CurrentDevice = CurrentDevice->next;
    }
    CurrentDevice->next = NULL;
    return StartDevice;
}
hid_device_info * HID_Enumerate_Single(unsigned short vid, unsigned short pid){
    hid_device_info *SingleDevice = (hid_device_info*) malloc(sizeof(hid_device_info));
    SingleDevice->vendor_id = 20;
    SingleDevice->product_id = 80;
    SingleDevice->release_number = 44;
    SingleDevice->usage_page = 99;
    SingleDevice->usage = 1;
    SingleDevice->manufacturer_string = NULL;
    SingleDevice->serial_number = NULL;
    SingleDevice->product_string= NULL;
    SingleDevice->interface_number = 88;
    SingleDevice->next = NULL;
    return SingleDevice;
}

class HIDEnumeratorTests : public ::testing::Test{

    public:
        unsigned short VENDOR_ID = 0x50;
        unsigned short PRODUCT_ID = 0x445;
        HIDEnumeratorTests(){
            //Data
            
            RESET_FAKE(hid_init);
            RESET_FAKE(hid_exit);
            RESET_FAKE(hid_enumerate);
        }
        ~HIDEnumeratorTests(){}
};

TEST_F(HIDEnumeratorTests, ObjectCreationWorksNoParams){
    HID::Enumerate DeviceEnumerate;
}

TEST_F(HIDEnumeratorTests, ObjectCreationWorks){
    HID::Enumerate DeviceEnumerate(0,0);
}

TEST_F(HIDEnumeratorTests, ObjectCreationCallsHIDInit){
    HID::Enumerate DeviceEnumerate(0,0);
    ASSERT_EQ(hid_init_fake.call_count, 1);
}

TEST_F(HIDEnumeratorTests, ObjectCreationCallsHIDInitFirst){
    HID::Enumerate DeviceEnumerate(0,0);
    ASSERT_EQ((void*)fff.call_history[0], (void*)hid_init);
}

TEST_F(HIDEnumeratorTests, ObjectCreationThrowsExceptionIfHIDInitReturnError){
    hid_init_fake.return_val = -1;
    EXPECT_THROW({
        try{
            HID::Enumerate DevcieEnumerate(0,0);
        }
        catch(const HID::InitException& e){
            std::cout << e.what() << std::endl;
            throw;
        }
    }, HID::InitException);
}

TEST_F(HIDEnumeratorTests, DestructorIsCalled){
    HID::Enumerate  *HeapEnum = new HID::Enumerate(0,0);
    delete HeapEnum;
    ASSERT_EQ(hid_exit_fake.call_count, 1);
} 

TEST_F(HIDEnumeratorTests, HIDEnumerateIsCalled){
    HID::Enumerate DeviceEnumeration;
    DeviceEnumeration.Devices();
    ASSERT_EQ(hid_enumerate_fake.call_count, 1);
} 

TEST_F(HIDEnumeratorTests, HIDEnumerateIsCalledWithDefaultZeroParameters){
    HID::Enumerate DeviceEnumeration;
    DeviceEnumeration.Devices();
    ASSERT_EQ(0, hid_enumerate_fake.arg0_history[0]);
    ASSERT_EQ(0, hid_enumerate_fake.arg1_history[0]);
}

TEST_F(HIDEnumeratorTests, HIDEnumerateIsCalledWithCorectParameters){
    HID::Enumerate DeviceEnumeration(VENDOR_ID, PRODUCT_ID);
    DeviceEnumeration.Devices();
    ASSERT_EQ(VENDOR_ID, hid_enumerate_fake.arg0_history[0]);
    ASSERT_EQ(PRODUCT_ID, hid_enumerate_fake.arg1_history[0]);
}

TEST_F(HIDEnumeratorTests, HIDEnumerateThrowsErrorIf){
    HID::Enumerate DeviceEnumeration(VENDOR_ID, PRODUCT_ID);
    DeviceEnumeration.Devices();
    ASSERT_EQ(VENDOR_ID, hid_enumerate_fake.arg0_history[0]);
    ASSERT_EQ(PRODUCT_ID, hid_enumerate_fake.arg1_history[0]);
}

