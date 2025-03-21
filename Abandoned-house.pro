QT       += core gui
QT += multimedia
QT += multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    edithtml.cpp \
    loading.cpp \
    main.cpp \
    menu.cpp \
    page14.cpp \
    page24.cpp \
    page4.cpp \
    page44.cpp \
    page45.cpp \
    page5.cpp \
    page8.cpp \
    page84.cpp \
    start.cpp \
    warning.cpp

HEADERS += \
    SignalManager.h \
    edithtml.h \
    loading.h \
    menu.h \
    page14.h \
    page24.h \
    page4.h \
    page44.h \
    page45.h \
    page5.h \
    page8.h \
    page84.h \
    start.h \
    styles.h \
    warning.h

FORMS += \
    loading.ui \
    menu.ui \
    page14.ui \
    page24.ui \
    page4.ui \
    page44.ui \
    page45.ui \
    page5.ui \
    page8.ui \
    page84.ui \
    start.ui \
    warning.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
