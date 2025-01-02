/*
* WindowController.cpp
* Author: trung.la
* Date: 01-02-2025
* Descriptionn: This class is used to control the window
*/

#include "WindowController.h"

#include <QQmlApplicationEngine>

WindowController::WindowController(const WEnginePtr &engine, QObject *parent)
    : QObject(parent)
    , m_engine(engine)
{
}

WindowController::~WindowController()
{
}

void WindowController::closeWindow()
{
    emit close();
}

void WindowController::minimizeWindow()
{
}

void WindowController::maximizeWindow()
{
}