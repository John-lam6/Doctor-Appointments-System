#include "TimeHelper.h"

TimeHelper* TimeHelper::timehelper = nullptr;

TimeHelper::TimeHelper() {

}

TimeHelper::~TimeHelper() {

}

/**
 * Returns the singleton instance of the class.
 *
 * @return  The single instance of the class.
 */
TimeHelper* TimeHelper::getInstance() {
    if (timehelper == nullptr) {
        timehelper = new TimeHelper();
    }
    return timehelper;
}

/**
 * Gets the current date and time.
 *
 * @return  The current date and time
 */
std::string TimeHelper::getTime() {
    time_t timestamp;
    time(&timestamp);

    return ctime(&timestamp);
}

/**
 * Gets the current year.
 *
 * @return  The current year.
 */
std::string TimeHelper::getCurrentYear() {
    std::string curr_time = getTime();

    std::string year = curr_time.substr(20,4);
    return year;
}

/**
 * Gets the current month.
 *
 * @return  The current month.
 */
std::string TimeHelper::getCurrentMonth() {
    std::string curr_time = getTime();

    std::string month = curr_time.substr(4,3);
    std::string months_arr[12] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};

    // finds out which index the month is for the formatting of the date (YYYY-MM-DD)
    int month_index = 0;
    for (int i = 0; i < 12; i++) {
        if (month == months_arr[i]) {
            month_index = i + 1;
            break;
        }
    }

    return (month_index < 10 ? "0" : "") + std::to_string(month_index);
}

/**
 * Gets the current day.
 *
 * @return  The current day.
 */
std::string TimeHelper::getCurrentDay() {
    std::string curr_time = getTime();

    std::string day = curr_time.substr(8,2);
    return day;
}

/**
 * Gets the current date.
 *
 * @return A string formatted YYYY-MM-DD.
 */
std::string TimeHelper::getCurrTime() {
    std::string year = getCurrentYear();
    std::string month = getCurrentMonth();
    std::string day = getCurrentDay();

    std::string date_format = year + "-" + month + "-" + day;
    return date_format;
}

/**
 * Extracts the year from the calendar's date.
 *
 * @param date  The date extracted from the calendar.
 * @return      The year from the calendar's date.
 */
std::string TimeHelper::extractYear(const QDate &date) {
    QString dateQString = date.toString("yyyy-MM-dd");
    std::string dateString = dateQString.toStdString();
    std::string year = dateString.substr(0,4);

    return year;
}

/**
 * Extracts the month from the calendar's date.
 *
 * @param date  The date extracted from the calendar.
 * @return      The month from the calendar's date.
 */
std::string TimeHelper::extractMonth(const QDate &date) {
    std::string months_arr[12] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    QString dateQString = date.toString("yyyy-MM-dd");
    std::string dateString = dateQString.toStdString();

    // from the month number extracted, turn it into an index to find out what month it is
    std::string month = dateString.substr(5,2);
    int month_index = stoi(month) - 1;
    month = months_arr[month_index];

    return month;
}

/**
 * Extracts the month in from the calendar's date.
 *
 * @param date  The date extracted from the calendar.
 * @return      The month from the calendar's date.
 */
std::string TimeHelper::extractMonthFromString(std::string month) {
    std::string months_arr[12] = {"JANUARY", "FEBRUARY", "MARCH", "APRIL", "MAY", "JUNE", "JULY", "AUGUST", "SEPTEMBER", "OCTOBER", "NOVEMBER", "DECEMBER"};
    // from the month number extracted, turn it into an index to find out what month it is
    int month_index = stoi(month) - 1;
    return months_arr[month_index];
} // timehelper->extractMonthFromString(appointment.getAppointmentMonth())

/**
 * Extracts the day from the calendar's date.
 *
 * @param date  The date extracted from the calendar.
 * @return      The day from the calendar's date.
 */
std::string TimeHelper::extractDay(const QDate &date) {
    QString dateQString = date.toString("yyyy-MM-dd");
    std::string dateString = dateQString.toStdString();
    std::string day = dateString.substr(8,2);

    return day;
}

/**
 * Determines whether the appointment time is valid before creating.
 *
 * @param start_time    The start time of the appointment.
 * @param end_time      The end time of the appointment.
 * @return              True if the times are valid, false otherwise.
 */
bool TimeHelper::isValidAppointmentTime (std::string start_time, std::string end_time) {
    int time_delimiter_position1 = start_time.find (":");
    int time_delimiter_position2 = end_time.find (":");

    // gets the hours of the start and end time
    int starting_hour = stoi(start_time.substr (0, time_delimiter_position1));
    int ending_hour = stoi(end_time.substr (0, time_delimiter_position2));

    // gets the minutes of the start and end time
    int starting_minutes = stoi(start_time.substr (time_delimiter_position1 + 1, 2));
    int ending_minutes = stoi(end_time.substr (time_delimiter_position2 + 1, 2));

    time_delimiter_position1 = start_time.find ("M");
    time_delimiter_position2 = end_time.find ("M");

    // gets the AM or PM of the start and end time
    std::string am_pm1 = start_time.substr (time_delimiter_position1 - 1, 2);
    std::string am_pm2 = end_time.substr (time_delimiter_position2 - 1, 2);


    // convert it to 24 hours
    // if it is 12AM, then 24 hour is 0
    if (starting_hour == 12 && am_pm1.std::string::compare("AM") == 0) {
        starting_hour = 0;
    }

    if (ending_hour == 12 && am_pm2.std::string::compare("AM") == 0) {
        ending_hour = 0;
    }

    // convert it to 24 hours
    // if it is 12PM, then 24 hour is 12
    if (am_pm1.std::string::compare("PM") == 0 && starting_hour != 12) { // 12 pm and 12 am FIXXXX
        starting_hour += 12;
    }

    if (am_pm2.std::string::compare("PM") == 0 && ending_hour != 12) {
        ending_hour += 12;
    }

    int minutes1 = convertToMinutes(starting_hour, starting_minutes);
    int minutes2 = convertToMinutes(ending_hour, ending_minutes);

    return (minutes2 > minutes1);
}


/**
 * Determines whether the appointment time is valid before creating.
 *
 * @param start_time    The start time of the appointment.
 * @param end_time      The end time of the appointment.
 * @return              True if the times are valid, false otherwise.
 */
bool TimeHelper::noConflictsTime (std::string start_time, std::string end_time, std::string existing_starting_time, std::string existing_end_time) {
    int time_delimiter_position1 = start_time.find (":");
    int time_delimiter_position2 = end_time.find (":");
    int time_delimiter_position3 = existing_starting_time.find (":");
    int time_delimiter_position4 = existing_end_time.find (":");

    // gets the hours of the start and end time
    int starting_hour = stoi(start_time.substr (0, time_delimiter_position1));
    int ending_hour = stoi(end_time.substr (0, time_delimiter_position2));
    int existing_starting_hour = stoi(existing_starting_time.substr (0, time_delimiter_position3));
    int existing_end_hour = stoi(existing_end_time.substr (0, time_delimiter_position4));

    // gets the minutes of the start and end time
    int starting_minutes = stoi(start_time.substr (time_delimiter_position1 + 1, 2));
    int ending_minutes = stoi(end_time.substr (time_delimiter_position2 + 1, 2));
    int existing_starting_minutes = stoi(existing_starting_time.substr (time_delimiter_position3 + 1, 2));
    int existing_ending_minutes = stoi(existing_end_time.substr (time_delimiter_position4 + 1, 2));

    time_delimiter_position1 = start_time.find ("M");
    time_delimiter_position2 = end_time.find ("M");

    // gets the AM or PM of the start and end time
    std::string am_pm1 = start_time.substr (time_delimiter_position1 - 1, 2);
    std::string am_pm2 = end_time.substr (time_delimiter_position2 - 1, 2);

    // convert it to 24 hours
    // if it is 12AM, then 24 hour is 0
    if (starting_hour == 12 && am_pm1.std::string::compare("AM") == 0) {
        starting_hour = 0;
    }

    if (ending_hour == 12 && am_pm2.std::string::compare("AM") == 0) {
        ending_hour = 0;
    }

    // convert it to 24 hours
    // if it is 12PM, then 24 hour is 12
    if (am_pm1.std::string::compare("PM") == 0 && starting_hour != 12) { // 12 pm and 12 am FIXXXX
        starting_hour += 12;
    }

    if (am_pm2.std::string::compare("PM") == 0 && ending_hour != 12) {
        ending_hour += 12;
    }

    int minutes1 = convertToMinutes(starting_hour, starting_minutes);
    int minutes2 = convertToMinutes(ending_hour, ending_minutes);
    int existing_minutes3 = convertToMinutes(existing_starting_hour, existing_starting_minutes);
    int existing_minutes4 = convertToMinutes(existing_end_hour, existing_ending_minutes);

    bool conflict = (minutes1 < existing_minutes4) && (minutes2 > existing_minutes3);
    return !conflict;
}

/**
 * Helper method to convert the time to minutes.
 *
 * @param time      The time to convert to minutes
 * @return          The time converted to minutes
 */
int TimeHelper::convertToMinutes (int hours, int minutes) {
    return hours * 60 + minutes;
}

/**
 * Converts the given parameters into a set format. Ex. Y2024M11D27T7:06-Y2024M11D27T8:06
 *
 * @param start_time    The start time of the appointment.
 * @param end_time      The end time of the appointment.
 * @param date          The date of the appointment.
 * @return              The timeslot set into a set format.
 */
std::string TimeHelper::convertToProperTimeFormat (const std::string start_time, const std::string end_time, const QDate date) {
    QString dateQString = date.toString("yyyy-MM-dd");
    std::string dateString = dateQString.toStdString();

    // gets the year, month and day from the date
    std::string year = dateString.substr(0,4);
    std::string month = dateString.substr(5,2);
    std::string day = dateString.substr(8,2);

    // gets the hours of the appointment
    int time_delimiter_position1 = start_time.find (":");
    int time_delimiter_position2 = end_time.find (":");
    int starting_hour = stoi (start_time.substr (0, time_delimiter_position1));
    int ending_hour = stoi(end_time.substr (0, time_delimiter_position2));

    // gets the minutes of the appointment
    std::string starting_minutes = start_time.substr (time_delimiter_position1 + 1, 2);
    std::string ending_minutes = end_time.substr (time_delimiter_position2 + 1, 2);

    // gets the AM or PM of the appointment
    time_delimiter_position1 = start_time.find ("M");
    time_delimiter_position2 = end_time.find ("M");

    // gets the AM or PM of the start and end time
    std::string am_pm1 = start_time.substr (time_delimiter_position1 - 1, 2);
    std::string am_pm2 = end_time.substr (time_delimiter_position2 - 1, 2);

    // convert starting hour to 24 hours
    // if it is 12AM, then 24 hour is 0
    if (starting_hour == 12 && am_pm1.std::string::compare("AM") == 0) {
        starting_hour = 0;
    }

    // convert ending hour to 24 hours
    // if it is 12AM, then 24 hour is 0
    if (ending_hour == 12 && am_pm2.std::string::compare("AM") == 0) {
        ending_hour = 0;
    }

    // convert starting hour to 24 hours
    // if it is 12PM, then 24 hour is 12
    if (am_pm1.std::string::compare("PM") == 0 && starting_hour != 12) { // 12 pm and 12 am FIXXXX
        starting_hour += 12;
    }

    // convert ending hour to 24 hours
    // if it is 12PM, then 24 hour is 12
    if (am_pm2.std::string::compare("PM") == 0 && ending_hour != 12) {
        ending_hour += 12;
    }
    // return the formatted string
    return "Y" + year + "M" + month + "D" + day + "T" + std::to_string(starting_hour) + ":" + starting_minutes + "-" + "Y" + year + "M" + month + "D" + day + "T" + std::to_string(ending_hour) + ":" + ending_minutes;
}

/**
 * Converts the given time from 24H to 12H for display purposes.
 *
 * @param time      The time to convert to 12H format.
 * @return          The time in 12H format.
 */
std::string TimeHelper::convertTo12HFormat (std::string time) {
    int time_delimiter_position = time.find (":");

    // gets the hour of the time
    int hour = stoi (time.substr (0, time_delimiter_position));

    // gets the minute of the time
    std::string minutes = time.substr (time_delimiter_position + 1, 2);

    std::string am_pm;
    bool additional_padding = false;

    // determines if it is AM or PM
    if (hour < 12) {
        am_pm = "AM";
    }
    else {
        am_pm = "PM";
    }


    // if it is hour 0, it is 12AM
    if (hour == 0) {
        hour = 12;
    }
    // if it is hour 12, it is 12PM
    else if (hour == 12) {
        hour = 12;
    }
    // else modulo the hour by 12
    else {
        hour = hour % 12;
    }

    // if the hour is less than 10, it requires a padding to have a consistent text throughout.
    if (hour < 10) {
        additional_padding = true;
    }

    std::string time_12h;

    // creates the 12H time into a string
    if (additional_padding) {
        time_12h = " " + std::to_string(hour) + ":" + minutes + " " + am_pm;
    }
    else {
        time_12h = std::to_string(hour) + ":" + minutes + " " + am_pm;
    }

    // returns the time.
    return time_12h;
}
