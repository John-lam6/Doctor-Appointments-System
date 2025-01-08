#ifndef TIMEHELPER_H
#define TIMEHELPER_H

#include <string>
#include <QDate>


class TimeHelper {
public:
    ~TimeHelper();
    static TimeHelper* getInstance();
    std::string getCurrTime();
    std::string extractYear(const QDate &date);
    std::string extractMonth(const QDate &date);
    std::string extractDay(const QDate &date);
    std::string extractMonthFromString(std::string month);
    bool isValidAppointmentTime (std::string start_time, std::string end_time);
    bool noConflictsTime (std::string start_time, std::string end_time, std::string existing_starting_time, std::string existing_end_time);
    std::string convertToProperTimeFormat (const std::string start_time, const std::string end_time, const QDate date);
    std::string convertTo12HFormat (std::string time);


private:
    TimeHelper();
    std::string getTime();
    std::string getCurrentYear();
    std::string getCurrentMonth();
    std::string getCurrentDay();
    int convertToMinutes (int hours, int minutes);
    static TimeHelper* timehelper;

};
#endif // TIMEHELPER_H
