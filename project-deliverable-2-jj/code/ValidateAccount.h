#ifndef VALIDATEACCOUNT_H
#define VALIDATEACCOUNT_H

#include "JSONHandeler.h"
#include <string>
#include <QDate>


class ValidateAccount {
public:
    ~ValidateAccount();
    static ValidateAccount* getInstance();
    bool emailExists(std::string email);
    bool emailIsValid(std::string email);
    bool accountIsValidDoctor(std::string email, std::string password);
    bool accountIsValidPatient(std::string email, std::string password);
    bool passwordIsValid (std::string password);

private:
    ValidateAccount();
    static ValidateAccount* validateaccount;
    static JSONHandeler* jsonhandeler;

};
#endif // VALIDATEACCOUNT_H
