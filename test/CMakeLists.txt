cmake_minimum_required(VERSION 3.24.2)

project(Test)

enable_testing()

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)
add_executable(ftp_test
main.cpp
file_test.h
load_test.h



)
target_link_libraries(ftp_test PUBLIC  ftp_lib Qt${QT_VERSION_MAJOR}::Test)
add_test(NAME FileTest  COMMAND FileTest_1)

