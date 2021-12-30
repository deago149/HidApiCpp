#include "fff_hidapi.hpp"
//Fake Function Definitions
DEFINE_FAKE_VALUE_FUNC(hid_device*, hid_open_path, const char *);
DEFINE_FAKE_VALUE_FUNC(hid_device*, hid_open, unsigned short, unsigned short, const wchar_t *);
DEFINE_FAKE_VALUE_FUNC(int, hid_write, hid_device*, const unsigned char*, size_t);
DEFINE_FAKE_VOID_FUNC(hid_close, hid_device*);
DEFINE_FAKE_VALUE_FUNC( int, hid_init);
DEFINE_FAKE_VALUE_FUNC( int, hid_exit);
//Proxy Functions Definitions
int hid_write_return_length( hid_device *device, const unsigned char *data, size_t length){
    return length;
}


hid_device *hid_open_path_fake_device_return(const char * path){
    return (hid_device*)malloc(100);
}
