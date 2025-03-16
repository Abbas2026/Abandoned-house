QT       += core gui
QT += multimedia
QT += multimedia multimediawidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    loading.cpp \
    main.cpp \
    menu.cpp \
    page4.cpp \
    page5.cpp \
    start.cpp \
    warning.cpp

HEADERS += \
    loading.h \
    menu.h \
    page4.h \
    page5.h \
    start.h \
    styles.h \
    warning.h

FORMS += \
    loading.ui \
    menu.ui \
    page4.ui \
    page5.ui \
    start.ui \
    warning.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
