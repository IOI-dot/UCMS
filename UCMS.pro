QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admin_login.cpp \
    main.cpp \
    mainwindow.cpp \
    student.cpp \
    student_login.cpp \
    student_registeration.cpp

HEADERS += \
    admin.h \
    admin_login.h \
    mainwindow.h \
    student.h \
    student_login.h \
    student_registeration.h

FORMS += \
    admin_login.ui \
    mainwindow.ui \
    student_login.ui \
    student_registeration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
