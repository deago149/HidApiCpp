#pragma once
#include <vector>
#include <iostream>
#include <gtest/gtest.h>
#include <hid/API.hpp>
#include "fff_hidapi.hpp"

DEFINE_FFF_GLOBALS;

class APIInitTests : public::testing::Test{
    public:
        APIInitTests(){};
        ~APIInitTests(){
            RESET_FAKE(hid_init);
        };
};

TEST_F(APIInitTests, InitCanBeCalled){
    HID::API::Init();
}

TEST_F(APIInitTests, HidInitIsCalled){
    HID::API::Init();
    ASSERT_EQ(hid_init_fake.call_count, 1);
}

TEST_F(APIInitTests, HidInitIsRetrunsZero){
    int Result = HID::API::Init();
    int Expected = 0;
    ASSERT_EQ(Result, Expected);
}

TEST_F(APIInitTests, HidInitIsRetrunsOne){
    hid_init_fake.return_val = 1;
    int Result = HID::API::Init();
    int Expected = 1;
    ASSERT_EQ(Result, Expected);
}

class APIExitTests : public::testing::Test{
    public:
        APIExitTests(){};
        ~APIExitTests(){
            RESET_FAKE(hid_exit);
        };
};

TEST_F(APIExitTests, ExitCanBeCalled){
    HID::API::Exit();
}

TEST_F(APIExitTests, HidExitIsCalled){
    HID::API::Exit();
    ASSERT_EQ(hid_exit_fake.call_count, 1);
}

TEST_F(APIExitTests, HidExitReturnZero){
    int Result = HID::API::Exit();
    int Expected = 0;
    ASSERT_EQ(Result, Expected);
}

TEST_F(APIExitTests, HidExitReturnOne){
    hid_exit_fake.return_val = 1;
    int Result = HID::API::Exit();
    int Expected = 1;
    ASSERT_EQ(Result, Expected);
}

class APIOpenPathTests : public::testing::Test {
    public:
        std::string emptyString;
        std::string Path = "ThisIsThePath";
        APIOpenPathTests(){};
        ~APIOpenPathTests(){
            RESET_FAKE(hid_open_path);
        };

};

TEST_F(APIOpenPathTests, CanCallOpen){
    HID::API::Open(Path);
}

TEST_F(APIOpenPathTests, CanCallHidOpenViaPath){
    HID::API::Open(Path);
    ASSERT_EQ(hid_open_path_fake.call_count, 1);
}

TEST_F(APIOpenPathTests, ReturnDeviceDoesNotEqualNullPtr){
    hid_open_path_fake.custom_fake = hid_open_path_fake_device_return;
    hid_device *ResultDevice = HID::API::Open(Path);
    ASSERT_TRUE(ResultDevice != nullptr);
}

TEST_F(APIOpenPathTests, ArgIsEqualToValueOfFirstParam){
    HID::API::Open(Path);
    ASSERT_TRUE(Path.c_str() == hid_open_path_fake.arg0_val);
}

TEST_F(APIOpenPathTests, ResultIsEqualToResultOfFunctionCall){
    hid_open_path_fake.custom_fake = hid_open_path_fake_device_return;
    hid_device *ResultDevice = HID::API::Open(Path);
    ASSERT_TRUE(ResultDevice == hid_open_path_fake.return_val_history[0]);
}

class APIOpenTests : public::testing::Test{
    public:
        unsigned short vid = 0x909;
        unsigned short pid = 0x4042;
        std::wstring emptyWString;
        APIOpenTests(){};
        ~APIOpenTests(){
            RESET_FAKE(hid_open);
        };
};

TEST_F(APIOpenTests, CanCallOpen){
    HID::API::Open(vid, pid, emptyWString);
}

TEST_F(APIOpenTests, CallsHidOpen){
    HID::API::Open(vid, pid, emptyWString);
    ASSERT_EQ(hid_open_fake.call_count, 1);
}

TEST_F(APIOpenTests, CallsHidOpenWithCorrectParmeterArguments){
    HID::API::Open(vid, pid, emptyWString);
    ASSERT_EQ(hid_open_fake.arg0_val, vid);
    ASSERT_EQ(hid_open_fake.arg1_val, pid);
    ASSERT_EQ(hid_open_fake.arg2_val, emptyWString.c_str());
}

TEST_F(APIOpenTests, ReturnValueEqualsHidOPenReturnVal){
    hid_device *ResultDevice = HID::API::Open(vid, pid, emptyWString);
    ASSERT_TRUE(ResultDevice == hid_open_fake.return_val_history[0]);
}

TEST_F(APIOpenTests, CallingWithEmptySerialNumberThrowsException){
    EXPECT_THROW(
        {
            try{
                HID::API::Open(vid, pid, emptyWString);
            }catch(const MyException& e ){
                EXPECT_STREQ( "Cucumber overflow", e.what() );
                throw;
            }
        },);
}
