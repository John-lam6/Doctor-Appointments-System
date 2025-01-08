#ifndef AVAILABILITYMANAGER_H
#define AVAILABILITYMANAGER_H

#include <string>
#include <vector>
#include <map>
#include "Doctor.h"
#include "Appointment.h"
#include "JSONHandeler.h"

class Observer {
public:
    virtual void update(const int& doctorid) = 0;
    //virtual void update(const Doctor& doctor) = 0;
    virtual ~Observer() = default;
};

class Subject {
public:
    virtual void attach(Observer* observer) = 0;
    virtual void detach(Observer* observer) = 0;
    virtual void notify(const int& doctorid) = 0;
    virtual ~Subject() = default;
};


class AvailabilityManager : public Subject {
private:
    static JSONHandeler* jsonhandeler;
    std::vector<Observer*> observers;
public:
    AvailabilityManager();

    void attach(Observer* observer) override;
    void detach(Observer* observer) override;
    void notify(const int& doctorid) override;

    //Add/rem a timeslot to the doctor's un/availablility, returning true if successful and false otherwise
    bool addDoctorAvailability(const int doctorid, const std::string timeslot) const;
    bool remDoctorAvailability(const int doctorid, const std::string timeslot) const;

    // cancels a patient's booking.
    bool cancelBooking (int appointment_id);
};

#endif // AVAILABILITYMANAGER_H
