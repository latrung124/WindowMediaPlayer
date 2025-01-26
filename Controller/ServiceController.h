/*
* File: ServiceController.h
* Author: trung.la
* Date: 01-08-2025
* Description: Implementation for Service Controller
*/

#ifndef SERVICE_CONTROLLER_H
#define SERVICE_CONTROLLER_H

#include <QObject>

#include <string>
#include <memory>
#include <unordered_map>

class IService;
class IServiceListener;
class QQmlApplicationEngine;

class ServiceController : public QObject
{
    Q_OBJECT

public:
    using ServiceUPtr = std::unique_ptr<IService>;
    using WEnginePtr = std::weak_ptr<QQmlApplicationEngine>;
    using EnginePtr = std::shared_ptr<QQmlApplicationEngine>;

    static ServiceController& getInstance();
    ~ServiceController();

    void initialize();
    void setEngine(const EnginePtr &engine);

private:
    ServiceController(QObject *parent = nullptr);
    void initializeServices();
    void registerListeners();

    std::unordered_map<std::string, ServiceUPtr> m_services;
    WEnginePtr m_engine;
};

#endif // SERVICE_CONTROLLER_H
