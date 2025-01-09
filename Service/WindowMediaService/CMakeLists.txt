set(HEADERS
    include/WindowMediaService.h
    include/WindowSystemMedia.h
)

set(SOURCES
    src/WindowMediaService.cpp
    src/WindowSystemMedia.cpp
)

add_library(WindowMediaService SHARED
    ${HEADERS}
    ${SOURCES}
)

target_include_directories(WindowMediaService
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
    PUBLIC
        ${CMAKE_SOURCE_DIR}/Interface
)