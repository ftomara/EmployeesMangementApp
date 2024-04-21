#include <iostream>
#include "employee.cpp"
using namespace std;

#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

class hourlyemployee : public employee
{
private:
    double hoursworked;
    double rate;

public:
    hourlyemployee()
    {
        rate = 0;
        hoursworked = 0;
    }
    hourlyemployee(double r, double hw)
    {
        rate = r;
        hoursworked = hw;
    }
    virtual ~hourlyemployee()
    {
    }
    void addhours(int morehours)
    {
        hoursworked += morehours;
    }
    double getsalary()
    {
        return rate * hoursworked;
    }
    string displaydetails()
    {
        return employee::displaydetails() + "\nRate : " + to_string(rate) + "\nHours Worked : " + to_string(hoursworked);
    }
    double calculatepay()
    {
        return getsalary();
    }
    void getinfo()
    {
        employee::getinfo();
        cout << "Enter Rate : ";
        cin >> rate;
        cout << "Enter Worked Hours : ";
        cin >> hoursworked;
    }
};

#endif