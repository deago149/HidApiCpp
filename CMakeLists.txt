cmake_minimum_required (VERSION 3.15...3.20)
project(
    hidapiCPP
    LANGUAGES CXX
    VERSION 0.0.1
    DESCRIPTION "C++ Header Only Wrpper Library For hidapi"
)

#Configuration And Version Number
configure_file (
    include/Version/Version.hpp.in
    include/Version/Version.hpp
)
#Enable Testing
include(CTest) # note: this adds a BUILD_TESTING which defaults to ON

#Append Scripts To Seach Path 
list(APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/scripts/CMake)

#Check For Git And Doxygen
find_package(Git REQUIRED)     # Git
find_package(Doxygen QUIET)    # Doxygen

#Includes
#Submodule Macro
include(scripts/CMake/PullSubmoduleMacro.cmake)
#Add vcpkg
include(extern/vcpkg/scripts/buildsystems/vcpkg.cmake)

#Pull Submodules
PullSubmodules()



#add SubProjects
add_subdirectory(extern/hidapi)
#find Libraries
find_package(GTest CONFIG REQUIRED)
find_package(CLI11 CONFIG REQUIRED)
find_package(FFF REQUIRED)
#add Source & App
add_subdirectory(src)
add_subdirectory(app)
#add Tests if Build
if(BUILD_TESTING)
    add_subdirectory(tests)
endif()