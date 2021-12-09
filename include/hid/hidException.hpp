#pragma once
#include <iostream>
#include <exception>
#include <hidapi.h>

namespace HID{
    
    class HIDException: public std::runtime_error{
        private:
            const char * Error;
        public:
            const char *what() const noexcept ;
            HIDException(const char *Message) noexcept;
            HIDException(std::string& Message) noexcept;
            ~HIDException() noexcept = default;
    };

    class InitException : public HIDException{
        private:
            std::string Message;
        public:
            const char* what() const noexcept;
            InitException(const char *Message) noexcept;
            InitException(std::string&  Message) noexcept;
            ~InitException() noexcept = default;
    };
};