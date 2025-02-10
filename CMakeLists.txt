cmake_minimum_required(VERSION 3.25)
project(attentionsim)
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_CXX_STANDARD 20)
find_package(PkgConfig REQUIRED)
pkg_get_variable(WaylandProtocolsDataDir wayland-protocols pkgdatadir)
find_package(Qt6 COMPONENTS REQUIRED Widgets WaylandClient)
add_executable(attentionsim
    mainwindow.h
    mainwindow.cpp
    xdgactivationv1.h
    xdgactivationv1.cpp
    main.cpp)
qt_generate_wayland_protocol_client_sources(attentionsim
    FILES ${WaylandProtocolsDataDir}/staging/xdg-activation/xdg-activation-v1.xml
)
target_link_libraries(attentionsim PRIVATE
    Qt6::Widgets
    Qt6::GuiPrivate
    Qt6::WaylandClient
    Qt6::WaylandClientPrivate
)
