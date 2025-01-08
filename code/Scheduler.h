#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "AppointmentManager.h"
#include "AvailabilityManager.h"
#include "AvailabilityObserver.h"
#include "Appointment.h"

void requestCreateAppointment(int doctorid, int patientid, std::string timeslot);
void requestCancelAppointment(int doctorid, int patientid, std::string timeslot);

void requestCancelAppointment(int appointmentid);

#endif // SCHEDULER_H
