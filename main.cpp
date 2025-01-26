#include <QGuiApplication>

#include "Controller/ModuleController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    ModuleController controller;
    QObject::connect(
        &controller,
        &ModuleController::moduleLoadedFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    QObject::connect(
        &controller,
        &ModuleController::moduleUnloaded,
        &app,
        &QGuiApplication::quit,
        Qt::QueuedConnection);

    controller.initialize();

    return app.exec();
}
