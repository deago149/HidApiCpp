#include <hid/API.hpp>

int HID::API::Init(){
    return hid_init();
}

int HID::API::Exit(){
    return hid_exit();
}

hid_device * HID::API::Open(std::string& Path){
    return hid_open_path(Path.c_str());
}

hid_device * HID::API::Open(unsigned short VendorID, unsigned short ProductID, std::wstring& serial_number){
    return hid_open(VendorID, ProductID, serial_number.c_str()); 
}