#ifndef DOCTOR_H
#define DOCTOR_H

#include <User.h>
#include <string>

// currently only adds a doctor specific id
class Doctor : public User {
public:
    Doctor(std::string theEmail, std::string thePassword); // constructor for Doctor
    int getDoctorID(); //Getter for doctor specific id
    int getId() const override;
private:
    std::string email;
    std::string password;
    int doctorId; //Doctor specific id
    static int nextId; // to ensure the doctor id will always be unique
};

#endif // DOCTOR_H
