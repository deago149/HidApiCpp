#pragma once
#include <iostream>
#include <exception>
#include <hidapi.h>
class HIDException : public std::exception
{
private:
     const char *Message;
     const char *HidError;
     hid_device *HIDError_Device;
public:
    const char* what() const throw();
    const char* hid_error() const throw();
    HIDException(hid_device *Error_Device, std::string message);
    HIDException(hid_device *Error_Device, const char* message);
};


