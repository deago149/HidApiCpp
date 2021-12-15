#pragma once
#include <iostream>
#include <hidapi.h>
#include <hid/Device.hpp>

namespace HIDAPI{
    class Info{
        private:
            std::string path;
            unsigned short vendor_id;
            unsigned short product_id;
            std::wstring serial_number;
            unsigned short release_number;
            std::wstring manufacturer_string;
            std::wstring product_string;
            unsigned short usage_page;
            unsigned short usage;
        public:
            Device OpenPath();
            Device OpenSerial();
            Info(hid_device_info * DeviceInfo);
            ~Info() = default;
    };
} // namespace HID
