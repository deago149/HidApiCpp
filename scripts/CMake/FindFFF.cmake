# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
 # file Copyright.txt or https://cmake.org/licensing for details.
 #[=======================================================================[.rst:
 FindFFF
 -------
 Finds the Fake Function Framework library.
 Imported Targets
 ^^^^^^^^^^^^^^^^
 This module provides the following imported targets, if found:
 ``Fake Function Framework``
   The Fake Function Framework library
 Result Variables
 ^^^^^^^^^^^^^^^^
 //Not Applicable 
 This will define the following variables:
 ``Foo_FOUND``
   True if the system has the Foo library.
 ``Foo_VERSION``
   The version of the Foo library which was found.
 ``Foo_INCLUDE_DIRS``
   Include directories needed to use Foo.
 ``Foo_LIBRARIES``
   Libraries needed to link to Foo.
 Cache Variables
 ^^^^^^^^^^^^^^^
 The following cache variables may also be set:
 ``Foo_INCLUDE_DIR``
   The directory containing ``foo.h``.
 ``Foo_LIBRARY``
   The path to the Foo library.
 #]=======================================================================]
set(FFF_SOURCE_DIR ${PROJECT_SOURCE_DIR}/extern/FFF)

find_path(FFF_INCLUDE NAMES fff.h PATHS ${FFF_SOURCE_DIR})

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(FFF
   FOUND_VAR FFF_FOUND
   REQUIRED_VARS
     FFF_INCLUDE
   VERSION_VAR 1.0
)

 message("INCLIDE FOR FFFF" ${FFF_INCLUDE})

 if(FFF_FOUND AND NOT TARGET FFF)
  message("Found FFF")
    MESSAGE("Removing Internal GTest Dir")
    EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E "make_directory" - "${PROJECT_SOURCE_DIR}/extern/FFF/include")
    EXECUTE_PROCESS(COMMAND ${CMAKE_COMMAND} -E "copy" - "${PROJECT_SOURCE_DIR}/extern/FFF/fff.h" "${PROJECT_SOURCE_DIR}/extern/FFF/include")

     add_library(FFF INTERFACE ${FFF_INCLUDE}/include/fff.h)
     target_include_directories(FFF INTERFACE ${FFF_INCLUDE}/include)
 endif()