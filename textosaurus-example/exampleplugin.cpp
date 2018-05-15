#include "exampleplugin.h"

#include "common/miscellaneous/settings.h"
#include "saurus/miscellaneous/textapplication.h"
#include "saurus/miscellaneous/textapplicationsettings.h"
#include "saurus/gui/tabwidget.h"

#include <QMessageBox>
#include <QAction>

ExamplePlugin::ExamplePlugin(QObject *parent) {}

ExamplePlugin::~ExamplePlugin() {
  qDebug("Destroying ExamplePlugin instance.");
}


QString ExamplePlugin::name() const {
  return tr("Example Plugin");
}

QList<BaseSidebar*> ExamplePlugin::sidebars() {
  return {};
}

QList<QAction*> ExamplePlugin::userActions() {
  return {
    new QAction(tr("Sample Action"), this)
  };
}

void ExamplePlugin::setTextApp(TextApplication *text_app, Settings *settings, IconFactory *icon_factory) {
  QMessageBox::information(nullptr, "Example plugin loaded", "Example plugin loaded");

  /*connect(text_app->tabWidget(), &TabWidget::currentChanged, [](int index) {
    QMessageBox::information(nullptr, "Example plugin loaded", QString("%1").arg(QString::number(index)));
  });*/
}
