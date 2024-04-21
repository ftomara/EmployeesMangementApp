#include <iostream>
#include "employee.cpp"
using namespace std;
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

class salariedemployee : public employee
{
protected:
    double salary;

public:
    salariedemployee()
    {
        salary = 0;
    }
    salariedemployee(double s)
    {
        salary = s;
    }
    ~salariedemployee() {}
    double getsalary()
    {
        return salary;
    }
    string displaydetails()
    {
        return employee::displaydetails() + "\nSalary : " + to_string(salary);
    }
    double calculatepay()
    {
        return getsalary();
    }
    void getinfo()
    {
        employee::getinfo();
        cout << "Enter Salary : ";
        cin >> salary;
    }
};

#endif