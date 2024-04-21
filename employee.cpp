#include <iostream>

#include "healthbenefit.cpp"
#include "dentalbenefit.cpp"
#include "department.cpp"

using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class employee
{
protected:
    int employeeid;
    string name;
    string phone;
    string email;
    string jobtitle;
    department *d;

private:
    benefit **benefitlist;
    int benefit_count;
    int benefit_size;

public:
    employee()
    {
        benefit_count = 0;
        benefit_size = 2;
        benefitlist = new benefit *[benefit_size];
        d = nullptr;
    }

    virtual ~employee()
    {
        for (int i = 0; i < benefit_count; i++)
            delete benefitlist[i];

        delete[] benefitlist;
    }
    virtual void getinfo()
    {
        cin.ignore();

        cout << "\n-----------------------------------------\n";
        cout << "Enter Name :  ";
        getline(cin, name);
        // cin.ignore();
        cout << "Phone number : ";
        cin >> phone;
        cout << "Email : ";
        cin >> email;
        cin.ignore();
        cout << "Job title : ";
        getline(cin, jobtitle);
    }
    virtual string displaydetails()
    {
        return "\nName : " + name + "\nPhone : " + phone + "\nEmail : " + email + "\nJob title : " + jobtitle + "\n" + ((d != nullptr) ? d->print() : " ");
    }
    void displaybe()
    {
        for (int i = 0; i < benefit_count; i++)
        {
            cout << i + 1 << "-" << benefitlist[i]->displaybenefit() << endl;
        }
    }
    void addbenefit()
    {
        int n, Hb = 0, Db = 0;
        ;
        bool f = 0;
        if (benefit_count < 2)
        {
            cout << "How many Benefits ? (0-" << benefit_size - benefit_count << ") : ";
            cin >> n;
            for (int i = 0; i < n; i++)
            {
                int c;
                cout << "\t1- Health Benefit \n"
                     << "\t2- Dental Benefit \n"
                     << "Enetr Choise --> ";
                cin >> c;
                switch (c)
                {
                case 1:
                    if (Hb < 1)
                    {
                        benefitlist[benefit_count] = new healthbenefit();
                        benefitlist[benefit_count++]->readinput();
                        Hb++;
                    }
                    else
                        f = 1;
                    break;

                case 2:
                    if (Db < 1)
                    {
                        benefitlist[benefit_count] = new dentalbenefit();
                        benefitlist[benefit_count++]->readinput();
                        Db++;
                    }
                    else
                        f = 1;
                    break;
                }

                if (f)
                {
                    cout << "Already Has One !\n";
                }
            }
        }
    }
    void editbe(int n)
    {
        for (int i = 0; i < n; i++)
            benefitlist[i]->readinput();
    }

    void setid(int id)
    {
        employeeid = id;
    }
    int getid()
    {
        return employeeid;
    }
    void nameprint()
    {
        cout << "ID : " << employeeid << "\nName : " << name << endl;
    }
    void setDepart(department *de)
    {
        d = de;
    }

    void delbe()
    {

        if (benefit_count == 0)
        {
            cout << "NO Benefits EXIST!\n";
            return;
        }
        bool deleted = false;

        for (int i = 0; i < benefit_count; i++)
        {
            benefitlist[i]->displaybenefit();
            cout << "\n------------------------------------------";
        }
        int delid;
        cout << "Enter Benefit's ID to Delete : ";
        cin >> delid;

        for (int i = 0; i < benefit_count; ++i)
        {
            if (i == delid - 1)
            {
                if (i == benefit_count - 1)
                {
                    benefit_count--;
                }
                else
                {
                    benefitlist[i] = benefitlist[benefit_count - 1];
                    benefit_count--;
                }
                deleted = true;
                break;
            }
        }
        if (deleted)
        {
            cout << "Benefit DELETED SUCCESSFULLY !\n";
        }
        else
        {
            cout << "NO Benefit EXIST!\n";
        }
    }
    virtual double getsalary() = 0;
    virtual double calculatepay() = 0;
};

#endif