QT += core gui widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Appointment.cpp \
    AvailabilityManager.cpp \
    AvailabilityObserver.cpp \
    AppointmentManager.cpp \
    Doctor.cpp \
    JSONHandeler.cpp \
    MainWindow.cpp \
    Patient.cpp \
    Scheduler.cpp \
    TimeHelper.cpp \
    ValidateAccount.cpp \
    main.cpp

HEADERS += \
    Appointment.h \
    AppointmentManager.h \
    AvailabilityManager.h \
    AvailabilityObserver.h \
    Doctor.h \
    JSONHandeler.h \
    MainWindow.h \
    Patient.h \
    Scheduler.h \
    TimeHelper.h \
    ValidateAccount.h

FORMS += \
    MainWindow.ui

RESOURCES += \
    build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/patients.json \
    build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/doctors.json \
    build/Desktop_Qt_6_8_0_MinGW_64_bit-Debug/appointments.json

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    appointments.json \
    auth.json \
    doctors.json \
    patients.json
