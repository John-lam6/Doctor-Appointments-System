/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCalendarWidget>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QStackedWidget *stackedWidget;
    QWidget *patientlogin;
    QWidget *widget;
    QLabel *orLabel_2;
    QPushButton *Signup_2;
    QLineEdit *passwordbox_2;
    QLabel *PatientLoginLabel;
    QPushButton *Signin_2;
    QLabel *password_2;
    QPushButton *doctorlogin_2;
    QLabel *email_2;
    QLineEdit *emailbox_2;
    QWidget *doctorlogin;
    QWidget *widget_2;
    QLabel *password;
    QLabel *DoctorLoginLabel;
    QPushButton *userlogin;
    QLineEdit *passwordbox;
    QLineEdit *emailbox;
    QLabel *email;
    QPushButton *Signin;
    QWidget *patientmain;
    QWidget *widget_3;
    QPushButton *logout_3;
    QPushButton *showallappt;
    QCalendarWidget *patientCalendarWidget;
    QWidget *doctormain;
    QCalendarWidget *doctorCalendarWidget;
    QPushButton *logout;
    QPushButton *todayappt;
    QWidget *patientappointments;
    QPushButton *backbutton_2;
    QPushButton *logout_4;
    QLabel *patientappointmentslabel;
    QWidget *doctorappointments;
    QPushButton *logout_2;
    QPushButton *backbutton;
    QLabel *doctorappointmentslabel;
    QPushButton *addappointment;
    QWidget *signup;
    QPushButton *createaccount;
    QPushButton *backtosignin;
    QLabel *email_3;
    QLabel *password_3;
    QLabel *orLabel_3;
    QLineEdit *emailbox_3;
    QLabel *patientsignuplabel;
    QLineEdit *passwordbox_3;
    QLineEdit *passwordbox_4;
    QLabel *confirmpassword;
    QWidget *successfulsignup;
    QLabel *accountsuccessful;
    QLabel *returnlabel;
    QPushButton *backtosignin_2;
    QWidget *patientdateappointment;
    QWidget *widget_4;
    QPushButton *backbutton_3;
    QPushButton *logout_5;
    QLabel *availableappointmentslabel;
    QWidget *insertnewappointment;
    QWidget *widget_5;
    QPushButton *backbutton_4;
    QPushButton *logout_6;
    QLabel *insertlabel;
    QLabel *startingtime;
    QLabel *endingtime;
    QPushButton *addappointment2;
    QLabel *tolabel;
    QTimeEdit *timeEdit_2;
    QTimeEdit *timeEdit;
    QWidget *successfulinsert;
    QWidget *widget_6;
    QLabel *returnlabel_2;
    QPushButton *backtoappointments;
    QLabel *appointmentssuccessful;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 0, 801, 571));
        patientlogin = new QWidget();
        patientlogin->setObjectName("patientlogin");
        widget = new QWidget(patientlogin);
        widget->setObjectName("widget");
        widget->setGeometry(QRect(0, 0, 801, 571));
        orLabel_2 = new QLabel(widget);
        orLabel_2->setObjectName("orLabel_2");
        orLabel_2->setGeometry(QRect(370, 380, 63, 20));
        orLabel_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Signup_2 = new QPushButton(widget);
        Signup_2->setObjectName("Signup_2");
        Signup_2->setGeometry(QRect(330, 410, 151, 41));
        passwordbox_2 = new QLineEdit(widget);
        passwordbox_2->setObjectName("passwordbox_2");
        passwordbox_2->setGeometry(QRect(330, 240, 211, 28));
        PatientLoginLabel = new QLabel(widget);
        PatientLoginLabel->setObjectName("PatientLoginLabel");
        PatientLoginLabel->setGeometry(QRect(310, 70, 201, 51));
        PatientLoginLabel->setBaseSize(QSize(0, 20));
        PatientLoginLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        Signin_2 = new QPushButton(widget);
        Signin_2->setObjectName("Signin_2");
        Signin_2->setGeometry(QRect(330, 320, 151, 41));
        password_2 = new QLabel(widget);
        password_2->setObjectName("password_2");
        password_2->setGeometry(QRect(220, 250, 91, 20));
        doctorlogin_2 = new QPushButton(widget);
        doctorlogin_2->setObjectName("doctorlogin_2");
        doctorlogin_2->setGeometry(QRect(630, 10, 151, 31));
        email_2 = new QLabel(widget);
        email_2->setObjectName("email_2");
        email_2->setGeometry(QRect(230, 190, 71, 20));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Maximum, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(14);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(email_2->sizePolicy().hasHeightForWidth());
        email_2->setSizePolicy(sizePolicy);
        email_2->setLineWidth(1);
        email_2->setScaledContents(true);
        email_2->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        email_2->setWordWrap(false);
        emailbox_2 = new QLineEdit(widget);
        emailbox_2->setObjectName("emailbox_2");
        emailbox_2->setGeometry(QRect(330, 180, 211, 28));
        stackedWidget->addWidget(patientlogin);
        doctorlogin = new QWidget();
        doctorlogin->setObjectName("doctorlogin");
        widget_2 = new QWidget(doctorlogin);
        widget_2->setObjectName("widget_2");
        widget_2->setGeometry(QRect(0, 0, 801, 571));
        password = new QLabel(widget_2);
        password->setObjectName("password");
        password->setGeometry(QRect(220, 250, 91, 20));
        DoctorLoginLabel = new QLabel(widget_2);
        DoctorLoginLabel->setObjectName("DoctorLoginLabel");
        DoctorLoginLabel->setGeometry(QRect(310, 70, 201, 51));
        DoctorLoginLabel->setBaseSize(QSize(0, 20));
        DoctorLoginLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        userlogin = new QPushButton(widget_2);
        userlogin->setObjectName("userlogin");
        userlogin->setGeometry(QRect(630, 10, 151, 31));
        passwordbox = new QLineEdit(widget_2);
        passwordbox->setObjectName("passwordbox");
        passwordbox->setGeometry(QRect(330, 240, 211, 28));
        emailbox = new QLineEdit(widget_2);
        emailbox->setObjectName("emailbox");
        emailbox->setGeometry(QRect(330, 180, 211, 28));
        email = new QLabel(widget_2);
        email->setObjectName("email");
        email->setGeometry(QRect(230, 190, 71, 20));
        sizePolicy.setHeightForWidth(email->sizePolicy().hasHeightForWidth());
        email->setSizePolicy(sizePolicy);
        email->setLineWidth(1);
        email->setScaledContents(true);
        email->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        email->setWordWrap(false);
        Signin = new QPushButton(widget_2);
        Signin->setObjectName("Signin");
        Signin->setGeometry(QRect(330, 320, 151, 41));
        stackedWidget->addWidget(doctorlogin);
        patientmain = new QWidget();
        patientmain->setObjectName("patientmain");
        widget_3 = new QWidget(patientmain);
        widget_3->setObjectName("widget_3");
        widget_3->setGeometry(QRect(0, 0, 801, 571));
        logout_3 = new QPushButton(widget_3);
        logout_3->setObjectName("logout_3");
        logout_3->setGeometry(QRect(630, 10, 151, 31));
        showallappt = new QPushButton(widget_3);
        showallappt->setObjectName("showallappt");
        showallappt->setGeometry(QRect(300, 410, 220, 40));
        patientCalendarWidget = new QCalendarWidget(widget_3);
        patientCalendarWidget->setObjectName("patientCalendarWidget");
        patientCalendarWidget->setGeometry(QRect(70, 50, 661, 341));
        patientCalendarWidget->setMinimumDate(QDate(2024, 11, 1));
        patientCalendarWidget->setMaximumDate(QDate(2030, 12, 31));
        patientCalendarWidget->setGridVisible(false);
        patientCalendarWidget->setHorizontalHeaderFormat(QCalendarWidget::HorizontalHeaderFormat::ShortDayNames);
        patientCalendarWidget->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);
        stackedWidget->addWidget(patientmain);
        doctormain = new QWidget();
        doctormain->setObjectName("doctormain");
        doctorCalendarWidget = new QCalendarWidget(doctormain);
        doctorCalendarWidget->setObjectName("doctorCalendarWidget");
        doctorCalendarWidget->setGeometry(QRect(70, 50, 661, 341));
        doctorCalendarWidget->setMinimumDate(QDate(2024, 11, 1));
        doctorCalendarWidget->setMaximumDate(QDate(2030, 12, 31));
        doctorCalendarWidget->setGridVisible(false);
        doctorCalendarWidget->setHorizontalHeaderFormat(QCalendarWidget::HorizontalHeaderFormat::ShortDayNames);
        doctorCalendarWidget->setVerticalHeaderFormat(QCalendarWidget::VerticalHeaderFormat::NoVerticalHeader);
        logout = new QPushButton(doctormain);
        logout->setObjectName("logout");
        logout->setGeometry(QRect(630, 10, 151, 31));
        todayappt = new QPushButton(doctormain);
        todayappt->setObjectName("todayappt");
        todayappt->setGeometry(QRect(290, 410, 220, 40));
        stackedWidget->addWidget(doctormain);
        logout->raise();
        todayappt->raise();
        doctorCalendarWidget->raise();
        patientappointments = new QWidget();
        patientappointments->setObjectName("patientappointments");
        backbutton_2 = new QPushButton(patientappointments);
        backbutton_2->setObjectName("backbutton_2");
        backbutton_2->setGeometry(QRect(20, 10, 151, 31));
        logout_4 = new QPushButton(patientappointments);
        logout_4->setObjectName("logout_4");
        logout_4->setGeometry(QRect(630, 10, 151, 31));
        patientappointmentslabel = new QLabel(patientappointments);
        patientappointmentslabel->setObjectName("patientappointmentslabel");
        patientappointmentslabel->setGeometry(QRect(200, 70, 400, 51));
        patientappointmentslabel->setBaseSize(QSize(0, 20));
        patientappointmentslabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(patientappointments);
        doctorappointments = new QWidget();
        doctorappointments->setObjectName("doctorappointments");
        logout_2 = new QPushButton(doctorappointments);
        logout_2->setObjectName("logout_2");
        logout_2->setGeometry(QRect(630, 10, 151, 31));
        backbutton = new QPushButton(doctorappointments);
        backbutton->setObjectName("backbutton");
        backbutton->setGeometry(QRect(20, 10, 151, 31));
        doctorappointmentslabel = new QLabel(doctorappointments);
        doctorappointmentslabel->setObjectName("doctorappointmentslabel");
        doctorappointmentslabel->setGeometry(QRect(200, 70, 400, 51));
        doctorappointmentslabel->setBaseSize(QSize(0, 20));
        doctorappointmentslabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        addappointment = new QPushButton(doctorappointments);
        addappointment->setObjectName("addappointment");
        addappointment->setGeometry(QRect(450, 10, 151, 31));
        stackedWidget->addWidget(doctorappointments);
        signup = new QWidget();
        signup->setObjectName("signup");
        createaccount = new QPushButton(signup);
        createaccount->setObjectName("createaccount");
        createaccount->setGeometry(QRect(330, 320, 151, 41));
        backtosignin = new QPushButton(signup);
        backtosignin->setObjectName("backtosignin");
        backtosignin->setGeometry(QRect(330, 410, 151, 41));
        email_3 = new QLabel(signup);
        email_3->setObjectName("email_3");
        email_3->setGeometry(QRect(230, 160, 71, 20));
        sizePolicy.setHeightForWidth(email_3->sizePolicy().hasHeightForWidth());
        email_3->setSizePolicy(sizePolicy);
        email_3->setLineWidth(1);
        email_3->setScaledContents(true);
        email_3->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        email_3->setWordWrap(false);
        password_3 = new QLabel(signup);
        password_3->setObjectName("password_3");
        password_3->setGeometry(QRect(220, 220, 91, 20));
        orLabel_3 = new QLabel(signup);
        orLabel_3->setObjectName("orLabel_3");
        orLabel_3->setGeometry(QRect(370, 380, 63, 20));
        orLabel_3->setAlignment(Qt::AlignmentFlag::AlignCenter);
        emailbox_3 = new QLineEdit(signup);
        emailbox_3->setObjectName("emailbox_3");
        emailbox_3->setGeometry(QRect(330, 150, 211, 28));
        patientsignuplabel = new QLabel(signup);
        patientsignuplabel->setObjectName("patientsignuplabel");
        patientsignuplabel->setGeometry(QRect(310, 70, 211, 51));
        patientsignuplabel->setBaseSize(QSize(0, 20));
        patientsignuplabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        passwordbox_3 = new QLineEdit(signup);
        passwordbox_3->setObjectName("passwordbox_3");
        passwordbox_3->setGeometry(QRect(330, 210, 211, 28));
        passwordbox_4 = new QLineEdit(signup);
        passwordbox_4->setObjectName("passwordbox_4");
        passwordbox_4->setGeometry(QRect(330, 270, 211, 28));
        confirmpassword = new QLabel(signup);
        confirmpassword->setObjectName("confirmpassword");
        confirmpassword->setGeometry(QRect(160, 270, 125, 20));
        stackedWidget->addWidget(signup);
        successfulsignup = new QWidget();
        successfulsignup->setObjectName("successfulsignup");
        accountsuccessful = new QLabel(successfulsignup);
        accountsuccessful->setObjectName("accountsuccessful");
        accountsuccessful->setGeometry(QRect(240, 90, 341, 20));
        accountsuccessful->setAlignment(Qt::AlignmentFlag::AlignCenter);
        returnlabel = new QLabel(successfulsignup);
        returnlabel->setObjectName("returnlabel");
        returnlabel->setGeometry(QRect(250, 190, 311, 20));
        returnlabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        backtosignin_2 = new QPushButton(successfulsignup);
        backtosignin_2->setObjectName("backtosignin_2");
        backtosignin_2->setGeometry(QRect(330, 320, 151, 41));
        stackedWidget->addWidget(successfulsignup);
        patientdateappointment = new QWidget();
        patientdateappointment->setObjectName("patientdateappointment");
        widget_4 = new QWidget(patientdateappointment);
        widget_4->setObjectName("widget_4");
        widget_4->setGeometry(QRect(0, 0, 801, 571));
        backbutton_3 = new QPushButton(widget_4);
        backbutton_3->setObjectName("backbutton_3");
        backbutton_3->setGeometry(QRect(20, 10, 151, 31));
        logout_5 = new QPushButton(widget_4);
        logout_5->setObjectName("logout_5");
        logout_5->setGeometry(QRect(630, 10, 151, 31));
        availableappointmentslabel = new QLabel(widget_4);
        availableappointmentslabel->setObjectName("availableappointmentslabel");
        availableappointmentslabel->setGeometry(QRect(130, 70, 550, 51));
        availableappointmentslabel->setBaseSize(QSize(0, 20));
        availableappointmentslabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(patientdateappointment);
        insertnewappointment = new QWidget();
        insertnewappointment->setObjectName("insertnewappointment");
        widget_5 = new QWidget(insertnewappointment);
        widget_5->setObjectName("widget_5");
        widget_5->setGeometry(QRect(0, 0, 801, 571));
        backbutton_4 = new QPushButton(widget_5);
        backbutton_4->setObjectName("backbutton_4");
        backbutton_4->setGeometry(QRect(20, 10, 151, 31));
        logout_6 = new QPushButton(widget_5);
        logout_6->setObjectName("logout_6");
        logout_6->setGeometry(QRect(630, 10, 151, 31));
        insertlabel = new QLabel(widget_5);
        insertlabel->setObjectName("insertlabel");
        insertlabel->setGeometry(QRect(200, 70, 400, 51));
        insertlabel->setBaseSize(QSize(0, 20));
        insertlabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        startingtime = new QLabel(widget_5);
        startingtime->setObjectName("startingtime");
        startingtime->setGeometry(QRect(200, 180, 121, 20));
        startingtime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        endingtime = new QLabel(widget_5);
        endingtime->setObjectName("endingtime");
        endingtime->setGeometry(QRect(490, 180, 101, 20));
        endingtime->setAlignment(Qt::AlignmentFlag::AlignCenter);
        addappointment2 = new QPushButton(widget_5);
        addappointment2->setObjectName("addappointment2");
        addappointment2->setGeometry(QRect(320, 300, 151, 31));
        tolabel = new QLabel(widget_5);
        tolabel->setObjectName("tolabel");
        tolabel->setGeometry(QRect(350, 210, 101, 20));
        tolabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        timeEdit_2 = new QTimeEdit(widget_5);
        timeEdit_2->setObjectName("timeEdit_2");
        timeEdit_2->setGeometry(QRect(467, 210, 151, 29));
        timeEdit = new QTimeEdit(widget_5);
        timeEdit->setObjectName("timeEdit");
        timeEdit->setGeometry(QRect(190, 210, 151, 29));
        stackedWidget->addWidget(insertnewappointment);
        successfulinsert = new QWidget();
        successfulinsert->setObjectName("successfulinsert");
        widget_6 = new QWidget(successfulinsert);
        widget_6->setObjectName("widget_6");
        widget_6->setGeometry(QRect(0, 0, 801, 571));
        returnlabel_2 = new QLabel(widget_6);
        returnlabel_2->setObjectName("returnlabel_2");
        returnlabel_2->setGeometry(QRect(250, 190, 311, 20));
        returnlabel_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        backtoappointments = new QPushButton(widget_6);
        backtoappointments->setObjectName("backtoappointments");
        backtoappointments->setGeometry(QRect(330, 320, 151, 41));
        appointmentssuccessful = new QLabel(widget_6);
        appointmentssuccessful->setObjectName("appointmentssuccessful");
        appointmentssuccessful->setGeometry(QRect(220, 90, 381, 20));
        appointmentssuccessful->setAlignment(Qt::AlignmentFlag::AlignCenter);
        stackedWidget->addWidget(successfulinsert);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(8);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        orLabel_2->setText(QCoreApplication::translate("MainWindow", "or", nullptr));
        Signup_2->setText(QCoreApplication::translate("MainWindow", "Sign up", nullptr));
        PatientLoginLabel->setText(QCoreApplication::translate("MainWindow", "PATIENT LOGIN PAGE", nullptr));
        Signin_2->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        password_2->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        doctorlogin_2->setText(QCoreApplication::translate("MainWindow", "Doctor Login", nullptr));
        email_2->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        password->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        DoctorLoginLabel->setText(QCoreApplication::translate("MainWindow", "DOCTOR LOGIN PAGE", nullptr));
        userlogin->setText(QCoreApplication::translate("MainWindow", "Patient Login", nullptr));
        email->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        Signin->setText(QCoreApplication::translate("MainWindow", "Sign in", nullptr));
        logout_3->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        showallappt->setText(QCoreApplication::translate("MainWindow", "Show All Booked Appointments", nullptr));
        logout->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        todayappt->setText(QCoreApplication::translate("MainWindow", "Today's Booked Appointments", nullptr));
        backbutton_2->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        logout_4->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        patientappointmentslabel->setText(QCoreApplication::translate("MainWindow", "APPOINTMENTS", nullptr));
        logout_2->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        backbutton->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        doctorappointmentslabel->setText(QCoreApplication::translate("MainWindow", "APPOINTMENTS", nullptr));
        addappointment->setText(QCoreApplication::translate("MainWindow", "Add Appointment", nullptr));
        createaccount->setText(QCoreApplication::translate("MainWindow", "Create Account", nullptr));
        backtosignin->setText(QCoreApplication::translate("MainWindow", "Back to Sign in", nullptr));
        email_3->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        password_3->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        orLabel_3->setText(QCoreApplication::translate("MainWindow", "or", nullptr));
        patientsignuplabel->setText(QCoreApplication::translate("MainWindow", "PATIENT SIGNUP PAGE", nullptr));
        confirmpassword->setText(QCoreApplication::translate("MainWindow", "Confirm Password", nullptr));
        accountsuccessful->setText(QCoreApplication::translate("MainWindow", "ACCOUNT SUCCESSFULLY CREATED", nullptr));
        returnlabel->setText(QCoreApplication::translate("MainWindow", "RETURN TO HOME PAGE TO LOGIN", nullptr));
        backtosignin_2->setText(QCoreApplication::translate("MainWindow", "Return to Login", nullptr));
        backbutton_3->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        logout_5->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        availableappointmentslabel->setText(QCoreApplication::translate("MainWindow", "AVAILABLE APPOINTMENTS", nullptr));
        backbutton_4->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        logout_6->setText(QCoreApplication::translate("MainWindow", "Logout", nullptr));
        insertlabel->setText(QCoreApplication::translate("MainWindow", "INSERT NEW APPOINTMENT", nullptr));
        startingtime->setText(QCoreApplication::translate("MainWindow", "Starting Time", nullptr));
        endingtime->setText(QCoreApplication::translate("MainWindow", "Ending Time", nullptr));
        addappointment2->setText(QCoreApplication::translate("MainWindow", "Add Appointment", nullptr));
        tolabel->setText(QCoreApplication::translate("MainWindow", "to", nullptr));
        returnlabel_2->setText(QCoreApplication::translate("MainWindow", "RETURN TO THE MAIN PAGE", nullptr));
        backtoappointments->setText(QCoreApplication::translate("MainWindow", "Return to Appointments", nullptr));
        appointmentssuccessful->setText(QCoreApplication::translate("MainWindow", "APPOINTMENT SUCCESSFULLY CREATED", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
