
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS *.cpp)
file(GLOB HEADER_LIST CONFIGURE_DEPENDS *.hpp)
add_executable(RunHIDCPPTests ${HEADER_LIST} ${SOURCE_LIST})
target_link_libraries(RunHIDCPPTests FFF hidapiCPP GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main )
add_test(HIDTests RunHIDCPPTests)