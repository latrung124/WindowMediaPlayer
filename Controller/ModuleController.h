/*
* File:  ModuleController.h
* Author: trung.la
* Date: 01-02-2025
* Descriptionn: This class is used to control the qml module
*/

#ifndef MODULECONTROLLER_H
#define MODULECONTROLLER_H

#include <QObject>
#include <QQmlApplicationEngine>

#include <memory>

class ModuleController : public QObject
{
    Q_OBJECT

public:
    using EnginePtr = std::shared_ptr<QQmlApplicationEngine>;
    explicit ModuleController(QObject *parent = nullptr);
    ~ModuleController();

    void initialize();
    EnginePtr engine() const;

signals:
    void moduleLoadedSucceed();
    void moduleLoadedFailed();
    void moduleUnloaded();

private:
    void startConnection();
    void endConnection();
    void loadModule(const QString &moduleName, const QString &moduleComponent);
    EnginePtr m_engine;
};

#endif // MODULECONTROLLER_H