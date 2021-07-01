# min cmake version req
cmake_minimum_required(VERSION 3.15)

#CMAKE_SOURCE_DIR = where the top level cmakelists.txt is located
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/output/bin) 

message(STATUS ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})
message(STATUS ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})
message(STATUS ${CMAKE_LIBRARY_OUTPUT_DIRECTORY})

# makes a better visual studio solution layout
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# solutino name for visual studio
set(SOL_NAME AthenaProject)

# version of engine
set(ENG_VER 1.0)

# sets PROJECT_SOURCE_DIR, PROJECT_BINARY_DIR, PROJECT_IS_TOP_LEVEL
project(${SOL_NAME} VERSION ${ENG_VER} LANGUAGES CXX)


# creates vs projects for all the different apps
add_subdirectory(Apps)

# creates static library for AthenaEngine
add_subdirectory(AthenaEngine)

set_directory_properties(PROPERTIES
    VS_STARTUP_PROJECT HelloTriangle
)
