## This is main project file of plugin for Textosaurus.
##
## !!! Always include file
##
## Usage: qmake "TEXTOSAURUS_REPO=<repo-root-folder>" "LIBTEXTOSAURUS_BIN_LIB=<folder-with-dll-lib-so>"
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
