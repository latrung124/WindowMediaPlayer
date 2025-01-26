/*
* WindowController.h
* Author: trung.la
* Date: 01-02-2025
* Descriptionn: This class is used to control the window
*/

#ifndef WINDOWCONTROLLER_H
#define WINDOWCONTROLLER_H

#include <QObject>

#include <memory>

class QQmlApplicationEngine;

class WindowController : public QObject
{
    Q_OBJECT

public:
    using WEnginePtr = std::shared_ptr<QQmlApplicationEngine>;

    explicit WindowController(const WEnginePtr &engine, QObject *parent = nullptr);
    ~WindowController();

public slots:
    void closeWindow();
    void minimizeWindow();
    void maximizeWindow();

Q_SIGNALS:
    void close();
    void minimize();
    void maximize();

private:
    WEnginePtr m_engine;
};

#endif // WINDOWCONTROLLER_H
