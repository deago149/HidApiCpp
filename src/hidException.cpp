#include <hid/hidException.hpp>


HID::HIDException::HIDException(const char *Message) noexcept: std::runtime_error(Message) {

}

HID::HIDException::HIDException(std::string& Message) noexcept: std::runtime_error(Message) {

}

const char *HID::HIDException::what() const noexcept {
    runtime_error::what();
}