#ifndef USER_H
#define USER_H

#include <string>

class User {
protected:
    int userId;
    std::string name;
private:
    static int nextUserId;
public:
    User();
    User(const std::string& name);
    virtual ~User();

    std::string getName() const;
    int getUserId() const;

    virtual int getId() const = 0;
};

#endif // USER_H
