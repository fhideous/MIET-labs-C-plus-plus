cmake_minimum_required(VERSION 3.17)
project(cpp_lab)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_lab  src/main.cpp src/lab_support.cpp
        src/employer.cpp  src/employers.cpp src/out_data.cpp
        hdrs/lab.h
        hdrs/employer.h
        hdrs/employers.h hdrs/out_data.h)