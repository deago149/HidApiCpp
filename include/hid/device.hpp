#pragma once
#include <vector>
#include <iostream>
#include <hidapi.h>

namespace HID{

    class Device{
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
            Device(hid_device_info * DeviceInfo);
            ~Device() = default;
    };

    class OpenDevice{
        private:
            hid_device *Device;
        public:
            OpenDevice(std::string path);
            OpenDevice(unsigned short VENDOR_ID, unsigned short PRODUCT_ID, std::wstring serial_number);
            ~OpenDevice();
            void Write(std::vector<uint8_t> data);
            std::vector<uint8_t> Read();
            std::vector<uint8_t> ReadTimeout(size_t milliseconds);
            void NonBlocking(int nonblocking);
            void SendFeatureReport(std::string data);
            std::string GetFeatureReport();
            std::string GetInputReport();
            std::wstring GetManufacturerString();
            std::wstring GetProductString();
            std::wstring GetSerialNumberString();
            std::wstring GetIndexString();
    };
};