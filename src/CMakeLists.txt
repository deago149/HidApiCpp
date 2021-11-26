# Note that headers are optional, and do not affect add_library, but they will not
 # show up in IDEs unless they are listed in add_library.
 # Optionally glob, but only for CMake 3.12 or later:
 file(GLOB HEADER_LIST_API CONFIGURE_DEPENDS include/hidapipp/*.hpp)
 file(GLOB HEADER_LIST CONFIGURE_DEPENDS ${PROJECT_SOURCE_DIR}/include/**/*.hpp)
 file(GLOB VERSION_LIST CONFIGURE_DEPENDS include/Version/*.hpp)
 file(GLOB SOURCE_LIST CONFIGURE_DEPENDS *.cpp)
#set(HEADER_LIST "${ModernCMakeExample_SOURCE_DIR}/include/modern/lib.hpp")
# Make an automatic library - will be static or dynamic based on user setting
add_library(${PROJECT_NAME} ${SOURCE_LIST} ${HEADER_LIST}  ${VERSION_LIST})
# We need this directory, and users of our library will need it too
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)
# This depends on (header only) boost
target_link_libraries(${PROJECT_NAME} PUBLIC hidapi::hidapi)
# All users of this library will need at least C++11
#target_compile_features(${LIB_NAME})
# IDEs should put the headers in a nice place
source_group(
  TREE "${PROJECT_SOURCE_DIR}/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST}
)