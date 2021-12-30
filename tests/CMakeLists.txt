
file(GLOB SOURCE_LIST CONFIGURE_DEPENDS *.c)
file(GLOB HEADER_LIST CONFIGURE_DEPENDS *.h)
file(GLOB SOURCE_LIST_PP CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/tests/*.cpp)
file(GLOB HEADER_LIST_PP CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/tests/*.hpp)
add_executable(RunHIDCPPTests ${HEADER_LIST} ${SOURCE_LIST} ${SOURCE_LIST_PP} ${HEADER_LIST_PP})
target_link_libraries(RunHIDCPPTests FFF hidapiCPP GTest::gmock GTest::gtest GTest::gmock_main GTest::gtest_main )
add_test(HIDTests RunHIDCPPTests)