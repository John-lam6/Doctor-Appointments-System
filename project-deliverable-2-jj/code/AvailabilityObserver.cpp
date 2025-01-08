#include "AvailabilityObserver.h"

#include <iostream>

////TODO Chnage this to the actual update logic
void AvailabilityObserver::update(const int& doctorid) {
    std::cout << "Observer notified: Availability of Doctor " << doctorid << " has changed.\n";
}
