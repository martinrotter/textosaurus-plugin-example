// For license of this file, see <project-root-folder>/LICENSE.md.

#ifndef EXAMPLEPLUGIN_H
#define EXAMPLEPLUGIN_H

#include <qobject.h>

#include "libtextosaurus/saurus/plugin-system/pluginbase.h"

#include <QtGlobal>

class TEXTOSAURUS_DLLSPEC_EXPORT ExamplePlugin : public QObject, public PluginBase {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID "io.github.martinrotter.textosaurus.example" FILE "plugin.json")
  Q_INTERFACES(PluginBase)

  public:
    explicit ExamplePlugin(QObject* parent = nullptr);
    virtual ~ExamplePlugin() override;

    virtual QString name() const override;
    virtual QString id() const override;
    virtual QList<BaseSidebar*> sidebars() override;
    virtual QList<QAction*> userActions() override;
    virtual void start(QWidget* main_form_widget, TextApplication* text_app,
                       Settings* settings, IconFactory* icon_factory,
                       WebFactory* web_factory) override;
    virtual void stop() override;
};

#endif // EXAMPLEPLUGIN_H
