/*
* File: WindowMediaServiceHandler.cpp
* Author: trung.la
* Date: 01-15-2025
* Description: Implementation for Window Media Service Handler
*/

#include "WindowMediaServiceHandler.h"

#include "ServiceConsumer/WindowMediaService/WindowMediaServiceConsumer.h"

WindowMediaServiceHandler::WindowMediaServiceHandler()
    : m_serviceConsumer(std::make_unique<WindowMediaServiceConsumer>(this))
{
}

WindowMediaServiceHandler::~WindowMediaServiceHandler()
{
}

WindowMediaServiceHandler& WindowMediaServiceHandler::getInstance()
{
    static WindowMediaServiceHandler instance;
    return instance;
}
