// For license of this file, see <project-root-folder>/LICENSE.md.

#include "exampleplugin.h"

#include "libtextosaurus/common/miscellaneous/settings.h"
#include "libtextosaurus/saurus/miscellaneous/textapplication.h"
#include "libtextosaurus/saurus/miscellaneous/textapplicationsettings.h"
#include "libtextosaurus/saurus/gui/tabwidget.h"
#include "libtextosaurus/saurus/gui/texteditor.h"

#include <QMessageBox>
#include <QAction>

ExamplePlugin::ExamplePlugin(QObject *parent) {
  Q_UNUSED(parent)
}

ExamplePlugin::~ExamplePlugin() {
  qDebug("Destroying ExamplePlugin instance.");
}


QString ExamplePlugin::name() const {
  return tr("Example Plugin");
}

QString ExamplePlugin::id() const {
  return QSL("io.github.martinrotter.textosaurus.example");
}

QList<BaseSidebar*> ExamplePlugin::sidebars() {
  return {};
}

QList<QAction*> ExamplePlugin::userActions() {
  return {
    new QAction(tr("Sample Action"), this)
  };
}

void ExamplePlugin::start(QWidget *main_form_widget, TextApplication *text_app, Settings *settings, IconFactory *icon_factory) {
  QMessageBox::information(nullptr, "Example plugin loaded", "Example plugin loaded");

  connect(text_app->tabWidget(), &TabWidget::currentChanged, [text_app](int index) {
    if (index >= 0) {
      text_app->tabWidget()->currentEditor()->appendText(5, "123456789");
    }
  });
}

void ExamplePlugin::stop() {
  QMessageBox::information(nullptr, "Example plugin stopping", "Example plugin stopping");
}
