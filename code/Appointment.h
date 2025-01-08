#ifndef APPOINTMENT_H
#define APPOINTMENT_H

#include <string>

class JSONHandeler;

class Appointment {
    private:
        int AppointmentID;
        int doctorID;
        int patientID;
        std::string timeslot;
        static int nextId;
        std::string getStartingTimeslot();
        std::string getEndingTimeslot();
        static JSONHandeler* jsonhandeler;
    public:
        // Constructor
        Appointment(int doctorid, int patientid, std::string theTimeslot, bool AddToJSON);

        //Secondary Constructor used for creating Appointments objects from info recieved from the json files
        Appointment (int appointmentid, int doctorid, int patientid, std::string theTimeslot);

        //Prototype method
        Appointment* clone(int newPatientid) const; // FOR PROTOTYPE PATTERN

        // Getter methods
        int getAppointmentID() const;
        std::string getTimeslot() const;
        int getDoctorID() const;
        int getPatientID() const;
        std::string getAppointmentDay();
        std::string getAppointmentMonth();
        std::string getAppointmentYear();
        std::string getStartingTime();
        std::string getEndingTime();
};


#endif // APPOINTMENT_H
