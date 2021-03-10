QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 c++14 c++17



# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Device/calibrator.cpp \
    Device/cominterface.cpp \
    Device/device.cpp \
    Device/h4_7.cpp \
    Device/hp34420.cpp \
    Device/idevice.cpp \
    Device/interfaceconnect.cpp \
    Device/voltmeter.cpp \
    controller.cpp \
    devicedialog.cpp \
    dialogsettingscom.cpp \
    main.cpp \
    maindata.cpp \
    mainwindow.cpp

HEADERS += \
    Device/EnumModelsDevice.h \
    Device/calibrator.h \
    Device/cominterface.h \
    Device/device.h \
    Device/h4_7.h \
    Device/hp34420.h \
    Device/interfaceconnect.h \
    Device/voltmeter.h \
    controller.h \
    devicedialog.h \
    dialogsettingscom.h \
    maindata.h \
    mainwindow.h

FORMS += \
    devicedialog.ui \
    dialogsettingscom.ui \
    maindata.ui \
    mainwindow.ui

TRANSLATIONS += msget89_ru.ts

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Files.qrc


