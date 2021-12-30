#pragma once
#include <iostream>
#include <vector>
#include <hidapi.h>

namespace HID{
        struct API {
            static int Init();
            static int Exit();
            //Open
            static hid_device * Open(std::string& Path);
            static hid_device * Open(unsigned short VENDOR_ID, unsigned short PRODUCT_ID, std::wstring& serial_number);
            //Write
            static int Write(hid_device *dev, std::vector<uint8_t> data);
            //Read
            static std::vector<uint8_t> Read(hid_device_info *dev);
            static std::vector<uint8_t> Read(hid_device_info *dev, int milliseconds);

            static int SetNonBlocking(hid_device *device, int NonBlocking);
            //Send Features
            static int SendFeatureReport(hid_device *device, std::vector<uint8_t> data);
            //Get Features
            static std::vector<uint8_t> GetFeatureReport(hid_device *device);
            static std::vector<uint8_t> GetInputReport(hid_device *device);
            static std::wstring GetManufacturerString(hid_device *device);
            static std::wstring GetProductString(hid_device *device);
            static std::wstring GetSerialNumberString(hid_device *device);
            static std::wstring GetIndexedString(hid_device *device);
            //Enumerate
            static std::vector<hid_device_info> Enumerate(unsigned short VENDOR_ID, unsigned short PRODUCT_ID);
            static void FreeEnumerate(hid_device_info *device_list);
            static void Close(hid_device *device);
            //Error
            static std::wstring Error(hid_device *device);
            // Version
            static hid_api_version Version();
            static std::string VersionString();
    };
};