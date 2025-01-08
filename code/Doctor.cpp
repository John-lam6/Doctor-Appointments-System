#include "Doctor.h"


// initialize static variable
int Doctor::nextId = 1;

/**
 *  Constructor for Doctor. Creates a doctor.
 *
 * @param theEmail              The email to signin.
 * @param thePassword           The password to signin.
 */
Doctor::Doctor(std::string theEmail, std::string thePassword) {
    doctorId = nextId;
    email = theEmail;
    password = thePassword;
    nextId++;
}

int Doctor::getId() const {
    return doctorId;
}

/**
 * Getter method for the Doctor Id.
 *
 * @return  The id of the doctor.
 */
int Doctor::getDoctorID() {
    return doctorId;
}
