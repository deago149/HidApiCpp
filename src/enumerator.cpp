#include <hid/enumerate.hpp>
#include <hid/hidException.hpp>

HID::Enumerate::Enumerate(){
    if(hid_init() != 0)
        throw HID::InitException("Unable To Init HIDAPI"); 
}

HID::Enumerate::Enumerate(unsigned short Vendor_ID, unsigned short Product_ID){
    if(hid_init() != 0)
        throw HID::InitException("Unable To Init HIDAPI"); 
    _Vendor_ID = Vendor_ID;
    _Product_ID = Product_ID;  
}

HID::Enumerate::~Enumerate(){
    if(hid_exit() != 0)
        std::cout << "Failure To Close HID" << std::endl;
    //if(Device_List)
    //    hid_free_enumeration(Device_List);
}

void HID::Enumerate::Devices(){
    hid_enumerate(_Vendor_ID, _Product_ID);
}