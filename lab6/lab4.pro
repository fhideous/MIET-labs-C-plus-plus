QT       += core gui

#QMAKE_CXXFLAGS_RELEASE -= -O2
#QMAKE_CXXFLAGS_RELEASE += -Os


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line_number.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0



SOURCES += \
    AbstractReader.cpp \
    CSVReader.cpp \
    Empl.cpp \
    JSONReader.cpp \
    Student.cpp \
    employer.cpp \
    error_text_browser.cpp \
    lab_support.cpp \
    main.cpp \
#    main2.cpp \
    mainwindow.cpp \
    out_data.cpp \
    professor.cpp

HEADERS += \
    AbstractReader.h \
    CSVReader.h \
    Empl.h \
    JSONReader.h \
    Student.h \
    employer.h \
    employers.h \
    error_text_browser.h \
    json.hpp \
    lab.h \
    mainwindow.h \
    out_data.h \
    professor.h

FORMS += \
    mainwindow.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    1 \
    CMakeLists.txt \
    csv.csv \
    lab2.pro.user \
    lab3.pro.user