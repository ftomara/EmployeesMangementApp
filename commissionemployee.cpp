#include <iostream>
#include "employee.cpp"
using namespace std;
#ifndef COMMISIONEMPLOYEE_H
#define COMMISIONEMPLOYEE_H

class commissionemployee : public employee
{
protected:
    double target;
    double rate;

public:
    commissionemployee()
    {
        rate = 0;
        target = 0;
    }
    commissionemployee(double t, double r)
    {
        rate = r;
        target = t;
    }
    ~commissionemployee()
    {
    }
    double getsalary()
    {
        return rate * target;
    }
    string displaydetails()
    {
        return employee::displaydetails() + "\nTarget : " + to_string(target) + "\nRate : " + to_string(rate);
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
        cout << "Enter Target : ";
        cin >> target;
    }
};

#endif