#include <iostream>
#include "benefit.cpp"
using namespace std;
#ifndef HEALTHBENEFIT_H
#define HEALTHBENEFIT_H

class healthbenefit : public benefit
{
private:
    string info;
    string coverage;

public:
    virtual ~healthbenefit(){};
    double calculatebenefit()
    {
        return 0.2 * amount;
    }
    string getdetails()
    {
        return "\nHelathBenefit Info : " + info + "\n Coverage : " + coverage + "\nBenefit Amount : " + to_string(calculatebenefit());
    }
    string displaybenefit()
    {
        return benefit::displaybenefit() + getdetails();
    }
    void readinput()
    {
        benefit::readinput();
        cout << "Enetr Health Benefit Info : ";
        getline(cin, info);
        cout << "Enter Coverage : ";
        getline(cin, coverage);
    }
};

#endif