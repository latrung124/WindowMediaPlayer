cmake_minimum_required(VERSION 3.16)

project(WindowMediaPlayer VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 6.5 REQUIRED COMPONENTS Quick Core5Compat)

qt_standard_project_setup(REQUIRES 6.5)

add_definitions(-DWMEDIA_SERVICE_LIBRARY_EXPORTS)
add_definitions(-DSERVICE_FACTORY_LIBRARY_EXPORTS)

add_subdirectory(Service/WindowMediaService)
add_subdirectory(Service/ServiceFactory)

set(CONTROLLER_SOURCES
    Controller/ModuleController.cpp
    Controller/WindowController.cpp
    Controller/ServiceController.cpp

    Controller/ModuleController.h
    Controller/WindowController.h
    Controller/ServiceController.h
)

set(MODEL_SOURCES
    Model/MediaModule/MediaPlayerModel.cpp
    Model/MediaModule/MediaPlayerModel.h
)

set(UTILS_SOURCES
    Utils/ThreadGuard.h
    Utils/ModuleUtility.h
    Utils/ServiceUtility.h
)

set (WINDOWMEDIASERVICELISTENER_SOURCES
    ServiceHandler/BaseHandler.h
    ServiceHandler/WindowMediaServiceHandler.h
    ServiceHandler/WindowMediaServiceHandler.cpp

    ServiceHandler/ServiceListener/WindowMediaService/WindowMediaServiceListener.h
    ServiceHandler/ServiceListener/WindowMediaService/WindowMediaServiceListener.cpp

    ServiceHandler/ServiceConsumer/BaseServiceConsumer.h
    ServiceHandler/ServiceConsumer/WindowMediaService/WindowMediaServiceConsumer.h
    ServiceHandler/ServiceConsumer/WindowMediaService/WindowMediaServiceConsumer.cpp

    ServiceHandler/ServiceMessage/BaseServiceMessage.h
    ServiceHandler/ServiceMessage/ServiceMessageId.h
    ServiceHandler/ServiceMessage/WindowMediaService/WMediaInfoMessage.h
    ServiceHandler/ServiceMessage/WindowMediaService/WMediaInfoMessage.cpp
    ServiceHandler/ServiceMessage/WindowMediaService/WPlaybackControlsMessage.h
    ServiceHandler/ServiceMessage/WindowMediaService/WPlaybackControlsMessage.cpp
    ServiceHandler/ServiceMessage/WindowMediaService/WPlaybackInfoMessage.h
    ServiceHandler/ServiceMessage/WindowMediaService/WPlaybackInfoMessage.cpp
    ServiceHandler/ServiceMessage/WindowMediaService/WTimelinePropertiesMessage.h
    ServiceHandler/ServiceMessage/WindowMediaService/WTimelinePropertiesMessage.cpp
)

set (SERVICELISTENER_SOURCES
    ${WINDOWMEDIASERVICELISTENER_SOURCES}
)

set (WINDOW_MEDIA_SERVICE_HEADERS
    Interface/WindowMediaService/WindowServiceUtils.h
    Interface/WindowMediaService/IWindowMediaService.h
    Interface/WindowMediaService/IWindowMediaServiceListener.h
)

set (INTERFACE_HEADERS
    Interface/Definitions.h
    Interface/IService.h
    Interface/IServiceListener.h
    Interface/IServiceFactory.h
    ${WINDOW_MEDIA_SERVICE_HEADERS}
)

qt_add_executable(appWindowMediaPlayer
    main.cpp
    ${CONTROLLER_SOURCES}
    ${MODEL_SOURCES}
    ${UTILS_SOURCES}
    ${INTERFACE_HEADERS}
    ${SERVICELISTENER_SOURCES}
)

set(QmlComponent
    QmlComponent/WindowControl.qml
    QmlComponent/MainContent.qml
    QmlComponent/BottomMediaPlayer.qml
    QmlComponent/MediaControl.qml

    QmlComponent/CustomButton.qml
    QmlComponent/CustomButtonBackground.qml
    QmlComponent/CustonButtonContent.qml
)

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
        QmlComponent/MainContent.qml
        QmlComponent/BottomMediaPlayer.qml
        QmlComponent/MediaControl.qml
        QmlComponent/CustomButton.qml
        QmlComponent/CustomButtonBackground.qml
        QmlComponent/CustomButtonContent.qml
    RESOURCES
        "QmlComponent/Resources/minimize-button.png"
        "QmlComponent/Resources/maximize-button.png"
        "QmlComponent/Resources/close-button.png"
        "QmlComponent/Resources/next-button.png"
        "QmlComponent/Resources/pause-button.png"
        "QmlComponent/Resources/play-button.png"
        "QmlComponent/Resources/previous-button.png"
        "QmlComponent/Resources/shuffle-button.png"
        "QmlComponent/Resources/repeat-button.png"
        "QmlComponent/Resources/music-note.png"
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
    PUBLIC
        ${CMAKE_SOURCE_DIR}/Interface
        ${CMAKE_SOURCE_DIR}/ServiceHandler
        ${CMAKE_SOURCE_DIR}/Model
)

target_link_libraries(appWindowMediaPlayer
    PRIVATE
        Qt6::Quick
        Qt6::Core5Compat
    PRIVATE
        WindowMediaService
        ServiceFactory
)

include(GNUInstallDirs)
install(TARGETS appWindowMediaPlayer
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
