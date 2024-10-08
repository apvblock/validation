cmake_minimum_required(VERSION 3.10)

# Project name
project(SimpleBlockchain)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Find and link OpenSSL (for SHA-256 hashing)
find_package(OpenSSL REQUIRED)

# Add the executable
add_executable(SimpleBlockchain main.cpp)

# Link OpenSSL libraries
target_link_libraries(SimpleBlockchain OpenSSL::SSL OpenSSL::Crypto)
