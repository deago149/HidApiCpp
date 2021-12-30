#pragma once
#include <fff.h>
#include <hidapi.h>
#include <cstdlib>

//Fake Function Declarations

DECLARE_FAKE_VALUE_FUNC( hid_device*, hid_open_path, const char * );
DECLARE_FAKE_VALUE_FUNC( hid_device*, hid_open, unsigned short, unsigned short, const wchar_t * );
DECLARE_FAKE_VALUE_FUNC( int, hid_write, hid_device* ,const unsigned char*, size_t);
DECLARE_FAKE_VALUE_FUNC( int, hid_init);
DECLARE_FAKE_VALUE_FUNC( int, hid_exit);
DECLARE_FAKE_VOID_FUNC( hid_close, hid_device*);
//Proxy Functions Declarations
int hid_write_return_length( hid_device *device, const unsigned char *data, size_t length);
hid_device *hid_open_path_fake_device_return(const char * path);