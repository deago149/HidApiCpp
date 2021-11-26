file(GLOB SOURCE_LIST CONFIGURE_DEPENDS *.cpp)
 add_executable(HIDcli ${SOURCE_LIST})
 target_link_libraries(HIDcli PUBLIC hidapiCPP CLI11::CLI11)