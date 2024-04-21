#include <iostream>
using namespace std;
#ifndef BENEFIT_H
#define BENEFIT_H

class benefit
{
protected:
    string plantype;
    double amount;

public:
    virtual ~benefit(){};
    virtual double calculatebenefit() = 0;
    virtual string displaybenefit()
    {
        return "Plan Type : " + plantype + "\tAmount : " + to_string(amount);
    }

    virtual void readinput()
    {
        cout << "Enter BenefitPlan : ";
        cin >> plantype;
        cout << "Enter Amount : ";
        cin >> amount;
        cin.ignore();
    }
};

#endif