#include "ValidateAccount.h"
#include "JSONHandeler.h"

JSONHandeler* ValidateAccount::jsonhandeler = JSONHandeler::getInstance();
ValidateAccount* ValidateAccount::validateaccount = nullptr;

ValidateAccount::ValidateAccount() {

}

ValidateAccount::~ValidateAccount() {

}


/**
 * Returns the singleton instance of the class.
 *
 * @return  The single instance of the class.
 */
ValidateAccount* ValidateAccount::getInstance () {
    if (validateaccount == nullptr) {
        validateaccount = new ValidateAccount();
    }
    return validateaccount;
}

/**
 * Checks if the email exists within the database.
 *
 * @param email     The email to check if it exists in the database.
 * @return          True if the email exists. False otherwise.
 */
bool ValidateAccount::emailExists(std::string email) {
    if (jsonhandeler->getEmail(email)) {
        return true;
    }
    return false;
}

/**
 * Checks if the email is of a valid pattern.
 *
 * @param email     The email to check the validity of.
 * @return          True if the email is of valid pattern. False otherwise.
 */
bool ValidateAccount::emailIsValid (std::string email) {
    int index_AT = email.find("@");
    int index_DOT = email.find(".", index_AT);

    if (index_AT > 0 && index_DOT > 0) {
        return true;
    }
    return false;
}

/**
 * Checks if the password is valid. If it is not empty, then it is valid.
 *
 * @param password  The password to check the validity.
 * @return          True if it is not empty, false otherwise.
 */
bool ValidateAccount::passwordIsValid (std::string password) {
    if (password.empty()) {
        return false;
    }
    return true;
}

/**
 * Checks if the doctor login is valid.
 *
 * @param email     The email to check if it exists in the database.
 * @param password  The password to check if it matches with the email in the database.
 * @return          True if the login is valid, otherwise False.
 */
bool ValidateAccount::accountIsValidDoctor(std::string email, std::string password) {
    if (jsonhandeler->checkAuthDoctor(email, password)) {
        return true;
    }
    return false;
}

/**
 * Checks if the patient login is valid.
 *
 * @param email     The email to check if it exists in the database.
 * @param password  The password to check if it matches with the email in the database.
 * @return          True if the login is valid, otherwise False.
 */
bool ValidateAccount::accountIsValidPatient(std::string email, std::string password) {
    if (jsonhandeler->checkAuthPatient(email, password)) {
        return true;
    }
    return false;
}
