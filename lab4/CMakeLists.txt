cmake_minimum_required(VERSION 3.17)
project(cpp_lab4)

set(CMAKE_CXX_STANDARD 14)
#find_package(nlohmann_json 3.2.0 REQUIRED)

add_executable(
        cpp_lab4  main2.cpp lab_support.cpp
        AbstractReader.cpp CSVReader.cpp JSONReader.cpp
        Employer.cpp
        Employer.h lab.h
        AbstractReader.h CSVReader.h JSONReader.h
        )

#target_link_libraries(cpp_lab4 PRIVATE nlohmann_json::nlohmann_json)