cmake_minimum_required(VERSION 3.24.2)

project(ftpwifi VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


find_package(QT NAMES Qt6          REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)
find_package(Qt6 REQUIRED COMPONENTS Network)

include_directories("./include")


set(PROJECT_HEADERS
    include/main/mainwindow.h


    include/file/ifilereader.h


    include/file/filereader.h
    include/file/filemanager.h
    include/file/abstractparsingfileinfo.h
    include/file/parsingfileinfo.h
    include/file/filemetadatacreate.h
    include/file/filemetadataparse.h



    include/load/iload.h
    include/load/dataloadmanager.h
    include/load/load.h


    include/net/iserver.h
    include/net/tcpserver.h


    include/net/idatasender.h
    include/net/datasender.h

    include/net/idatareceiver.h
    include/net/datareceiver.h




)
set(PROJECT_SOURCES
    src/main/main.cpp
    src/main/mainwindow.cpp

    src/file/filereader.cpp
    src/file/filemanager.cpp
    src/file/parsingfileinfo.cpp
    src/file/filemetadatacreate.cpp
    src/file/filemetadataparse.cpp



    src/load/dataloadmanager.cpp
    src/load/load.cpp


    src/net/datasender.cpp
    src/net/datareceiver.cpp
    src/net/tcpserver.cpp




)
set(PROJECT_UI  
    src/main/mainwindow.ui
)
add_library(ftp_lib     
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
    ${PROJECT_UI}
)

target_link_directories(ftp_lib PUBLIC  ./include)
target_link_libraries  (ftp_lib PUBLIC  Qt${QT_VERSION_MAJOR}::Widgets )
target_link_libraries  (ftp_lib PUBLIC  Qt${QT_VERSION_MAJOR}::Network )




set_target_properties(ftp_lib PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS ftp_lib
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})



set(TEST_VAR TRUE)
if(NOT TEST_VAR)
qt_add_executable(ftpwifi
        MANUAL_FINALIZATION
        src/main/main.cpp
    )
target_link_libraries(ftpwifi PRIVATE  ftp_lib)
qt_finalize_executable(ftpwifi)
else()
add_subdirectory("./test")
endif()
