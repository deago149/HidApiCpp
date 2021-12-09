#include "HIDDeviceTests.hpp"
#include "HIDEnumerateTests.hpp"
#include "HIDOpenDeviceTests.hpp"


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
