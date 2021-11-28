#include <iostream>
#include <hidapi.h>
int main(int argc, char const *argv[])
{
    struct hid_device_info *devs, *cur_dev;
    devs = hid_enumerate(0x55, 0x7);
	cur_dev = devs;
	while (cur_dev) {
		printf("Device Found\n  type: %04hx %04hx\n  path: %s\n  serial_number: %ls", cur_dev->vendor_id, cur_dev->product_id, cur_dev->path, cur_dev->serial_number);
		printf("\n");
		printf("  Manufacturer: %ls\n", cur_dev->manufacturer_string);
		printf("  Product:      %ls\n", cur_dev->product_string);
		printf("  Release:      %hx\n", cur_dev->release_number);
		printf("  Interface:    %d\n",  cur_dev->interface_number);
		printf("  Usage (page): 0x%hx (0x%hx)\n", cur_dev->usage, cur_dev->usage_page);
		printf("\n");
		cur_dev = cur_dev->next;
	}
	hid_free_enumeration(devs);
    if(devs == NULL)
        printf("Error: %ls\n", hid_error(NULL));
    std::cout << "HID!!" << std::endl;
    return 0;
}
