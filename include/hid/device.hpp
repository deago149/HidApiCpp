#pragma once
#include <vector>
#include <iostream>
#include <hidapi.h>

namespace HID{
    class Device{
        private:
            hid_device *HIDDevice;
        public:
            Device(std::string path);
            Device(unsigned short VENDOR_ID, unsigned short PRODUCT_ID, std::wstring serial_number);
            ~Device();
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