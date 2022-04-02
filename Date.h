#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<string>
using namespace std;

// To store number of days in
// all months from January to Dec.
const int monthDays[12]
        = { 31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31 };

class Date {
    private:
        int day;
        int month;
        int year;

    public:
      Date() {
          this->day = 0;
          this->month = 0;
          this->year = 0;
      }

      Date(int day, int month, int year) {
          this->day = day;
          this->month = month;
          this->year = year;
      }

      // Setters
      void setDay(int day) {
          this->day = day;
      }

      void setMonth(int month) {
          this->month = month;
      }

      void setYear(int year) {
          this->year = year;
      }

      // Getters
      int getDay() const {
          return day;
      }

      int getMonth() const {
        return month;
      }

      int getYear() const {
          return year;
      }

      // methods
      int countLeapYears(Date d)
      {
          int years = d.year;

          // Check if the current year needs to be
          //  considered for the count of leap years
          // or not
          if (d.month <= 2)
              years--;

          // A year is a leap year if it
          // is a multiple of 4,
          // multiple of 400 and not a
          // multiple of 100.
          return years / 4
                 - years / 100
                 + years / 400;
      }

    // This function returns number of
    // days between two given dates
    int getDifference(Date dt1, Date dt2)
    {
        // COUNT TOTAL NUMBER OF DAYS
        // BEFORE FIRST DATE 'dt1'

        // initialize count using years and day
        long int n1 = dt1.year * 365 + dt1.day;

        // Add days for months in given date
        for (int i = 0; i < dt1.month - 1; i++)
            n1 += monthDays[i];

        // Since every leap year is of 366 days,
        // Add a day for every leap year
        n1 += countLeapYears(dt1);

        // SIMILARLY, COUNT TOTAL NUMBER OF
        // DAYS BEFORE 'dt2'

        long int n2 = dt2.year * 365 + dt2.day;
        for (int i = 0; i < dt2.month - 1; i++)
            n2 += monthDays[i];
        n2 += countLeapYears(dt2);

        // return difference between two counts
        return (n2 - n1);
    }


    string tabbedDateString() const {
          return to_string(day) + "\t" + to_string(month) + "\t" + to_string(year);
      }
};
#endif
