QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appliedjob.cpp \
    changepassemp.cpp \
    changepassjobseek.cpp \
    connect.cpp \
    dialog.cpp \
    editprofile.cpp \
    editprofileemp.cpp \
    employer.cpp \
    global.cpp \
    main.cpp \
    mainwindow.cpp \
    providejob.cpp \
    searchjob.cpp \
    signup_dialog.cpp \
    signup_emp.cpp \
    viewprofile.cpp \
    vprofileemp.cpp \
    vprovidejob.cpp

HEADERS += \
    appliedjob.h \
    changepassemp.h \
    changepassjobseek.h \
    dialog.h \
    editprofile.h \
    editprofileemp.h \
    employer.h \
    global.h \
    mainwindow.h \
    providejob.h \
    searchjob.h \
    signup_dialog.h \
    signup_emp.h \
    viewprofile.h \
    vprofileemp.h \
    vprovidejob.h

FORMS += \
    appliedjob.ui \
    changepassemp.ui \
    changepassjobseek.ui \
    dialog.ui \
    editprofile.ui \
    editprofileemp.ui \
    employer.ui \
    mainwindow.ui \
    providejob.ui \
    searchjob.ui \
    signup_dialog.ui \
    signup_emp.ui \
    viewprofile.ui \
    vprofileemp.ui \
    vprovidejob.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
