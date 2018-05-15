#ifndef EXAMPLEPLUGIN_H
#define EXAMPLEPLUGIN_H

#include <qobject.h>

#include "saurus/plugin-system/pluginbase.h"

#include <QtGlobal>

class TEXTOSAURUS_DLLSPEC_EXPORT ExamplePlugin : public QObject, public PluginBase {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "io.github.martinrotter.textosaurus.example" FILE "plugin.json")
  Q_INTERFACES(PluginBase)

  public:
    explicit ExamplePlugin(QObject* parent = nullptr);
    virtual ~ExamplePlugin() override;

    QString name() const;
    QList<BaseSidebar*> sidebars();
    QList<QAction*> userActions();
    void setTextApp(TextApplication *text_app, Settings *settings, IconFactory *icon_factory);
};

#endif // EXAMPLEPLUGIN_H
