#include <iostream>
#include <hid/enumerate.hpp>
int main(int argc, char const *argv[])
{
	HID::Enumerate hidDevices(0,0);
	return 0;
}
