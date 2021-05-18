cmake_minimum_required(VERSION 3.17)
project(cpp_lab)

set(CMAKE_CXX_STANDARD 11)

add_executable(cpp_lab  main2.cpp lab_support.cpp
        employer.cpp   out_data.cpp
        professor.cpp Student.cpp AbstractReader.cpp
        CSVReader.cpp JSONReader.cpp
        lab.h
        employer.h

        professor.h
        Student.h
        out_data.h Empl.cpp Empl.h)