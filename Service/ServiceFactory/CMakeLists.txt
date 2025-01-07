set(HEADERS
    include/ServiceFactory.h
)

set(SOURCES
    src/ServiceFactory.cpp
)

add_library(ServiceFactory SHARED
    ${HEADERS}
    ${SOURCES}
)

add_dependencies(ServiceFactory WindowMediaService)

target_include_directories(ServiceFactory
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/Service
    PUBLIC
        ${CMAKE_SOURCE_DIR}/Interface
)

target_link_libraries(ServiceFactory
    PRIVATE
        WindowMediaService
)