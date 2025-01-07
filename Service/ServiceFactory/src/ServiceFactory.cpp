/*
* File: ServiceFactory.cpp
* Author: trung.la
* Date: 01-07-2025
* Description: Implementation for Service Factory
*/

#include "include/ServiceFactory.h"

ServiceFactory& ServiceFactory::instance()
{
    static ServiceFactory factory;
    return factory;
}