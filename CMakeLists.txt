cmake_minimum_required(VERSION 3.21)

project(attentionsim
    LANGUAGES CXX C
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 11)
find_package(ECM REQUIRED NO_MODULE)
list(APPEND CMAKE_MODULE_PATH ${ECM_MODULE_PATH})

find_package(PkgConfig REQUIRED)
find_package(QtWaylandScanner REQUIRED)
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS REQUIRED Widgets WaylandClient)
pkg_check_modules(WaylandClient IMPORTED_TARGET wayland-client)
pkg_get_variable(WaylandProtocolsDataDir wayland-protocols pkgdatadir)

ecm_add_qtwayland_client_protocol(XDG_ACTIVATION_SOURCES
    PROTOCOL ${WaylandProtocolsDataDir}/staging/xdg-activation/xdg-activation-v1.xml
    BASENAME xdg-activation-v1
)

add_executable(attentionsim
    ${XDG_ACTIVATION_SOURCES}
    mainwindow.h
    mainwindow.cpp
    xdgactivationv1.h
    xdgactivationv1.cpp
    main.cpp
)

target_link_libraries(attentionsim PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Qt${QT_VERSION_MAJOR}::GuiPrivate
    Qt${QT_VERSION_MAJOR}::WaylandClient
    Qt${QT_VERSION_MAJOR}::WaylandClientPrivate
    PkgConfig::WaylandClient
)
