/*
* File: ServiceUtility.h
* Author: trung.la
* Date: 01-08-2025
* Description: Utility functions for Service
*/

#ifndef SERVICEUTILITY_H
#define SERVICEUTILITY_H

#include <unordered_map>
#include <string>

namespace utils {

namespace service {

enum class ServiceType {
    WindowMediaService,
};

inline std::unordered_map<ServiceType, std::string>& getServiceNames() {
    static std::unordered_map<ServiceType, std::string> serviceNames = {
        {ServiceType::WindowMediaService, "WindowMediaService"},
    };
    return serviceNames;
}

} // namespace utils::service

} // namespace utils

#endif // SERVICEUTILITY_H
