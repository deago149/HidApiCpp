#include <hid/HID.hpp>


HIDAPI::HID::HID(){
    if(hid_init() != 0)
        throw HIDAPI::InitException("Unable To Init HIDAPI"); 
}

HIDAPI::HID::~HID(){
    if(hid_exit() != 0)
        std::cout << "Failure To Close HID" << std::endl;
}

std::vector<HIDAPI::Device> HIDAPI::HID::Device_List(unsigned short VENDOR_ID, unsigned short PRODUCT_ID){
    //hid_enumerate(_Vendor_ID, _Product_ID);
}

std::string HIDAPI::HID::CheckError(HIDAPI::Device){

}
