## Usage: qmake "TEXTOSAURUS_REPO=<repo-root-folder>" "LIBTEXTOSAURUS_BIN_LIB=<folder-with-dll-lib-so>"
## Example: qmake "TEXTOSAURUS_REPO=c:\\textilosaurus" "LIBTEXTOSAURUS_BIN_LIB=c:\\libtextosaurus\\bin"

unix|mac {
  TARGET      = textosaurus-example
}
else {
  TARGET      = libtextosaurus-example
}

TEMPLATE = lib
QT       *= widgets
CONFIG += unversioned_libname unversioned_soname skip_target_version_ext
DEFINES *= TEXTOSAURUS_DLLSPEC= TEXTOSAURUS_DLLSPEC_EXPORT=Q_DECL_EXPORT QT_DEPRECATED_WARNINGS

message(textosaurus repository root folder is: $$TEXTOSAURUS_REPO)
message(libtextosaurus binary folder is: $$LIBTEXTOSAURUS_BIN_LIB)

# Setup inclusion of (lib)textosaurus, which is needed
# by every plugin. Every plugin must link
# against libtextosaurus.
INCLUDEPATH += $$TEXTOSAURUS_REPO/src/libtextosaurus
DEPENDPATH += $$LIBTEXTOSAURUS_BIN_LIB

win32: LIBS += -L$$LIBTEXTOSAURUS_BIN_LIB -llibtextosaurus
unix: LIBS += -L$$LIBTEXTOSAURUS_BIN_LIB -ltextosaurus

SOURCES += \
        exampleplugin.cpp

HEADERS += \
        exampleplugin.h
