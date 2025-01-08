#ifndef APPOINTMENTMANAGER_H
#define APPOINTMENTMANAGER_H

#include "JSONHandeler.h"
#include <string>

class AppointmentManager {
public:
    ~AppointmentManager();
    static AppointmentManager* getInstance();
    void createAppointment (int doctorid, int patientid, std::string timeslot);
    void cancelAppointment (int appointmentid);
    void cancelAppointmentPatient (int appointmentid);

private:
    AppointmentManager();

    static AppointmentManager* appointmentmanager;
    static JSONHandeler* jsonhandeler;
};


#endif // APPOINTMENTMANAGER_H
