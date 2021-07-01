
# name of the executable
set(APP_NAME HelloTriangle)

# executable
add_executable(${APP_NAME} main.cpp)


set_target_properties(${APP_NAME}
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
        VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

# set include paths
target_include_directories(${APP_NAME}
    PRIVATE ${CMAKE_SOURCE_DIR}/AthenaEngine
)

target_link_libraries(${APP_NAME} PUBLIC AthenaEngine)
