#pragma once
#include <iostream>
#include <vector>
#include <hidapi.h>
#include <hid/Device.hpp>
#include <hid/Exception.hpp>
namespace HIDAPI{
    class HID{
        private:

        public:
            HID();
            ~HID();
            std::string CheckError(HIDAPI::Device);
            std::vector<HIDAPI::Device> Device_List(unsigned short VENDOR_ID, unsigned short PRODUCT_ID);
    };
};
