project(AtfGuiCore)

find_package(Qt6 COMPONENTS Core Gui Xml Widgets QuickControls2 Quick Qml REQUIRED)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_executable(${PROJECT_NAME}
    Src/Widgets/MainWindow.cpp
    Src/Widgets/MainWindow.h
    Src/Main.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)
