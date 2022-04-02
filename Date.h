#ifndef DATE_H
#define DATE_H

#include<iostream>
#include<string>
using namespace std;

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

      // Getters
      int getDay() const {
          return day;
      }

      int getMonth() const {
        return month;
      }

      int getYear() const{
        return year;
      }

      string dateString() const {
        return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
    }
};
#endif
