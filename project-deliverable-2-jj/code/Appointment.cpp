#include "Appointment.h"
#include "JSONHandeler.h"

// initialize static variable
JSONHandeler* Appointment::jsonhandeler = JSONHandeler::getInstance();
int Appointment::nextId = jsonhandeler->getNextAppointmentID();

/**
 *  Constructor for Appointment. Creates an appointment with a patient, a doctor and a given timeslot.
 *
 * @param doctorid          ID of doctor
 * @param patientid         ID of patient
 * @param theTimeslot       Timeslot of the appointment, formatted like starttime-endtime. Ex. 7:30-9:30. Will be in 24H format.
 * @param addToJSON         Whether you want to write to the JSON file.
 */
Appointment::Appointment (int doctorid, int patientid, std::string theTimeslot, bool addToJSON) {
    AppointmentID = nextId;
    doctorID = doctorid;
    patientID = patientid;
    timeslot = theTimeslot;

    // adds to json
    if (addToJSON) {
        jsonhandeler->addAppointment (AppointmentID, doctorid, patientid, timeslot);
        nextId++;
    }
}

/**
 * Creates an instance of Appointment for easy data extraction.
 *
 * @param appointmentid     ID of appointment
 * @param doctorid          ID of doctor
 * @param patientid         ID of patient
 * @param theTimeslot       Timeslot of the appointment, formatted like starttime-endtime. Ex. 7:30-9:30. Will be in 24H format.
 */
Appointment::Appointment (int appointmentid, int doctorid, int patientid, std::string theTimeslot) {
    AppointmentID = appointmentid;
    doctorID = doctorid;
    patientID = patientid;
    timeslot = theTimeslot;
}

/**
 * FOR PROTOTYPE PATTERN, creates a new appointment by cloning an existing appointment with the same parameters, but sets the patient id to the given.
 *
 * @param newPatientid      The id of the patient to set into the new appointment.
 * @return                  The newly created appointment object.
 */
Appointment* Appointment::clone(int newPatientid) const {
    return new Appointment(AppointmentID, doctorID, newPatientid, timeslot);
}

/**
 * Getter method for the appointmentID
 *
 * Output: AppointmentID
 */
int Appointment::getAppointmentID() const {
    return AppointmentID;
}

/**
 * Getter method for the timeslot
 *
 * Output: timeslot
 */
std::string Appointment::getTimeslot() const {
    return timeslot;
}

/**
 * Getter method for the appointmentID
 *
 * Output: doctorID
 */
int Appointment::getDoctorID() const {
    return doctorID;
}

/**
 * Getter method for the patientID
 *
 * Output: patientID
 */
int Appointment::getPatientID() const {
    return patientID;
}

/**
 * Getter method for the starting timeslot of the appointment
 *
 * Output: starting timeslot of the appointment
 */
std::string Appointment::getStartingTimeslot() {
    int delimiter_position = timeslot.find("-");
    return timeslot.substr(0, delimiter_position);
}

/**
 * Getter method for the ending timeslot of the appointment
 *
 * Output: ending timeslot of the appointment
 */
std::string Appointment::getEndingTimeslot() {
    int delimiter_position = timeslot.find("-");
    return timeslot.substr(delimiter_position+1);
}

/**
 * Getter method for the year of the appointment
 *
 * Output: year of the appointment
 */
std::string Appointment::getAppointmentYear() {
    std::string timeslot2 = getStartingTimeslot();
    int year_delimiter_position = timeslot2.find ("Y");
    int month_delimiter_position = timeslot2.find ("M");
    return timeslot2.substr(year_delimiter_position+1, month_delimiter_position-year_delimiter_position-1);
}

/**
 * Getter method for the month of the appointment
 *
 * Output: month of the appointment
 */
std::string Appointment::getAppointmentMonth() {
    std::string timeslot2 = getStartingTimeslot();
    int month_delimiter_position = timeslot2.find ("M");
    int day_delimiter_position = timeslot2.find ("D");
    return timeslot2.substr(month_delimiter_position+1, day_delimiter_position-month_delimiter_position-1);
}

/**
 * Getter method for the day of the appointment
 *
 * Output: day of the appointment
 */
std::string Appointment::getAppointmentDay() {
    std::string timeslot2 = getStartingTimeslot();
    int day_delimiter_position = timeslot2.find ("D");
    int time_delimiter_position = timeslot2.find ("T");
    return timeslot2.substr(day_delimiter_position+1, time_delimiter_position-day_delimiter_position-1);
}

/**
 * Getter method for the starting time of the appointment
 *
 * Output: starting time of the appointment
 */
std::string Appointment::getStartingTime() {
    std::string timeslot2 = getStartingTimeslot();
    int time_delimiter_position = timeslot2.find ("T");
    return timeslot2.substr(time_delimiter_position+1);
}

/**
 * Getter method for the ending time of the appointment
 *
 * Output: ending time of the appointment
 */
std::string Appointment::getEndingTime() {
    std::string timeslot2 = getEndingTimeslot();
    int time_delimiter_position = timeslot2.find ("T");
    return timeslot2.substr(time_delimiter_position+1);
}

