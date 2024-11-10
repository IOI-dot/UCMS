QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    admin.cpp \
    admin_course_management.cpp \
    admin_event_management.cpp \
    admin_homepage.cpp \
    admin_login.cpp \
    admin_student_management.cpp \
    course.cpp \
    event.cpp \
    file_manager.cpp \
    main.cpp \
    mainwindow.cpp \
    student.cpp \
    student_academic_profile.cpp \
    student_course_registration.cpp \
    student_event_registration.cpp \
    student_homepage.cpp \
    student_login.cpp \
    student_registeration.cpp

HEADERS += \
    admin.h \
    admin_course_management.h \
    admin_event_management.h \
    admin_homepage.h \
    admin_login.h \
    admin_student_management.h \
    course.h \
    event.h \
    file_manager.h \
    mainwindow.h \
    student.h \
    student_academic_profile.h \
    student_course_registration.h \
    student_event_registration.h \
    student_homepage.h \
    student_login.h \
    student_registeration.h

FORMS += \
    admin_course_management.ui \
    admin_event_management.ui \
    admin_homepage.ui \
    admin_login.ui \
    admin_student_management.ui \
    mainwindow.ui \
    student_academic_profile.ui \
    student_course_registration.ui \
    student_event_registration.ui \
    student_homepage.ui \
    student_login.ui \
    student_registeration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
