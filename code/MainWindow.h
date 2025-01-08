#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "TimeHelper.h"
#include "ValidateAccount.h"
#include "AppointmentManager.h"
#include "AvailabilityManager.h"
#include "Patient.h"
#include "JSONHandeler.h"
#include "AppointmentManager.h"

#include <list>
#include <QMainWindow>
#include <QMessageBox>
#include <string>
#include <QFile>

QT_BEGIN_NAMESPACE

namespace Ui {
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onSigninClickedDoctor();
    void onSigninClickedPatient();
    void switchToDoctorLogin();
    void switchToPatientLogin();
    void switchToSignUp();
    void doctorDateClicked(const QDate &date);
    void doctorDateClicked2();
    void backToDoctorCalendar();
    void backToPatientCalendar();
    void patientDateClicked(const QDate &date);
    void loadDateToLabelDoctor(const QDate &date);
    void loadDateToLabelPatient(const QDate &date);
    void todayAppointments ();
    void switchToSuccessfulCreationPage();
    void switchToPatientsAppointments();
    void switchToSuccessfulInsert();
    void switchToInsertAppointment();

private:
    static TimeHelper* timehelper;
    static ValidateAccount* validateaccount;
    static JSONHandeler* jsonhandeler;
    static QDate static_date;
    static AvailabilityManager availabilitymanager;
    static AppointmentManager* appointmentmanager;
    int docid;
    int patientid;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
