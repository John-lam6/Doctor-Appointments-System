#include "AvailabilityManager.h"

JSONHandeler* AvailabilityManager::jsonhandeler = JSONHandeler::getInstance();

AvailabilityManager::AvailabilityManager() {
    observers = {};
}

/**
 * Attaches an observer to the concreate subject
 *
 * @param pointer to observer to attach
 */
void AvailabilityManager::attach(Observer* observer) {
    observers.push_back(observer);
}

/**
 * Detaches an observer from the concreate subject
 *
 * @param observer to attach
 */
void AvailabilityManager::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

/**
 * Notfies all attached observers to update
 *
 * @param observer to attach
 */
void AvailabilityManager::notify(const int& doctorid) {
    for (Observer* observer: observers) {
        observer->update(doctorid);
    }
}

/**
 * Adds a 'timeslot' to the doctor's schedule, a timeslot is an appointment object with a -1 for patient id
 *
 * @param doctorid
 * @param timeslot
 * @return True if the addition was successful
 */
bool AvailabilityManager::addDoctorAvailability(const int doctorid, const std::string timeslot) const {
    Appointment appoint(doctorid, -1, timeslot, true);
    return true;
}

/**
 * Removes a doctor's availability with a given time
 *
 * @param doctorid
 * @param timeslot
 * @return True if the removal of the appointment was successful/the appointment exisited to be removed
 */
bool AvailabilityManager::remDoctorAvailability(const int doctorid, const std::string timeslot) const {
    std::optional<std::list<Appointment>> list = jsonhandeler->getAppointmentsDoctor(doctorid);

    if (list.has_value()) {
        for (Appointment& appointment : *list) {
            if (appointment.getTimeslot().compare(timeslot) == 0) {
                jsonhandeler->remAppointment(appointment.getAppointmentID());
                return true;
            }
        }
    }
    return false;
}

/**
 * Cancels the booking of an appointment.
 *
 * @param appointment_id        The id of the appointment to cancel.
 * @return                      Whether the cancel appointment was successful.
 */
bool AvailabilityManager::cancelBooking (int appointment_id) {
    return jsonhandeler->cancelAppointment(appointment_id);
}
