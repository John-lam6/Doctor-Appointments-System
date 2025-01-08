#include <User.h>

int User::nextUserId = 1;

User::User() {
    name = "";
    userId = nextUserId;
    nextUserId++;
}

User::User(const std::string& name) : name(name) {
    userId = nextUserId;
    nextUserId++;
}

User::~User() {}

std::string User::getName() const {
    return name;
}
