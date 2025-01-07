/*
* File: WMediaServiceFactory.cpp
* Author: trung.la
* Date: 01-07-2025
* Descriptiton: This class is declares the factory method that is supposed to return an Media Service Object.
*/

#include "include/WMediaServiceFactory.h"
#include "WindowMediaSerice/include/WindowMediaService.h"

IService* WMediaServiceFactory::factoryMethod() const
{
    return new WindowMediaService();
}