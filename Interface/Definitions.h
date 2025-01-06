#ifndef INTERFACE_DEFINITIONS_H
#define INTERFACE_DEFINITIONS_H

#ifdef _WIN32
#    ifdef WMEDIA_SERVICE_LIBRARY_EXPORTS
#        define WMEDIA_SERVICE_API __declspec(dllexport) // When building the library
#    else
#        define WMEDIA_SERVICE_API __declspec(dllimport) // When consuming the library
#    endif
#else
#    define WMEDIA_SERVICE_API // Non-Windows platforms
#endif

#endif // INTERFACE_DEFINITIONS_H