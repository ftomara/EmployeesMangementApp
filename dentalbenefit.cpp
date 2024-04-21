#include <iostream>
#include "benefit.cpp"
using namespace std;
#ifndef DENTALBENEFIT_H
#define DENTALBENEFIT_H

class dentalbenefit : public benefit
{
protected:
    string info;

public:
    virtual ~dentalbenefit(){};
    double calculatebenefit()
    {
        return 0.1 * amount;
    }
    string getdetails()
    {
        return "\nDental Benefit Info : " + info + "\nBenefit Amount : " + to_string(calculatebenefit());
    }
    string displaybenefit()
    {
        return benefit::displaybenefit() + getdetails();
    }
    void readinput()
    {
        benefit::readinput();
        cout << "Enter Health Benefit Info : ";
        getline(cin, info);
    }
};

#endif