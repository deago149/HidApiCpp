#pragma once
#include <iostream>
#include <exception>
#include <hid/Exception.hpp>

namespace HID{
    
    class Exception: public std::runtime_error{
        private:
            const char * Error;
        public:
            const char *what() const noexcept ;
            Exception(const char *Message) noexcept;
            Exception(std::string& Message) noexcept;
            ~Exception() noexcept = default;
    };
};