/*
* ModuleController.cpp
* Author: trung.la
* Date: 01-02-2025
* Descriptionn: This class is used to control the qml module
*/

#include "ModuleController.h"
#include "Utils/ModuleUtility.h"

#include "WindowController.h"
#include "ServiceController.h"

#include "QQmlContext"
#include <QGuiApplication>

ModuleController::ModuleController(QObject *parent)
    : QObject(parent)
    , m_engine(std::make_shared<QQmlApplicationEngine>())
    , m_windowController(std::make_shared<WindowController>(m_engine))
{
    startConnection();

    ServiceController::getInstance().initialize();
}

ModuleController::~ModuleController()
{
    m_engine->deleteLater();
    m_windowController->deleteLater();
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
    QObject::connect(
        m_windowController.get(),
        &WindowController::close,
        this,
        [this]() {
            emit moduleUnloaded();
            ServiceController::getInstance().onModuleUnload();
        },
        Qt::QueuedConnection);

    QObject::connect(
        m_engine.get(),
        &QQmlApplicationEngine::objectCreated,
        this,
        [this](QObject *object, const QUrl &url) {
            Q_UNUSED(url)
            if (!object)
                return;
            emit moduleLoadedSucceed(m_engine); },
        Qt::QueuedConnection);
 
    QObject::connect(
        this,
        &ModuleController::moduleLoadedSucceed,
        &ServiceController::getInstance(),
        &ServiceController::onModuleLoadedSucceed,
        Qt::QueuedConnection);
}

void ModuleController::endConnection() {
    QObject::disconnect(this, nullptr, nullptr, nullptr);
}

void ModuleController::initialize()
{
    setContextProperties();

    using namespace utils;
    auto moduleInfo = getModuleInfo();
    m_engine->loadFromModule(moduleInfo[ModuleType::MediaPlayer].moduleName,
                            moduleInfo[ModuleType::MediaPlayer].componentName);
}

void ModuleController::setContextProperties()
{
    m_engine->rootContext()->setContextProperty("windowController", m_windowController.get());
}

void ModuleController::loadModule(const QString &moduleName, const QString &moduleComponent)
{
    m_engine->loadFromModule(moduleName, moduleComponent);
}
