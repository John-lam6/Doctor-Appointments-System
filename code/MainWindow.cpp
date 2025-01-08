#include "MainWindow.h"
#include "ui_MainWindow.h"


TimeHelper* MainWindow::timehelper = TimeHelper::getInstance();
ValidateAccount* MainWindow::validateaccount = ValidateAccount::getInstance();
JSONHandeler* MainWindow::jsonhandeler = JSONHandeler::getInstance();
AvailabilityManager MainWindow::availabilitymanager;
AppointmentManager* MainWindow::appointmentmanager = AppointmentManager::getInstance();
QDate MainWindow::static_date; // for switching back to the proper appointments screen

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    docid = 0;
    patientid = 0;

    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);


    // Sets the functionality of the buttons for the doctorappointments page.
    connect (ui->backbutton, &QPushButton::clicked, this, &MainWindow::backToDoctorCalendar);
    connect (ui->logout_2, &QPushButton::clicked, this, &MainWindow::switchToPatientLogin);
    connect (ui->addappointment, &QPushButton::clicked, this, &MainWindow::switchToInsertAppointment);


    // Sets the functionality of the buttons for the doctorlogin page.
    connect (ui->Signin, &QPushButton::clicked, this, &MainWindow::onSigninClickedDoctor);
    connect (ui->userlogin, &QPushButton::clicked, this, &MainWindow::switchToPatientLogin);


    // Sets the functionality of the buttons for the doctormain page.
    connect (ui->doctorCalendarWidget, &QCalendarWidget::clicked, this, &MainWindow::doctorDateClicked);
    connect (ui->logout, &QPushButton::clicked, this, &MainWindow::switchToPatientLogin);
    connect (ui->todayappt, &QPushButton::clicked, this, &MainWindow::todayAppointments);


    // Sets the functionality of the buttons for the patientappointments page.
    connect (ui->backbutton_2, &QPushButton::clicked, this, &MainWindow::backToPatientCalendar);
    connect (ui->logout_4, &QPushButton::clicked, this, &MainWindow::switchToPatientLogin);


    // Sets the functionality of the buttons for the patientdateappointment page.
    connect (ui->backbutton_3, &QPushButton::clicked, this, &MainWindow::backToPatientCalendar);
    connect (ui->logout_5, &QPushButton::clicked, this, &MainWindow::switchToPatientLogin);


    // Sets the functionality of the buttons for the patientlogin page.
    connect (ui->Signin_2, &QPushButton::clicked, this, &MainWindow::onSigninClickedPatient);
    connect (ui->Signup_2, &QPushButton::clicked, this, &MainWindow::switchToSignUp);
    connect (ui->doctorlogin_2, &QPushButton::clicked, this, &MainWindow::switchToDoctorLogin);


    // Sets the functionality of the buttons for the patientmain page.
    connect (ui->patientCalendarWidget, &QCalendarWidget::clicked, this, &MainWindow::patientDateClicked);
    connect (ui->logout_3, &QPushButton::clicked, this, &MainWindow::switchToPatientLogin);
    connect (ui->showallappt, &QPushButton::clicked, this, &MainWindow::switchToPatientsAppointments);


    // Sets the functionality of the buttons for the signup page.
    connect (ui->backtosignin, &QPushButton::clicked, this, &MainWindow::switchToPatientLogin);
    connect (ui->createaccount, &QPushButton::clicked, this, &MainWindow::switchToSuccessfulCreationPage);
    //connect (ui->createaccount, &QPushButton::clicked, this, &MainWindow::confirmCreate);


    // Sets the functionality of the buttons for the successfulinsert page.
    connect (ui->backtoappointments, &QPushButton::clicked, this, &MainWindow::doctorDateClicked2);

    // Sets the functionality of the buttons for the insertnewappointment page.
    connect (ui->addappointment2, &QPushButton::clicked, this, &MainWindow::switchToSuccessfulInsert);
    connect (ui->backbutton_4, &QPushButton::clicked, this, &MainWindow::doctorDateClicked2);
    connect (ui->logout_6, &QPushButton::clicked, this, &MainWindow::switchToPatientLogin);

    // Sets the functionality of the buttons for the successfulsignup page.
    connect (ui->backtosignin_2, &QPushButton::clicked, this, &MainWindow::switchToPatientLogin);


    // Sets the styles for the doctorlogin page.
    QFont font = ui->DoctorLoginLabel->font();
    font.setPointSize(16);
    ui->DoctorLoginLabel->setFont(font);

    font = ui->Signin->font();
    font.setPointSize(11);
    ui->Signin->setFont(font);

    font = ui->email->font();
    font.setPointSize(12);
    ui->email->setFont(font);

    font = ui->password->font();
    font.setPointSize(12);
    ui->password->setFont(font);

    font = ui->userlogin->font();
    font.setPointSize(11);
    ui->userlogin->setFont(font);

    ui->widget_2->setStyleSheet("background-color: beige;");

    ui->Signin->setStyleSheet("background-color: #C2B280;");
    ui->userlogin->setStyleSheet("background-color: #C2B280;");


    // Sets the styles for the doctorappointments page.
    font = ui->doctorappointmentslabel->font();
    font.setPointSize(16);
    ui->doctorappointmentslabel->setFont(font);

    ui->doctorappointments->setStyleSheet("background-color: beige;");

    ui->backbutton->setStyleSheet("background-color: #C2B280;");
    ui->logout_2->setStyleSheet("background-color: #C2B280;");
    ui->addappointment->setStyleSheet("background-color: #C2B280;");


    // Sets the styles for the doctormain page.
    ui->doctorCalendarWidget->setNavigationBarVisible(true);
    ui->doctorCalendarWidget->setStyleSheet("color: black;");

    ui->doctormain->setStyleSheet("background-color: beige;");

    ui->logout->setStyleSheet("background-color: #C2B280;");
    ui->todayappt->setStyleSheet("background-color: #C2B280;");


    // Sets the styles for the patientappointments page.
    font = ui->patientappointmentslabel->font();
    font.setPointSize(16);
    ui->patientappointmentslabel->setFont(font);

    ui->patientappointments->setStyleSheet("background-color: beige;");

    ui->backbutton_2->setStyleSheet("background-color: #C2B280;");
    ui->logout_4->setStyleSheet("background-color: #C2B280;");


    // Sets the styles for the patientdateappointment page.
    font = ui->availableappointmentslabel->font();
    font.setPointSize(16);
    ui->availableappointmentslabel->setFont(font);

    ui->widget_4->setStyleSheet("background-color: beige;");

    ui->backbutton_3->setStyleSheet("background-color: #C2B280;");
    ui->logout_5->setStyleSheet("background-color: #C2B280;");


    // Sets the styles for the patientlogin page.
    font = ui->PatientLoginLabel->font();
    font.setPointSize(16);
    ui->PatientLoginLabel->setFont(font);

    font = ui->email_2->font();
    font.setPointSize(12);
    ui->email_2->setFont(font);

    font = ui->password_2->font();
    font.setPointSize(12);
    ui->password_2->setFont(font);

    font = ui->orLabel_2->font();
    font.setPointSize(12);
    ui->orLabel_2->setFont(font);

    font = ui->Signup_2->font();
    font.setPointSize(11);
    ui->Signup_2->setFont(font);

    font = ui->Signin_2->font();
    font.setPointSize(11);
    ui->Signin_2->setFont(font);

    font = ui->doctorlogin_2->font();
    font.setPointSize(11);
    ui->doctorlogin_2->setFont(font);

    ui->patientlogin->setStyleSheet("background-color: beige;");

    ui->Signin_2->setStyleSheet("background-color: #C2B280;");
    ui->Signup_2->setStyleSheet("background-color: #C2B280;");
    ui->doctorlogin_2->setStyleSheet("background-color: #C2B280;");


    // Sets the styles for the patientmain page.
    ui->patientCalendarWidget->setNavigationBarVisible(true);
    ui->patientCalendarWidget->setStyleSheet("color: black;");

    ui->widget_3->setStyleSheet("background-color: beige;");

    ui->logout_3->setStyleSheet("background-color: #C2B280;");
    ui->showallappt->setStyleSheet("background-color: #C2B280;");


    // Sets the styles for the signup page.
    font = ui->confirmpassword->font();
    font.setPointSize(12);
    ui->confirmpassword->setFont(font);

    font = ui->email_3->font();
    font.setPointSize(12);
    ui->email_3->setFont(font);

    font = ui->orLabel_3->font();
    font.setPointSize(12);
    ui->orLabel_3->setFont(font);

    font = ui->password_3->font();
    font.setPointSize(12);
    ui->password_3->setFont(font);

    font = ui->patientsignuplabel->font();
    font.setPointSize(16);
    ui->patientsignuplabel->setFont(font);

    font = ui->createaccount->font();
    font.setPointSize(11);
    ui->createaccount->setFont(font);

    font = ui->backtosignin->font();
    font.setPointSize(11);
    ui->backtosignin->setFont(font);

    ui->signup->setStyleSheet("background-color: beige;");

    ui->backtosignin->setStyleSheet("background-color: #C2B280;");
    ui->createaccount->setStyleSheet("background-color: #C2B280;");


    // Sets the styles for the successfulsignup page.
    font = ui->accountsuccessful->font();
    font.setPointSize(16);
    ui->accountsuccessful->setFont(font);

    font = ui->returnlabel->font();
    font.setPointSize(14);
    ui->returnlabel->setFont(font);

    font = ui->backtosignin_2->font();
    font.setPointSize(11);
    ui->backtosignin_2->setFont(font);

    ui->successfulsignup->setStyleSheet("background-color: beige;");

    ui->backtosignin_2->setStyleSheet("background-color: #C2B280;");

    // Sets the styles for the successfulinsert page.
    font = ui->appointmentssuccessful->font();
    font.setPointSize(16);
    ui->appointmentssuccessful->setFont(font);

    font = ui->returnlabel_2->font();
    font.setPointSize(14);
    ui->returnlabel_2->setFont(font);

    ui->successfulinsert->setStyleSheet("background-color: beige;");

    ui->backtoappointments->setStyleSheet("background-color: #C2B280;");


    // Sets the styles for the insertnewappointment page.
    font = ui->insertlabel->font();
    font.setPointSize(16);
    ui->insertlabel->setFont(font);

    font = ui->endingtime->font();
    font.setPointSize(14);
    ui->endingtime->setFont(font);

    font = ui->startingtime->font();
    font.setPointSize(14);
    ui->startingtime->setFont(font);

    font = ui->tolabel->font();
    font.setPointSize(16);
    ui->tolabel->setFont(font);

    font = ui->timeEdit->font();
    font.setPointSize(16);
    ui->timeEdit->setFont(font);

    font = ui->timeEdit_2->font();
    font.setPointSize(16);
    ui->timeEdit_2->setFont(font);

    ui->insertnewappointment->setStyleSheet("background-color: beige;");

    ui->addappointment2->setStyleSheet("background-color: #C2B280;");
    ui->backbutton_4->setStyleSheet("background-color: #C2B280;");
    ui->logout_6->setStyleSheet("background-color: #C2B280;");
}

/**
 * When the user clicks on the signin button in the Doctor login page, it will validate the email and password then if valid, will send them to the main page of the appointments.
 */
void MainWindow::onSigninClickedDoctor() {
    QString email = ui->emailbox->text();
    QString password = ui->passwordbox->text();

    std::string email_str = email.toStdString();
    std::string password_str = password.toStdString();

    if (validateaccount->accountIsValidDoctor(email_str, password_str)) {
        docid = jsonhandeler->getDoctorID(email_str);
        ui->stackedWidget->setCurrentIndex(3);

    }
    else {
        QMessageBox::information(this, "Error", "Incorrect email or password.");
    }
}

/**
 * Switches to the insert appointments screen for Doctors
 */
void MainWindow::switchToInsertAppointment() {
    ui->stackedWidget->setCurrentIndex(9);
}

/**
 * Switches to the successful insert of appointment for Doctors
 */
void MainWindow::switchToSuccessfulInsert() {
    // gets the values of the times
    QString starting_time = ui->timeEdit->text();
    QString ending_time = ui->timeEdit_2->text();

    // checks if the times are valid for an appointment
    if (!(timehelper->isValidAppointmentTime(starting_time.toStdString(), ending_time.toStdString()))) {
        QMessageBox::information(this, "Error", "Start and end times are invalid for an appointment.");
        return;
    }

    std::string day = timehelper->extractDay(static_date);

    QString dateQString = static_date.toString("yyyy-MM-dd");
    std::string dateString = dateQString.toStdString();
    std::string month = dateString.substr(5,2);

    std::string year = timehelper->extractYear(static_date);
    std::optional<std::list<Appointment>> appointments = jsonhandeler->getAppointmentsDoctor(docid);

    if (appointments) { // if not nullptr
        // loop through all appointments of this doctor
        for (Appointment &appt : *appointments) {
            // if it is not the same date, then skip this appointment
            if (!(day.std::string::compare (appt.getAppointmentDay()) == 0 && month.std::string::compare(appt.getAppointmentMonth()) == 0 && year.std::string::compare(appt.getAppointmentYear()) == 0)) {
                continue;
            }

            // checks if there is a conflict with an existing appointment
            if (!(timehelper->noConflictsTime (starting_time.toStdString(), ending_time.toStdString(), appt.getStartingTime(), appt.getEndingTime()))) {
                QMessageBox::information(this, "Error", "Time conflicts with an existing appointment.");
                return;
            }
        }
    }
    // if no conflicts, then it will add the appointment
    std::string timeslot = timehelper->convertToProperTimeFormat(starting_time.toStdString(), ending_time.toStdString(), static_date);
    availabilitymanager.addDoctorAvailability(docid, timeslot); // adds to json
    ui->stackedWidget->setCurrentIndex(10);
}


/**
 * When the user clicks on the signin button in the Patient login page, it will validate the email and password then if valid, will send them to the main page of the appointments.
 */
void MainWindow::onSigninClickedPatient() {
    QString email = ui->emailbox_2->text();
    QString password = ui->passwordbox_2->text();

    std::string email_str = email.toStdString();
    std::string password_str = password.toStdString();

    // checks if the email and password matches an existing account
    if (validateaccount->accountIsValidPatient(email_str, password_str)) {
        patientid = jsonhandeler->getPatientID(email_str);
        ui->stackedWidget->setCurrentIndex(2);
    }
    else {
        QMessageBox::information(this, "Error", "Incorrect email or password.");
    }
}

/**
 * Switches to the login screen for Doctors
 */
void MainWindow::switchToDoctorLogin() {
    ui->stackedWidget->setCurrentIndex(1);
    ui->emailbox->setText("");
    ui->passwordbox->setText("");
}

/**
 * Switches to the login screen for Patients
 */
void MainWindow::switchToPatientLogin() {
    ui->stackedWidget->setCurrentIndex(0);
    ui->emailbox_2->setText("");
    ui->passwordbox_2->setText("");
}

/**
 * Switches to the page where it lists all the appointments the patient has booked.
 */
void MainWindow::switchToPatientsAppointments() {
    // clear only dynamically created labels and buttons
    for (QObject *child : ui->patientappointments->children()) {
        QWidget *widget = qobject_cast<QWidget *>(child);
        if (widget && widget->objectName().startsWith("label_")) {
            widget->deleteLater(); // delete the list of labels that shows the appointments
        }
        else if (widget && widget->objectName().startsWith ("deletebutton_")) {
            widget->deleteLater(); // deletes the list of delete buttons for each appointment label
        }
    }


    ui->stackedWidget->setCurrentIndex(4);
    std::optional<std::list<Appointment>> patient_appointments = jsonhandeler->getAppointmentsPatient(patientid);

    if (patient_appointments) { // if not nullptr
        int y_offset = 140;

        // loop through all appointments of this patient
        for (Appointment &appt : *patient_appointments) {
            // gets the year month and day of the appointment
            std::string year = appt.getAppointmentYear();
            std::string month = appt.getAppointmentMonth();
            std::string day = appt.getAppointmentDay();

            std::string starting_time = appt.getStartingTime();
            std::string ending_time = appt.getEndingTime();

            // converts the starting and end time to 12h format
            std::string starting_time_12h = timehelper->convertTo12HFormat(starting_time);
            std::string ending_time_12h = timehelper->convertTo12HFormat(ending_time);

            // turns the extracted month (initially the number month) into the word month (ex. 11 would turn to November)
            std::string month_string = timehelper->extractMonthFromString(month);

            // the value of the label to show
            std::string appointment_label = month_string + " " + day + ", " + year + "\t\t " + starting_time_12h + "   ——   " + ending_time_12h;
            QString appointment_labelQ = QString::fromStdString(appointment_label);
            QLabel *label = new QLabel(appointment_labelQ, ui->patientappointments);
            label->setObjectName("label_" + QString::number(appt.getAppointmentID()));
            label->setStyleSheet("font-size: 12px; letter-spacing: 5px;");
            label->show();
            label->move(100, y_offset);
            label->raise();

            // create a button that cancels the linked appointment
            QPushButton *deletebutton = new QPushButton ("X", ui->patientappointments);
            deletebutton->setObjectName("deletebutton_" + QString::number(appt.getAppointmentID()));
            deletebutton->setGeometry(690, y_offset - 10, 30, 30);
            deletebutton->setStyleSheet("background-color: #C2B280;");

            QObject::connect(deletebutton, &QPushButton::clicked, [this, appt]() {
                appointmentmanager->cancelAppointmentPatient(appt.getAppointmentID());
                switchToPatientsAppointments();
            });
            deletebutton->show();

            y_offset += 35;
        }
    }
}

/**
 * Switches back to the main screen for the Doctor appointments page.
 */
void MainWindow::backToDoctorCalendar() {
    ui->stackedWidget->setCurrentIndex(3);
}

/**
 * Switches back to the main screen for the Patient appointments page.
 */
void MainWindow::backToPatientCalendar() {
    ui->stackedWidget->setCurrentIndex(2);
}

/**
 * Switches when the account creation has been successful.
 */
void MainWindow::switchToSuccessfulCreationPage () {
    // gets the inputted info from the boxes
    QString email =  ui->emailbox_3->text();
    QString password = ui->passwordbox_3->text();
    QString password2 = ui->passwordbox_4->text();

    // converts it to string
    std::string email_str = email.toStdString();
    std::string password_str = password.toStdString();
    std::string password2_str = password2.toStdString();

    // if the email is of a valid pattern, if it isn't, throw an info box and do not change screens
    if (!validateaccount->emailIsValid(email_str)) {
        QMessageBox::information(this, "Error", "The email is invalid.");
        return;
    }

    // if the password is empty
    if (!validateaccount->passwordIsValid(password_str)) {
        QMessageBox::information(this, "Error", "The password cannot be empty.");
        return;
    }

    // if the passwords do not match, throw an info box and do not change screens
    if (password_str.std::string::compare(password2_str) != 0) {
        QMessageBox::information(this, "Error", "The passwords do not match.");
        return;
    }
    else {
        // if the email does not exist within the database
        if (!validateaccount->emailExists(email_str)) {

            Patient new_account (email_str, password_str, true); // create a new account

            ui->stackedWidget->setCurrentIndex(7);
        }
        // if an account with this email already exists
        else {
            QMessageBox::information(this, "Error", "An account with this email already exists.");
            return;
        }
    }
}

/**
 * Switches to the page that lists all appointments that patients have made for that particular doctor on that specific date and allows Doctor to create create appointments.
 */
void MainWindow::doctorDateClicked(const QDate &date) {
    ui->stackedWidget->setCurrentIndex (5);
    loadDateToLabelDoctor(date);
    static_date = date;
}

/**
 * Switches to the page that lists all appointments that patients have made for that particular doctor. Used for going back to their previous date clicked.
 */
void MainWindow::doctorDateClicked2() {
    ui->stackedWidget->setCurrentIndex (5);
    loadDateToLabelDoctor(static_date);
}

/**
 * Switches to the page that lists all appointments booked and appointments available for that specific date.
 */
void MainWindow::patientDateClicked(const QDate &date) {
    // switches to the screen
    static_date = date;
    ui->stackedWidget->setCurrentIndex(8);
    loadDateToLabelPatient(date);


    // clear only dynamically created labels and buttons
    for (QObject *child : ui->patientdateappointment->children()) {
        QWidget *widget = qobject_cast<QWidget *>(child);
        if (widget && widget->objectName().startsWith("label_")) {
            widget->deleteLater(); // deletes appointment label
        }
        else if (widget && widget->objectName().startsWith ("cancelbutton_")) {
            widget->deleteLater(); // deletes the button that deletes the appointment
        }
        else if (widget && widget->objectName().startsWith ("bookbutton_")) {
            widget->deleteLater(); // deletes the button that books the appointment
        }
    }

    // extracts the day month and year of the selected date
    std::string day = timehelper->extractDay(date);
    std::string month = timehelper->extractMonth(date);
    std::string year = timehelper->extractYear(date);

    QJsonArray jsonArray = jsonhandeler->getAppointmentsFromJson();

    int y_offset = 140;
    std::list<QJsonObject> available_appointments; // stores only appointments relevant to the patient. ex. available appointments on that date and booked appointments (booked by this patient) on that date

    // loops through the json file
    for (const QJsonValue &appointment : jsonArray) {
        // for each object in the json
        if (appointment.isObject()) {
            QJsonObject element = appointment.toObject();

            // gets the info from the json object
            int doctor_id_element = element["doctor_id"].toInt();
            int appointment_id_element = element["appointment_id"].toInt();
            int patient_id_element = element["patient_id"].toInt();
            QString timeslot_element = element["timeslot"].toString();
            std::string timeslot_str = timeslot_element.toStdString ();

            Appointment appointment (appointment_id_element, doctor_id_element, patient_id_element, timeslot_str); // creates an appointment instance to allow for easier info extraction

            // if the date of this appointment matches the clicked on date
            if (day.std::string::compare(appointment.getAppointmentDay()) == 0 && month.std::string::compare(timehelper->extractMonthFromString(appointment.getAppointmentMonth())) == 0 && year.std::string::compare(appointment.getAppointmentYear()) == 0) {
                // if the appointment is available
                if (patient_id_element == -1) {
                    bool found = false;

                    // ensures there is no such appointment already in the list
                    for (const QJsonObject &appt : available_appointments) {
                        if (appt["appointment_id"].toInt() == appointment_id_element) {
                            found = true;
                        }
                    }
                    // add to list
                    if (!found) {
                        available_appointments.push_back(element);
                    }
                }
                // if the appointment is booked by this patient
                else if (patient_id_element == patientid) {
                    // remove the appointment of this id in the list, as that shows it is an available appointment
                    for (const QJsonObject &appt : available_appointments) {
                        if (appt["appointment_id"].toInt() == appointment_id_element) {
                            available_appointments.remove(appt);
                            break;
                        }
                    }
                    // add the booked appointment to list
                    available_appointments.push_back(element);
                }
                // if the appointment is booked and is not booked by this patient, remove it from the list
                else {
                    available_appointments.remove(element);
                }
            }
        }
    }

    // loops through the appointments only relevant to the patient
    for (const QJsonObject &appointment : available_appointments) {
        // extracts the information from each object
        int doctor_id_element = appointment["doctor_id"].toInt();
        int appointment_id_element = appointment["appointment_id"].toInt();
        int patient_id_element = appointment["patient_id"].toInt();
        QString timeslot_element = appointment["timeslot"].toString();
        std::string timeslot_str = timeslot_element.toStdString ();

        // creates an instance of appointment for easier data extraction
        Appointment appointment_instance (appointment_id_element, doctor_id_element, patient_id_element, timeslot_str);

        // gets the times of the appointment
        std::string starting_time = appointment_instance.getStartingTime();
        std::string ending_time = appointment_instance.getEndingTime();

        // converts the times into 12h format
        std::string starting_time_12h = timehelper->convertTo12HFormat(starting_time);
        std::string ending_time_12h = timehelper->convertTo12HFormat(ending_time);

        std::string appointment_label;
        bool isbooked = false;

        // if the appointment is booked
        if (jsonhandeler->appointmentIsBooked(appointment_id_element)) {
            appointment_label = "BOOKED\t\t" + starting_time_12h + "   ——   " + ending_time_12h;
            isbooked = true;
        }
        // if the appointment is available
        else {
            appointment_label = "AVAILABLE\t" + starting_time_12h + "   ——   " + ending_time_12h;
        }


        // creates a label of the appointment
        QString appointment_labelQ = QString::fromStdString(appointment_label);
        QLabel *label = new QLabel(appointment_labelQ, ui->patientdateappointment);
        label->setObjectName("label_" + QString::number(appointment_instance.getAppointmentID()));
        label->setStyleSheet("font-size: 12px; letter-spacing: 5px;");
        label->show();
        label->move(120, y_offset);
        label->raise();

        // if the appointment is booked, create a cancel appointment button
        if (isbooked) {
            QPushButton *cancelbutton = new QPushButton ("X", ui->patientdateappointment);
            cancelbutton->setObjectName("cancelbutton_" + QString::number(appointment_instance.getAppointmentID()));
            cancelbutton->setGeometry(710, y_offset - 10, 30, 30);
            cancelbutton->setStyleSheet("background-color: #C2B280;");

            QObject::connect(cancelbutton, &QPushButton::clicked, [this, appointment_instance]() {
                availabilitymanager.cancelBooking(appointment_instance.getAppointmentID());
                patientDateClicked(static_date);
            });

            cancelbutton->show();
        }
        // if the appointment is not booked, create a book appointment button
        else {
            QPushButton *bookbutton = new QPushButton ("Book Appointment", ui->patientdateappointment);
            bookbutton->setObjectName("bookbutton_" + QString::number(appointment_instance.getAppointmentID()));
            bookbutton->setGeometry(550, y_offset - 10, 150, 30);
            bookbutton->setStyleSheet("background-color: #C2B280;");

            QObject::connect(bookbutton, &QPushButton::clicked, [this, appointment_instance]() {
                appointmentmanager->createAppointment(appointment_instance.getDoctorID(), patientid, appointment_instance.getTimeslot());
                patientDateClicked(static_date);

            });

            bookbutton->show();
        }
        y_offset += 35;
    }
}

/**
 * Switches to the signup page.
 */
void MainWindow::switchToSignUp () {
    ui->stackedWidget->setCurrentIndex(6);

    // resets all the text inputs
    ui->emailbox_3->setText("");
    ui->passwordbox_3->setText("");
    ui->passwordbox_4->setText("");
}

/**
 * Will extract the date from the calendar that the Doctor has clicked on and load that data for the next page to use.
 *
 * @param date      The date that the Doctor has clicked on.
 */
void MainWindow::loadDateToLabelDoctor (const QDate &date) {
    // clear only dynamically created labels and buttons
    for (QObject *child : ui->doctorappointments->children()) {
        QWidget *widget = qobject_cast<QWidget *>(child);
        if (widget && widget->objectName().startsWith("label_")) {
            widget->deleteLater(); // delete the appointment label
        }
        else if (widget && widget->objectName().startsWith("deletebutton_")) {
            widget->deleteLater(); // delete the delete appointment button
        }
        else if (widget && widget->objectName().startsWith ("cancelbutton_")) {
            widget->deleteLater();  // delete the cancel appointment button
        }
    }

    // extracts the day month and year from the clicked date
    std::string day = timehelper->extractDay(date);
    std::string month = timehelper->extractMonth(date);
    std::string year = timehelper->extractYear(date);

    std::string label_text = "APPOINTMENTS FOR " + month + " " + day + ", " + year;
    QString label_textQ = QString::fromStdString(label_text);

    ui->doctorappointmentslabel->setText(label_textQ);

    // gets all appointments
    QJsonArray jsonArray = jsonhandeler->getAppointmentsFromJson();

    int y_offset = 140;
    std::list<int> booked_appointments; // list that stores the id of all booked appointments

    // loops through the json file
    for (const QJsonValue &appointment : jsonArray) {
        // for each object in the json
        if (appointment.isObject()) {
            // extracts the information from the appointment
            QJsonObject element = appointment.toObject();
            int doctor_id_element = element["doctor_id"].toInt();
            int appointment_id_element = element["appointment_id"].toInt();
            int patient_id_element = element["patient_id"].toInt();
            QString timeslot_element = element["timeslot"].toString();
            std::string timeslot_str = timeslot_element.toStdString ();

            // creates an appointment instance for easier data extraction
            Appointment appointment (appointment_id_element, doctor_id_element, patient_id_element, timeslot_str);
            bool skip_element = false;

            // if the appointment is already within the list, no need to duplicate adding it to screen
            for (int id : booked_appointments) {
                if (id == appointment.getAppointmentID()) {
                    skip_element = true;
                    break;
                }
            }

            // if the appointment is on the clicked on date
            if (!skip_element && day.std::string::compare(appointment.getAppointmentDay()) == 0 && month.std::string::compare(timehelper->extractMonthFromString(appointment.getAppointmentMonth())) == 0 && year.std::string::compare(appointment.getAppointmentYear()) == 0 && docid == doctor_id_element) {
                // gets the times of the appointment
                std::string starting_time = appointment.getStartingTime();
                std::string ending_time = appointment.getEndingTime();

                // converts the times to 12h format
                std::string starting_time_12h = timehelper->convertTo12HFormat(starting_time);
                std::string ending_time_12h = timehelper->convertTo12HFormat(ending_time);

                std::string appointment_label;
                bool isbooked = false;

                // if the appointment is booked
                if (jsonhandeler->appointmentIsBooked(appointment_id_element)) {
                    appointment_label = "BOOKED\t\t" + starting_time_12h + "   ——   " + ending_time_12h;
                    booked_appointments.push_back(appointment.getAppointmentID()); // add it to list
                    isbooked = true;
                }
                // if the appointment is available
                else {
                    appointment_label = "AVAILABLE\t" + starting_time_12h + "   ——   " + ending_time_12h;
                }

                // create a label to display to screen
                QString appointment_labelQ = QString::fromStdString(appointment_label);
                QLabel *label = new QLabel(appointment_labelQ, ui->doctorappointments);
                label->setObjectName("label_" + QString::number(appointment.getAppointmentID()));
                label->setStyleSheet("font-size: 12px; letter-spacing: 5px;");
                label->show();
                label->move(120, y_offset);
                label->raise();

                // create a button that deletes the linked appointment
                QPushButton *deletebutton = new QPushButton ("X", ui->doctorappointments);
                deletebutton->setObjectName("deletebutton_" + QString::number(appointment.getAppointmentID()));
                deletebutton->setGeometry(710, y_offset - 10, 30, 30);
                deletebutton->setStyleSheet("background-color: #C2B280;");

                QObject::connect(deletebutton, &QPushButton::clicked, [this, appointment]() {
                    availabilitymanager.remDoctorAvailability(appointment.getDoctorID(), appointment.getTimeslot());
                    loadDateToLabelDoctor(static_date);

                });
                deletebutton->show();

                // create a button that cancels the linked appointment
                if (isbooked) {
                    QPushButton *cancelbutton = new QPushButton ("Cancel Patient's Booking", ui->doctorappointments);
                    cancelbutton->setObjectName("cancelbutton_" + QString::number(appointment.getAppointmentID()));
                    cancelbutton->setGeometry(550, y_offset - 10, 150, 30);
                    cancelbutton->setStyleSheet("background-color: #C2B280;");

                    QObject::connect(cancelbutton, &QPushButton::clicked, [this, appointment]() {
                        appointmentmanager->cancelAppointment(appointment.getAppointmentID());
                        loadDateToLabelDoctor(static_date);
                    });
                    cancelbutton->show();
                }

                y_offset += 35;
            }
        }
    }
}

/**
 * Will extract the date from the calendar that the Patient has clicked on and load that data for the next page to use.
 *
 * @param date      The date that the Patient has clicked on.
 */
void MainWindow::loadDateToLabelPatient (const QDate &date) {
    std::string day = timehelper->extractDay(date);
    std::string month = timehelper->extractMonth(date);
    std::string year = timehelper->extractYear(date);

    std::string label_text = "APPOINTMENTS FOR " + month + " " + day + ", " + year;
    QString label_textQ = QString::fromStdString(label_text);

    ui->availableappointmentslabel->setText(label_textQ);
}

/**
 * Using the current date, will load that data for the next page to use (to show the appointments the doctor has on that day).
 */
void MainWindow::todayAppointments () {
    std::string current_date = timehelper->getCurrTime();
    ui->stackedWidget->setCurrentIndex (5);

    QDate date = QDate::fromString(QString::fromStdString(current_date), "yyyy-MM-dd");
    static_date = date;

    loadDateToLabelDoctor(date);
}


MainWindow::~MainWindow()
{
    delete ui;
}
