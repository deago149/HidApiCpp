#pragma once
#include <iostream>
#include <vector>
#include <hidapi.h>
#include <hid/Device.hpp>

namespace HID{
    class Enumerate{
        private:
            unsigned short _Vendor_ID = 0x0;
            unsigned short _Product_ID = 0x0;
            //hid_device_info *Device_List = nullptr;
        public:
        //  std::string CheckError();
            std::vector<HID::Device> Devices();
            Enumerate();
            Enumerate(unsigned short Vendor_ID, unsigned short Product_ID);
            ~Enumerate();
    };
};
