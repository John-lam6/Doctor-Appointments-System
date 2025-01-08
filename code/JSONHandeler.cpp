#include "JSONHandeler.h"

#include "Patient.h"
#include <QDir>

JSONHandeler* JSONHandeler::instance = nullptr;
QMutex JSONHandeler::patientJsonMutex; // allows for only 1 user writing or reading the patient json at a time to ensure data integrity.
QMutex JSONHandeler::appointmentsJsonMutex; // allows for only 1 user writing or reading the appointments json at a time to ensure data integrity.

/**
 * Returns the singleton instance of the class.
 *
 * @return  The single instance of the class.
 */
JSONHandeler* JSONHandeler::getInstance() {
    if (instance == nullptr) {
        instance = new JSONHandeler();
    }
    return instance;
}

/**
 * The constructor. Sets the file paths of the json files
 */
JSONHandeler::JSONHandeler()
    : patientsFilePath("patients.json"),
    doctorsFilePath("doctors.json"),
    appointmentsFilePath("appointments.json") {
}


JSONHandeler::~JSONHandeler() {

}


/**
 * Gets the next unique id for patient.
 *
 * @return      The next unique id for patient.
 */
int JSONHandeler::getNextPatientID () {
    // lock the patients json because it is reading.
    QMutexLocker locker (&patientJsonMutex);

    // open the file for reading
    QFile file(QString::fromStdString(patientsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return -1;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return -1;
    }


    int largest_id = 0;

    // loops through all the objects in the json file
    for (const QJsonValue &account : jsonArray) {
        if (account.isObject()) {
            QJsonObject element = account.toObject();
            int id_int = element["patient_id"].toInt();

            // if the current id is larger than the current largest id
            if (id_int > largest_id) {
                // set the largest int to the current id
                largest_id = id_int;
            }
        }
    }

    return largest_id + 1;
}

/**
 * Gets the next unique id for appointment.
 *
 * @return      The next unique id for appointment.
 */
int JSONHandeler::getNextAppointmentID () {
    // lock the appointments json because it is reading.
    QMutexLocker locker (&appointmentsJsonMutex);

    // open the file for reading
    QFile file(QString::fromStdString(appointmentsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return -1;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return -1;
    }


    int largest_id = 0;

    // loops through all the objects in the json file
    for (const QJsonValue &account : jsonArray) {
        if (account.isObject()) {
            QJsonObject element = account.toObject();
            int id_int = element["appointment_id"].toInt();

            // if the current id is larger than the current largest id
            if (id_int > largest_id) {
                // set the largest int to the current id
                largest_id = id_int;
            }
        }
    }

    return largest_id + 1;
}

/**
 * Checks if the email already is connected to a patient account. True if it is, false otherwise.
 *
 * @param email     The email to check if it is associated with a patient account.
 * @return          True if the email is associated with a patient account, false otherwise.
 */
bool JSONHandeler::getEmail(std::string email) {
    // lock the patients json because it is reading.
    QMutexLocker locker (&patientJsonMutex);

    // open the file for reading
    QFile file(QString::fromStdString(patientsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return false;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return false;
    }


    bool email_exists = false;

    // loops through all the objects in the json file
    for (const QJsonValue &account : jsonArray) {
        if (account.isObject()) {
            QJsonObject element = account.toObject();
            QString email_element = element["email"].toString();
            std::string email_str = email_element.toStdString ();

            // checks if the account with that email exists
            if (email_str.compare(email) == 0) {
                // if account exists
                email_exists = true;
                break;
            }
        }
    }
    return email_exists;
}

/**
 * Checks if an account with the given email and password exists. True if it exists, False otherwise.
 *
 * @param email         The email associated with the account.
 * @param password      The password associated with the account.
 * @return              True if it exists, false otherwise.
 */
bool JSONHandeler::checkAuthDoctor(std::string email, std::string password) {
    // don't need to lock the doctor json because there will never be a write in the json file (no signup function for doctor, as it should only be given when a new doctor
    // arrives, that is when an admin creates a new account for them).

    // open the file for reading
    QFile file(QString::fromStdString(doctorsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return false;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return false;
    }


    bool account_exists = false;

    // loops through the json file
    for (const QJsonValue &account : jsonArray) {
        // for each object in the json
        if (account.isObject()) {
            // gets the email and password of the object and compares it to the entered email and password.
            QJsonObject element = account.toObject();
            QString email_element = element["email"].toString();
            QString password_element = element["password"].toString();
            std::string email_str = email_element.toStdString ();
            std::string password_str = password_element.toStdString ();

            // checks if the account exists
            if (email_str.compare(email) == 0 && password_str.compare(password) == 0) {
                // if account exists
                account_exists = true;
                break;
            }
        }
    }

    return account_exists;
}

/**
 * Checks if an account with the given email and password exists. True if it exists, False otherwise.
 *
 * @param email         The email associated with the account.
 * @param password      The password associated with the account.
 * @return              True if it exists, false otherwise.
 */
bool JSONHandeler::checkAuthPatient(std::string email, std::string password) {
    // lock the patients json because it is reading.
    QMutexLocker locker (&patientJsonMutex);

    // open the file for reading
    QFile file(QString::fromStdString(patientsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return false;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return false;
    }


    bool account_exists = false;

    // loops through the json file
    for (const QJsonValue &account : jsonArray) {
        // for each object in the json
        if (account.isObject()) {
            // gets the email and password of the object and compares it to the entered email and password.
            QJsonObject element = account.toObject();
            QString email_element = element["email"].toString();
            QString password_element = element["password"].toString();
            std::string email_str = email_element.toStdString ();
            std::string password_str = password_element.toStdString ();
            // checks if the account exists
            if (email_str.std::string::compare(email) == 0 && password_str.std::string::compare(password) == 0) {
                // if account exists
                account_exists = true;
                break;
            }
        }
    }
    return account_exists;
}


/**
 * Checks if an appointment is booked with the given appointment id. True if it is booked, False otherwise.
 *
 * @param appointmentID     The id of the appointment
 * @return                  True if it is booked, false otherwise.
 */
bool JSONHandeler::appointmentIsBooked(int appointmentID) {
    // lock the patients json because it is reading.
    QMutexLocker locker (&appointmentsJsonMutex);

    // open the file for reading
    QFile file(QString::fromStdString(appointmentsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return false;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return false;
    }

    bool first_appointment = false;

    // loops through the json file
    for (const QJsonValue &account : jsonArray) {
        // for each object in the json
        if (account.isObject()) {
            // gets the appointment id of the json object
            QJsonObject element = account.toObject();
            int id_element = element["appointment_id"].toInt();

            // checks if the appointment id matches
            if (appointmentID == id_element) {
                // if there are 2 appointments, that means a patient booked it
                if (first_appointment == false) {
                    first_appointment = true;
                }
                else {
                    return true;
                }
            }
        }
    }
    return false;
}

/**
 * Creates a patient account, and adds it to the patients json.
 *
 * @param patient_id    The patient id.
 * @param email         The email to link the account with.
 * @param password      The password to allow the account to connect.
 */
void JSONHandeler::addAccount (int patient_id, std::string email, std::string password) {
    // lock the patients json because it is writing.
    QMutexLocker locker (&patientJsonMutex);

    // open the file for reading
    QFile file(QString::fromStdString(patientsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return;
    }

    // creates a new json object to be inserted
    QJsonObject newAccount;
    newAccount["patient_id"] = patient_id;
    newAccount["email"] = QString::fromStdString (email);
    newAccount["password"] = QString::fromStdString (password);

    // add the new object to the json array
    jsonArray.append (newAccount);

    // try and open the json file for writing
    if (!file.open (QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing.";
        return;
    }

    // update the json file and write
    jsonDocument.setArray (jsonArray);
    file.write (jsonDocument.toJson (QJsonDocument::Indented)); // indented for better readability
    file.close();
}

/**
 * Gets the data of the appointments JSON.
 *
 * @return      The JSON array for the appointments JSON
 */
QJsonArray JSONHandeler::getAppointmentsFromJson () {
    // lock the appointments json because it is writing.
    QMutexLocker locker (&appointmentsJsonMutex);

    // open the file for reading
    QFile file(QString::fromStdString(appointmentsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return QJsonArray(); // return an empty JSONArray
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
        return jsonArray;
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return QJsonArray(); // return an empty JSONArray
    }
}

/**
 * Returns the patient id that corresponds to the account linked with the given email.
 *
 * @param email     The email that is linked with the account.
 * @return          The patient id that corresponds to the respective account.
 */
int JSONHandeler::getPatientID (std::string email) {
    // lock the patients json because it is reading.
    QMutexLocker locker (&patientJsonMutex);

    // open the file for reading
    QFile file(QString::fromStdString(patientsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return false;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return false;
    }

    // loops through the json file
    for (const QJsonValue &account : jsonArray) {
        // for each object in the json
        if (account.isObject()) {
            // finds the account with the given email.
            QJsonObject element = account.toObject();
            QString email_element = element["email"].toString();
            int id_element = element["patient_id"].toInt();
            std::string email_str = email_element.toStdString ();
            if (email_str.std::string::compare(email) == 0) {
                // if account exists, return the id
                return id_element;
            }
        }
    }
    return -1;
}

/**
 * Returns the doctor id that corresponds to the account linked with the given email.
 *
 * @param email     The email that is linked with the account.
 * @return          The doctor id that corresponds to the respective account.
 */
int JSONHandeler::getDoctorID (std::string email) {
    // don't need to lock the doctor json because there will never be a write in the json file (no signup function for doctor, as it should only be given when a new doctor
    // arrives, that is when an admin creates a new account for them).

    // open the file for reading
    QFile file(QString::fromStdString(doctorsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return false;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return false;
    }

    // loops through the json file
    for (const QJsonValue &account : jsonArray) {
        // for each object in the json
        if (account.isObject()) {
            // finds an account with the given email
            QJsonObject element = account.toObject();
            QString email_element = element["email"].toString();
            int id_element = element["doctor_id"].toInt();
            std::string email_str = email_element.toStdString ();
            if (email_str.std::string::compare(email) == 0) {
                // if account exists, return the doc id
                return id_element;
            }
        }
    }
    return -1;
}

/**
 * Returns an appointment with the given appointment id.
 *
 * @param appointmentid     The id of the appointment to search for through the json.
 * @return                  An appointment with the given appointment id (if it exists)
 */
std::optional<Appointment> JSONHandeler::getAppointment(int appointmentid) {
    // open the file for reading
    QFile file(QString::fromStdString(appointmentsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return std::nullopt;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return std::nullopt;
    }

    // loops through all the objects in the json file
    for (const QJsonValue &appointment : jsonArray) {
        if (appointment.isObject()) {
            QJsonObject element = appointment.toObject();
            int appointmentid_element = element["appointment_id"].toInt();

            // if the appointment id of this appointment is the same as the parameter id
            if (appointmentid_element == appointmentid) {
                // create an instance and return it
                Appointment output(appointmentid_element, element["doctor_id"].toInt(), element["patient_id"].toInt(), element["timeslot"].toString().toStdString());
                return output;
            }
        }
    }
    return std::nullopt;
}

/**
 * Returns a list of appointments that is associated with the doctor.
 *
 * @param doctorid      The doctor to find appointments associated with them.
 * @return              Returns a list of appointments that is associated with the doctor.
 */
std::optional<std::list<Appointment>> JSONHandeler::getAppointmentsDoctor(int doctorid) {
    // open the file for reading
    QFile file(QString::fromStdString(appointmentsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return std::nullopt;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return std::nullopt;
    }

    std::list<Appointment> output;

    // loops through the appointments
    for (const QJsonValue &appointment : jsonArray) {
        if (appointment.isObject()) {
            QJsonObject element = appointment.toObject();
            int doctorid_element = element["doctor_id"].toInt();

            // if the doctor id of this appointment is the same as the given doctor id, add it to the list
            if (doctorid_element == doctorid) {
                Appointment appoint(element["appointment_id"].toInt(), doctorid_element, element["patient_id"].toInt(), element["timeslot"].toString().toStdString());
                output.push_back(appoint);
            }
        }
    }
    // return the list.
    return output;
}

/**
 * Returns a list of appointments that is associated with the patient.
 *
 * @param doctorid      The patient to find appointments associated with them.
 * @return              Returns a list of appointments that is associated with the patient.
 */
std::optional<std::list<Appointment>> JSONHandeler::getAppointmentsPatient(int patientid) {
    // open the file for reading
    QFile file(QString::fromStdString(appointmentsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return std::nullopt;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return std::nullopt;
    }

    std::list<Appointment> output;

    for (const QJsonValue &appointment : jsonArray) {
        if (appointment.isObject()) {
            QJsonObject element = appointment.toObject();
            int patientid_element = element["patient_id"].toInt();

            // if the patient id of this appointment is the same as the given patient id, add it to the list
            if (patientid_element == patientid) {
                Appointment appoint(element["appointment_id"].toInt(), element["doctor_id"].toInt(), patientid_element, element["timeslot"].toString().toStdString());
                output.push_back(appoint);
            }
        }
    }
    return output;
}

/**
 * Adds the following appointment info to the JSON file.
 *
 * @param appointmentid     id of the appointment.
 * @param doctorid          id of the doctor.
 * @param patientid         id of the patient.
 * @param timeslot          timeslot of the appointment.
 */
void JSONHandeler::addAppointment(int appointmentid, int doctorid, int patientid, std::string timeslot) {
    QMutexLocker locker (&appointmentsJsonMutex);
    // open the file for reading
    QFile file(QString::fromStdString(appointmentsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return;
    }

    // sets the new jsonobject's info
    QJsonObject newAppointment;
    newAppointment["appointment_id"] = appointmentid;
    newAppointment["doctor_id"] = doctorid;
    newAppointment["patient_id"] = patientid;
    newAppointment["timeslot"] = QString::fromStdString(timeslot);

    // adds it to the json array
    jsonArray.append(newAppointment);

    if (!file.open (QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing.";
        return;
    }
    // update the json file and write
    jsonDocument.setArray (jsonArray);
    file.write (jsonDocument.toJson (QJsonDocument::Indented)); // indented for better readability
    file.close();
}

/**
 * Deletes an appointment from the system.
 *
 * @param appointmentid     The id of the appointment to delete.
 * @return                  True if it is successful, false otherwise.
 */
bool JSONHandeler::remAppointment(int appointmentid) {
    QMutexLocker locker (&appointmentsJsonMutex);
    // open the file for reading
    QFile file(QString::fromStdString(appointmentsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return false;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return false;
    }

    QJsonArray newarray;
    // loops through all the appointments
    for (const QJsonValue &appointment : jsonArray) {
        if (appointment.isObject()) {
            QJsonObject element = appointment.toObject();
            int appointmentid_element = element["appointment_id"].toInt();

            // if the current appointment's id is the same as the parameter, remove it
            if (appointmentid_element == appointmentid) {
                continue;
            }
            newarray.append(appointment);
        }
    }

    if (!file.open (QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing.";
        return false;
    }
    // update the json file and write
    jsonDocument.setArray (newarray);
    file.write (jsonDocument.toJson (QJsonDocument::Indented)); // indented for better readability
    file.close();
    return true;
}

/**
 * Removes the booking from a patient.
 *
 * @param appointmentid     The id of the appointment to cancel.
 * @return                  True if it removed successfully, false otherwise.
 */
bool JSONHandeler::cancelAppointment (int appointmentid) {

    QMutexLocker locker (&appointmentsJsonMutex);
    // open the file for reading
    QFile file(QString::fromStdString(appointmentsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return false;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return false;
    }

    QJsonArray newarray;
    // loops through all the appointments
    for (const QJsonValue &appointment : jsonArray) {
        if (appointment.isObject()) {
            QJsonObject element = appointment.toObject();
            int appointmentid_element = element["appointment_id"].toInt();
            int patient_id_element = element["patient_id"].toInt();
            // if the appointment id is the same as the given appointment id, and it is not an appointment created by the doctor, remove from the system
            if (appointmentid_element == appointmentid && patient_id_element != -1) {
                continue;
            }
            newarray.append(appointment);
        }
    }

    if (!file.open (QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing.";
        return false;
    }
    // update the json file and write
    jsonDocument.setArray (newarray);
    file.write (jsonDocument.toJson (QJsonDocument::Indented)); // indented for better readability
    file.close();
    return true;
}

/**
 * Removes the booking from a patient.
 *
 * @param appointmentid     The id of the appointment to cancel.
 * @return                  True if it removed successfully, false otherwise.
 */
bool JSONHandeler::remAppointmentPatient(int appointmentid) {
    QMutexLocker locker (&appointmentsJsonMutex);
    // open the file for reading
    QFile file(QString::fromStdString(appointmentsFilePath));
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "Failed to open file for reading.";
        return false;
    }

    QByteArray fileData = file.readAll();
    file.close();

    QJsonDocument jsonDocument = QJsonDocument::fromJson(fileData);
    QJsonArray jsonArray;

    // if the json holds array
    if (jsonDocument.isArray()) {
        jsonArray = jsonDocument.array();
    }
    // if the json holds an object (no square brackets), exit
    else {
        qDebug() << "JSON file is not an array.";
        return false;
    }

    QJsonArray newarray;
    // loops through all the appointments
    for (const QJsonValue &appointment : jsonArray) {
        if (appointment.isObject()) {
            QJsonObject element = appointment.toObject();
            int appointmentid_element = element["appointment_id"].toInt();

            // if the appointment id is the same as the given appointment id, and it is not an appointment created by the doctor, remove from the system
            if (appointmentid_element == appointmentid && element["patient_id"] != -1) {
                continue;
            }
            newarray.append(appointment);
        }
    }

    if (!file.open (QIODevice::WriteOnly)) {
        qDebug() << "Failed to open file for writing.";
        return false;
    }
    // update the json file and write
    jsonDocument.setArray (newarray);
    file.write (jsonDocument.toJson (QJsonDocument::Indented)); // indented for better readability
    file.close();
    return true;
}
