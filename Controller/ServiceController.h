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

class ServiceController : public QObject
{
    Q_OBJECT

public:
    using ServiceUPtr = std::unique_ptr<IService>;
    explicit ServiceController(QObject *parent = nullptr);
    ~ServiceController();

    void initialize();

private:
    void initializeServices();
    void registerListeners();

    std::unordered_map<std::string, ServiceUPtr> m_services;
};

#endif // SERVICE_CONTROLLER_H
