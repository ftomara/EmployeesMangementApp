#include <iostream>
#include "salariedemployee.cpp"
using namespace std;
#ifndef MANGEREMPLOYEE_H
#define MANGEREMPLOYEE_H

class mangeremployee : public salariedemployee
{
protected:
    double bouns;

public:
    mangeremployee()
    {
        bouns = 0;
        salary = 0;
    }
    mangeremployee(double b, double s) : salariedemployee(s)
    {
        salary = s;
        bouns = b;
    }
    ~mangeremployee()
    {
    }
    void addbouns(double morebouns)
    {
        bouns += morebouns;
    }
    double getsalary()
    {
        return salary + bouns;
    }
    string displaydetails()
    {
        return salariedemployee::displaydetails() + "\nBouns : " + to_string(bouns);
    }
    double calculatepay()
    {
        return getsalary();
    }
    void getinfo()
    {
        salariedemployee::getinfo();
        cout << "Enter Bouns : ";
        cin >> bouns;
    }
};

#endif