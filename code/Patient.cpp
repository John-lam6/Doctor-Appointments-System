#include "Patient.h"
#include "JSONHandeler.h"

// initialize static variable
JSONHandeler* Patient::jsonhandeler = JSONHandeler::getInstance();
int Patient::nextId = jsonhandeler->getNextPatientID();

/**
 *  Constructor for Patient. Creates a Patient. And adds it to the JSON file.
 *
 * @param theEmail                 The email to signin.
 * @param thePassword              The password to signin.
 * @param addToJSON                Whether or not to add to JSON file, True add, false no add.
 */
Patient::Patient(std::string theEmail, std::string thePassword, bool addToJSON) {
    patientId = nextId;
    email = theEmail;
    password = thePassword;

    // adds to json file
    if (addToJSON) {
        jsonhandeler->addAccount(patientId, email, password);
        nextId++;
    }
}

int Patient::getId() const {
    return patientId;
}

/**
 * Getter method for the patient id
 * @return  Returns the patient id.
 */
int Patient::getPatientID() {
    return patientId;
}
