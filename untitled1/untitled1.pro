
#-------------------------------------------------
#
# Project created by QtCreator 2018-10-31T08:31:47
#
#-------------------------------------------------

QT       += core gui sql
QT       += core gui network
CONFIG += console
QT += printsupport
INCLUDEPATH += C:\Program Files (x86)\OpenSSL-Win32
DEPENDPATH +=C:\Program Files (x86)\OpenSSL-Win32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled1
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


CONFIG += c++11
SOURCES += \
        main.cpp \
        mainwindow.cpp \
        client.cpp \
        cnx.cpp \
        src/emailaddress.cpp \
        src/mimeattachment.cpp \
        src/mimecontentformatter.cpp \
        src/mimefile.cpp \
        src/mimehtml.cpp \
        src/mimeinlinefile.cpp \
        src/mimemessage.cpp \
        src/mimemultipart.cpp \
        src/mimepart.cpp \
        src/mimetext.cpp \
        src/quotedprintable.cpp \
        src/smtpclient.cpp \
        ticket.cpp







HEADERS += \
        mainwindow.h \
    client.h \
    cnx.h \
    src/SmtpMime \
    src/emailaddress.h \
    src/mimeattachment.h \
    src/mimecontentformatter.h \
    src/mimefile.h \
    src/mimehtml.h \
    src/mimeinlinefile.h \
    src/mimemessage.h \
    src/mimemultipart.h \
    src/mimepart.h \
    src/mimetext.h \
    src/quotedprintable.h \
    src/smtpclient.h \
    src/smtpexports.h \
    ticket.h



FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ressources.qrc

DISTFILES +=
