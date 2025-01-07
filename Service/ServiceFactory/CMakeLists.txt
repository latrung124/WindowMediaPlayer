set(HEADERS
    include/WMediaServiceFactory.h
)

set(SOURCES
    src/WMediaServiceFactory.cpp
)

add_library(ServiceFactory SHARED
    ${HEADERS}
    ${SOURCES}
)

target_include_directories(ServiceFactory
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_SOURCE_DIR}/Service
        ${CMAKE_SOURCE_DIR}/Interface
)