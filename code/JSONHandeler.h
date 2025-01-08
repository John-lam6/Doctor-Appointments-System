#ifndef JSONHANDELER_H
#define JSONHANDELER_H

#include <string>
#include <list>
#include <array>
#include <optional>
#include "Doctor.h"
#include "Appointment.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QMessageBox>
#include <QMutex>
#include <QMutexLocker>

class Patient;


/*
Singleton class that recieves instructions from other classes which prompts the class to read/modify data in the respective json file(s)
*/

class JSONHandeler {
public:

    //Below lines prevent copying and assignment, unedecided currentlly on their usefulness or necessity
    //JSONHandeler(const JSONHandeler&) = delete;
    //JSONHandeler& operator=(const JSONHandeler&) = delete;

    static JSONHandeler* getInstance();

    //Various getters/specific data extraction
    Patient getPatient(int patientid);
    Patient getPatient(std::string name);
    Doctor getDoctor(int doctorid);
    Doctor getDoctor(std::string name);

    std::optional<Appointment> getAppointment(int appointmentid);
    std::optional<std::list<Appointment>> getAppointmentsDoctor(int doctorid);
    std::optional<std::list<Appointment>> getAppointmentsPatient(int patientid);

    QJsonArray getAppointmentsFromJson ();

    //Add needed public methods here (they should never alter the jsons directly, use private methods to do so)

    bool getEmail(std::string email);
    bool checkAuth(std::array<std::string, 2> auth);
    bool checkAuth(std::string email, std::string password);

    bool checkAuthDoctor(std::string email, std::string password);
    bool checkAuthPatient(std::string email, std::string password);

    void addAccount (int addAccount, std::string email, std::string password);

    int getNextPatientID();
    int getNextAppointmentID();

    int getPatientID (std::string email);
    int getDoctorID (std::string email);
    bool appointmentIsBooked(int appointmentID);

    void addAppointment(int appointmentid, int doctorid, int patientid, std::string timeslot);
    bool remAppointment(int appointmentid);
    bool cancelAppointment (int appointmentid);
    bool remAppointmentPatient(int appointmentid);


private:
    //Private constructor and destructor to align with the singleton pattern, preventing instantiation
    JSONHandeler();
    ~JSONHandeler();

    std::string patientsFilePath;
    std::string doctorsFilePath;
    std::string authFilePath;
    std::string appointmentsFilePath;

    static JSONHandeler* instance;

    //static QMutex doctorJsonMutex;
    static QMutex patientJsonMutex;
    static QMutex appointmentsJsonMutex;
};

#endif // JSONHANDELER_H
