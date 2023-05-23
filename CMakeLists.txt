cmake_minimum_required(VERSION 3.5)

project(ProyectoED2 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cpp
        node.h
        AVL.h
        AVL.cpp
        AVL_Thread.h
        AVL_Thread.cpp
        HEAP.h
        HEAP.cpp
        HEAP_thread.h
        HEAP_thread.cpp
        ABB.h
        ABB.cpp
        ABB_thread.h
        ABB_thread.cpp
        ARJ.h
        tablero.h
        tablero.cpp
        plagaThread.cpp
        plagaThread.h
        ARJ.cpp
        ARJ_thread.h
        ARJ_thread.cpp
        granjero.h
        granjero.cpp
        gamewindow.cpp
        gamewindow.h
        gamewindow.ui
        mainwindow.cpp
        mainwindow.h
        mainwindow.ui
        mercado.cpp
        mercado.h
        mercado.ui
)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(ProyectoED2
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET ProyectoED2 APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(ProyectoED2 SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(ProyectoED2
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(ProyectoED2 PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)

set_target_properties(ProyectoED2 PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

install(TARGETS ProyectoED2
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(ProyectoED2)
endif()
