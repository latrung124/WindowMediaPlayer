cmake_minimum_required(VERSION 3.16)

project(WindowMediaPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick)

qt_standard_project_setup(REQUIRES 6.5)

set(CONTROLLER_SOURCES
    Controller/ModuleController.cpp
    Controller/ModuleController.h
)

set(UTILS_SOURCES
    Utils/ModuleUtility.h
)

qt_add_executable(appWindowMediaPlayer
    main.cpp
    ${CONTROLLER_SOURCES}
    ${UTILS_SOURCES}
)

set(QmlComponent
    QmlComponent/WindowControl.qml)

foreach(QmlComponent ${component})
    get_filename_component(component_name ${component} NAME)
    set_source_file_properties(${component} PROPERTIES QT_RESOURCE_ALIAS ${component_name})
endforeach()

set_source_files_properties(Main.qml
    PROPERTIES
        QT_QML_SINGLETON_TYPE true
)

qt_add_qml_module(appWindowMediaPlayer
    URI WindowMediaPlayer
    VERSION 1.0
    QML_FILES
        Main.qml
        QmlComponent/WindowControl.qml
    RESOURCES
        "QmlComponent/Resources/minimize-button.png"
        "QmlComponent/Resources/maximize-button.png"
        "QmlComponent/Resources/close-button.png"
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appWindowMediaPlayer PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appWindowMediaPlayer
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

target_include_directories(appWindowMediaPlayer
    PRIVATE
        Controller
)

target_link_libraries(appWindowMediaPlayer
    PRIVATE Qt6::Quick
)

include(GNUInstallDirs)
install(TARGETS appWindowMediaPlayer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
