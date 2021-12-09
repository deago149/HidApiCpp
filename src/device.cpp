#include <hid/device.hpp>

HID::Device::Device(hid_device_info* DeviceInfo):
path(DeviceInfo->path),
vendor_id(DeviceInfo->vendor_id),
product_id(DeviceInfo->product_id),
serial_number(DeviceInfo->serial_number),
release_number(DeviceInfo->release_number),
manufacturer_string(DeviceInfo->manufacturer_string),
product_string(DeviceInfo->product_string),
usage_page(DeviceInfo->usage_page),
usage(DeviceInfo->usage)
{
    
}