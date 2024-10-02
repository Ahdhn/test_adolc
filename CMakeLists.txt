# Set CMake version
cmake_minimum_required(VERSION 3.14)

# Set project name
set(project_name "adolc_minimal_working_example")
project(${project_name})

# Set path to header files directories
include_directories("/usr/local/include/")

# Set path to executable directories
link_directories("/usr/local/lib/")

# Add source files to compile to the project
add_executable(${project_name} main.cpp)

# Add external libraries
target_link_libraries(${project_name} -ladolc)