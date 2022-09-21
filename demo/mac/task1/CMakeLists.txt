cmake_minimum_required(VERSION 3.0)
project(template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE ${PROJECT_NAME}_Headers include/*.h include/*.hpp)
file(GLOB_RECURSE ${PROJECT_NAME}_Sources source/*.cpp source/*.c source/*.hpp)



add_executable(${PROJECT_NAME}_executable ${${PROJECT_NAME}_Headers} ${${PROJECT_NAME}_Sources})

target_include_directories(${PROJECT_NAME}_executable PUBLIC include)



