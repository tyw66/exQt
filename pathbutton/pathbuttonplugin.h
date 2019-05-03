#pragma once

#include "pathbutton_global.h"

#include <extensionsystem/iplugin.h>

namespace PathButton {
namespace Internal {

class PathButtonPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "PathButton.json")

public:
    PathButtonPlugin();
    ~PathButtonPlugin();

    bool initialize(const QStringList &arguments, QString *errorString);
    void extensionsInitialized();
    ShutdownFlag aboutToShutdown();

private:
    void triggerAction();
};

} // namespace Internal
} // namespace PathButton
