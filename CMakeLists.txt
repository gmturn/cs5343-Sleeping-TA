cmake_minimum_required(VERSION 3.10)

project(SleepingTA VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(models)

# Binary execution files will be made in /bin
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# Find the Threads package (which includes pthreads on UNIX-like systems)
find_package(Threads REQUIRED)

add_library(student src/student.cpp)
add_library(ta src/ta.cpp)

# Main program executable
add_executable(SleepingTA main.cpp)
target_link_libraries(SleepingTA student ta)

# If your program or any of the libraries use threads, link them with pthreads
target_link_libraries(SleepingTA Threads::Threads) # Link pthreads to your main executable



set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")