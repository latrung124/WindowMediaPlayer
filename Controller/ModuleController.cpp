/*
* ModuleController.cpp
* Author: trung.la
* Date: 01-02-2025
* Descriptionn: This class is used to control the qml module
*/

#include "ModuleController.h"
#include "Utils/ModuleUtility.h"

ModuleController::ModuleController(QObject *parent)
    : QObject(parent)
    , m_engine(std::make_shared<QQmlApplicationEngine>())
{
    startConnection();
}

ModuleController::~ModuleController()
{
    endConnection();
}

void ModuleController::startConnection() {
    QObject::connect(
        m_engine.get(),
        &QQmlApplicationEngine::objectCreationFailed,
        this,
        [this]() { emit moduleLoadedFailed(); },
        Qt::QueuedConnection);
    QObject::connect(
        m_engine.get(),
        &QQmlApplicationEngine::quit,
        this,
        [this]() { emit moduleUnloaded(); },
        Qt::QueuedConnection);
}

void ModuleController::endConnection() {
    QObject::disconnect(this, nullptr, nullptr, nullptr);
}

void ModuleController::initialize()
{
    using namespace utils;
    auto moduleInfo = getModuleInfo();
    m_engine->loadFromModule(moduleInfo[ModuleType::MediaPlayer].moduleName,
                            moduleInfo[ModuleType::MediaPlayer].componentName);
}

void ModuleController::loadModule(const QString &moduleName, const QString &moduleComponent)
{
    m_engine->loadFromModule(moduleName, moduleComponent);
}
