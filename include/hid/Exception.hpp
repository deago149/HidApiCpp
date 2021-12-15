#pragma once
#include <iostream>
#include <exception>
#include <hidapi.h>

namespace HIDAPI{
    
    class Exception: public std::runtime_error{
        private:
            const char * Error;
        public:
            const char *what() const noexcept ;
            Exception(const char *Message) noexcept;
            Exception(std::string& Message) noexcept;
            ~Exception() noexcept = default;
    };

    class InitException : public HIDAPI::Exception{
        private:
            std::string Message;
        public:
            const char* what() const noexcept;
            InitException(const char *Message) noexcept;
            InitException(std::string&  Message) noexcept;
            ~InitException() noexcept = default;
    };
};