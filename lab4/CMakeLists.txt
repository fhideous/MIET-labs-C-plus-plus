cmake_minimum_required(VERSION 3.17)
project(cpp_lab4)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpp_lab4  main2.cpp lab_support.cpp
        AbstractReader.cpp CSVReader.cpp JSONReader.cpp
        Employer.cpp
        Employer.h lab.h
        AbstractReader.h CSVReader.h JSONReader.h
         )