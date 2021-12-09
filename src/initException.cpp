#include <hid/hidException.hpp>


HID::InitException::InitException(const char *Message) noexcept: HIDException(Message)
{
}

HID::InitException::InitException(std::string& Message) noexcept: HIDException(Message)
{
}


const char* HID::InitException::what() const noexcept{
    return "Inits";
}