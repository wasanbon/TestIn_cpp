# TestIn CMake config file
#
# This file sets the following variables:
# TestIn_FOUND - Always TRUE.
# TestIn_INCLUDE_DIRS - Directories containing the TestIn include files.
# TestIn_IDL_DIRS - Directories containing the TestIn IDL files.
# TestIn_LIBRARIES - Libraries needed to use TestIn.
# TestIn_DEFINITIONS - Compiler flags for TestIn.
# TestIn_VERSION - The version of TestIn found.
# TestIn_VERSION_MAJOR - The major version of TestIn found.
# TestIn_VERSION_MINOR - The minor version of TestIn found.
# TestIn_VERSION_REVISION - The revision version of TestIn found.
# TestIn_VERSION_CANDIDATE - The candidate version of TestIn found.

message(STATUS "Found TestIn-1.0.0")
set(TestIn_FOUND TRUE)

find_package(<dependency> REQUIRED)

#set(TestIn_INCLUDE_DIRS
#    "/usr/local/include/testin-1"
#    ${<dependency>_INCLUDE_DIRS}
#    )
#
#set(TestIn_IDL_DIRS
#    "/usr/local/include/testin-1/idl")
set(TestIn_INCLUDE_DIRS
    "/usr/local/include/"
    ${<dependency>_INCLUDE_DIRS}
    )
set(TestIn_IDL_DIRS
    "/usr/local/include//idl")


if(WIN32)
    set(TestIn_LIBRARIES
        "/usr/local/components/lib/libtestin.a"
        ${<dependency>_LIBRARIES}
        )
else(WIN32)
    set(TestIn_LIBRARIES
        "/usr/local/components/lib/libtestin.dylib"
        ${<dependency>_LIBRARIES}
        )
endif(WIN32)

set(TestIn_DEFINITIONS ${<dependency>_DEFINITIONS})

set(TestIn_VERSION 1.0.0)
set(TestIn_VERSION_MAJOR 1)
set(TestIn_VERSION_MINOR 0)
set(TestIn_VERSION_REVISION 0)
set(TestIn_VERSION_CANDIDATE )

