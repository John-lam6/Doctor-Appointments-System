#include "AppointmentManager.h"

JSONHandeler* AppointmentManager::jsonhandeler = JSONHandeler::getInstance();
AppointmentManager* AppointmentManager::appointmentmanager = nullptr;

AppointmentManager::AppointmentManager() {

}

AppointmentManager::~AppointmentManager() {

}

/**
 * Returns the singleton instance of the class.
 *
 * @return  The single instance of the class.
 */
AppointmentManager* AppointmentManager::getInstance() {
    if (appointmentmanager == nullptr) {
        appointmentmanager = new AppointmentManager();
    }
    return appointmentmanager;
}

/**
 * Books an appointment for a patient. It clones the information of an appointment (that has the given doctor id and timeslot) then changes the patient id.
 *
 * @param doctorid      The id of the doctor in the appointment.
 * @param patientid     The id of the patient that books the appointment.
 * @param timeslot      The timeslot of the appointment.
 */
void AppointmentManager::createAppointment (int doctorid, int patientid, std::string timeslot) {
    // gets the appointments of the given doctor.
    std::optional<std::list<Appointment>> list = jsonhandeler->getAppointmentsDoctor(doctorid);
    if (list.has_value()) {
        // loops through all the appointments of the doctor.
        for (Appointment& appointment : *list) {
            // finds the appointment with the given timeslot
            if (appointment.getTimeslot().std::string::compare(timeslot) == 0) {
                // clones the appointment then adds the new appointment to the JSON file
                Appointment* newappointment = appointment.clone(patientid);
                jsonhandeler->addAppointment(newappointment->getAppointmentID(), newappointment->getDoctorID(), newappointment->getPatientID(), newappointment->getTimeslot());
            }
        }
    }
}

/**
 * Deletes the appointment from the system.
 *
 * @param appointmentid     The id of the appointment to remove from the system.
 */
void AppointmentManager::cancelAppointment (int appointmentid) {
    jsonhandeler->remAppointmentPatient(appointmentid);
}

/**
 * Cancels the booking of the patient.
 *
 * @param appointmentid     The id of the appointment to cancel booking.
 */
void AppointmentManager::cancelAppointmentPatient (int appointmentid) {
    jsonhandeler->cancelAppointment(appointmentid);
}
