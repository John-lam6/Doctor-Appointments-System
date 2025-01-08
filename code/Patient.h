#ifndef PATIENT_H
#define PATIENT_H

#include <User.h>
#include <string>

class JSONHandeler; // forward declare class JSONHandeler

// currently only adds a patient specific id
class Patient : public User {
public:
    Patient (std::string theEmail, std::string thePassword, bool addToJSON); // the constructor of the patient
    int getPatientID(); // Getter for patient specific id
    int getId() const override;
private:
    //Patient specific id
    int patientId;
    std::string email;
    std::string password;
    static int nextId;
    static JSONHandeler* jsonhandeler;
};

#endif // PATIENT_H
