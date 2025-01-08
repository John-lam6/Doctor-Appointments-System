#ifndef AVAILABILITYOBSERVER_H
#define AVAILABILITYOBSERVER_H

#include "AvailabilityManager.h"


class AvailabilityObserver: public Observer {
public:
    void update(const int& doctorid) override;
};

#endif // AVAILABILITYOBSERVER_H
