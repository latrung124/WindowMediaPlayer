/*
* File: ModuleUtility.h
* Author: trung.la
* Date: 01-02-2025
* Descriptionn: This class is used to control the qml module
*/

#ifndef MODULEUTILITY_H
#define MODULEUTILITY_H

#include <QString>
#include <QHash>

namespace utils {

enum class ModuleType {
    MediaPlayer,
};

struct ModuleInfo {
    ModuleInfo() = default;
    ModuleInfo(QString module, QString component)
        : moduleName(module)
        , componentName(component)
    {
    }

    QString moduleName;
    QString componentName;
};

inline QHash<ModuleType, ModuleInfo>& getModuleInfo() {
    static QHash<ModuleType, ModuleInfo> moduleInfo = {
        {ModuleType::MediaPlayer, {"WindowMediaPlayer", "Main"}},
    };
    return moduleInfo;
}

} // namespace utils
#endif // MODULEUTILITY_H
