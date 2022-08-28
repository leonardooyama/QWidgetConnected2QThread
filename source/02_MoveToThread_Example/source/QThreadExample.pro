QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    workerclass.cpp

HEADERS += \
    mainwindow.h \
    workerclass.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

isEmpty(TARGET_EXT) {
    win32 {
        TARGET_CUSTOM_EXT = .exe
    }
    macx {
        TARGET_CUSTOM_EXT = .app
    }
} else {
    TARGET_CUSTOM_EXT = $${TARGET_EXT}
}

win32 {
    DEPLOY_COMMAND = $$[QT_INSTALL_BINS]/windeployqt
}
macx {
    DEPLOY_COMMAND = $$[QT_INSTALL_BINS]/macdeployqt
}

CONFIG( debug, debug|release ) {
    # debug
    DEPLOY_FOLDER = $$shell_quote($$shell_path($${OUT_PWD}/debug))
    DEPLOY_TARGET = $$shell_quote($$shell_path($${OUT_PWD}/debug/$${TARGET}$${TARGET_CUSTOM_EXT}))
} else {
    # release
    DEPLOY_FOLDER = $$shell_quote($$shell_path($${OUT_PWD}/release))
    DEPLOY_TARGET = $$shell_quote($$shell_path($${OUT_PWD}/release/$${TARGET}$${TARGET_CUSTOM_EXT}))
}


QMAKE_POST_LINK = $${DEPLOY_COMMAND} $${DEPLOY_TARGET} --no-translations $$escape_expand(\n\t)

