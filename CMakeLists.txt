cmake_minimum_required(VERSION 4.1.1)
project(ProceduralAnimation)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_BUILD_TYPE Debug)

include(cmake/raylib-cpp.cmake)
include(cmake/json.cmake)
include(cmake/rlimgui.cmake)
include(cmake/imgui.cmake)

set(SOURCES 
    src/main.cpp   
    src/Test_Circle.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "/home/bodie/DeveloperStuff/Tests/RaylibCpp"    
)

target_link_libraries(${PROJECT_NAME} 
    raylib 
    raylib_cpp 
    rlimgui 
    nlohmann_json::nlohmann_json
    imgui
)