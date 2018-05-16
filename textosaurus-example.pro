#### This is main project file of plugin for Textosaurus.
##
## !!! Always include file "https://github.com/martinrotter/textosaurus-plugin-example/blob/master/plugin-common-setup.pri"
## in this project like this:
##
##   include($$PWD/plugin-common-setup.pri)
##
#### How to compile
##
## You need to have libtextosaurus repository cloned and submodules recursively updated. You also
## have to compile libtextosaurus because every plugin must link against libtextosaurus library.
## You can find libtextosaurus here (https://github.com/martinrotter/textosaurus/tree/master/src/libtextosaurus),
## it is part of Textosaurus source code tree.
##
## QMake usage: qmake "TEXTOSAURUS_REPO=<repo-root-folder>" "LIBTEXTOSAURUS_BIN_LIB=<folder-with-dll-lib-so>"
## Example: qmake "TEXTOSAURUS_REPO=c:\\textilosaurus" "LIBTEXTOSAURUS_BIN_LIB=c:\\libtextosaurus\\bin"

include($$PWD/plugin-common-setup.pri)

unix|mac {
  TARGET      = textosaurus-example
}
else {
  TARGET      = libtextosaurus-example
}

QT       *= widgets

SOURCES += \
        exampleplugin.cpp

HEADERS += \
        exampleplugin.h
