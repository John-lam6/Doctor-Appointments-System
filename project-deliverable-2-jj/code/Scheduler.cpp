#include "Scheduler.h"
#include "JSONHandeler.h"

AppointmentManager* appointmentmanager = AppointmentManager::getInstance();

/**
 * Request to create an appointment, will notify observers of the change in doctor schedule
 *
 * @param doctorid
 * @param patientid
 * @param timeslot
 */
void requestCreateAppointment(int doctorid, int patientid, std::string timeslot) {
    AvailabilityManager availabilitymanager;
    AvailabilityObserver availabilityobserver;
    availabilitymanager.attach(&availabilityobserver);

    appointmentmanager->createAppointment(doctorid, patientid, timeslot);

    availabilitymanager.notify(doctorid);

    availabilitymanager.detach(&availabilityobserver);
}

/**
 * Request to cancel an appointment, will notify observers of the change in doctor schedule
 *
 * @param doctorid
 * @param patientid
 * @param timeslot
 */
void requestCancelAppointment(int appointmentid) {
    AvailabilityManager availabilitymanager;
    AvailabilityObserver availabilityobserver;
    availabilitymanager.attach(&availabilityobserver);

    std::optional<Appointment> appointment = JSONHandeler::getInstance()->getAppointment(appointmentid);

    if (appointment.has_value()) {
        int doctorid = appointment->getDoctorID();
        appointmentmanager->cancelAppointment(appointmentid);

        availabilitymanager.notify(doctorid);
    }

    availabilitymanager.detach(&availabilityobserver);
}
