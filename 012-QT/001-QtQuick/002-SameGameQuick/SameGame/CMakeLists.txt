cmake_minimum_required(VERSION 3.16)

project(SameGame VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Qml Quick)

qt_standard_project_setup(REQUIRES 6.5)

qt_add_executable(appSameGame
    main.cpp
)

qt_add_qml_module(appSameGame
    URI SameGame
    VERSION 1.0
    QML_FILES Main.qml Block.qml Button.qml SameGame.js Dialog.qml

    RESOURCES "pics/background.jpg" "pics/redStone.png" "pics/blueStar.png" "pics/blueStone.png" "pics/greenStar.png" "pics/redStar.png" "pics/redStone.png"
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appSameGame PROPERTIES

    # MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appSameGame
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_link_libraries(appSameGame
    PRIVATE Qt6::Quick
    PRIVATE Qt6::Core
    PRIVATE Qt6::Gui
    PRIVATE Qt6::Qml
)

include(GNUInstallDirs)
install(TARGETS appSameGame
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
