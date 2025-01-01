cmake_minimum_required(VERSION 3.24.2)

project(Test)

enable_testing()

find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Test)


add_executable(ftp_test  test_main.cpp)



target_link_libraries(ftp_test PUBLIC ftp_lib  Qt${QT_VERSION_MAJOR}::Test)
add_test(NAME first_test COMMAND qtest)
