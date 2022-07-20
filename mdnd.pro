QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    backend.cpp \
    enter_bits.cpp \
    enter_number.cpp \
    error.cpp \
    main.cpp \
    mainwindow.cpp \
    mdnf_window.cpp \
    number_choice.cpp \
    tablewindow.cpp

HEADERS += \
    backend.h \
    enter_bits.h \
    enter_number.h \
    error.h \
    mainwindow.h \
    mdnf_window.h \
    number_choice.h \
    tablewindow.h

FORMS += \
    enter_bits.ui \
    enter_number.ui \
    error.ui \
    mainwindow.ui \
    mdnf_window.ui \
    number_choice.ui \
    tablewindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
