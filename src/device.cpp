#include <hid/Device.hpp>

HID::Device::Device(std::string& path): DeviceHandle(hid_open_path(path.c_str()))
{}

HID::Device::Device(unsigned short VENDOR_ID, unsigned short PRODUCT_ID, std::wstring serial_number):
DeviceHandle(hid_open(VENDOR_ID, PRODUCT_ID, serial_number.c_str()))
{}

HID::Device::~Device()
{
    hid_close(DeviceHandle);
}

int HID::Device::Write(std::vector<uint8_t>& data){
    if (data.empty())
        return data.size();
    return hid_write(this->DeviceHandle, data.data(), data.size());
}