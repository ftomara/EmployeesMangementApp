#include <iostream>
#include "employee.cpp"
#include "mangeremployee.cpp"
#include "department.cpp"
#include "hourlyemployee.cpp"
#include "commissionemployee.cpp"
using namespace std;
#ifndef HRSYSTEM_H
#define HRSYSTEM_H

class hrsystem
{
private:
    employee **employeelist;
    int employee_count;
    int employee_size;
    int dep_size;
    department d[10];
    int dep_count;

public:
    hrsystem() {}
    hrsystem(int size1)
    {
        employee_size = size1;
        employeelist = new employee *[employee_size];
        employee_count = 0;
        for (int i = 0; i < employee_size; i++)
        {
            employeelist[i] = nullptr;
        }

        dep_count = 0;
    }
    ~hrsystem()
    {
        for (int i = 0; i < employee_count; i++)
            delete employeelist[i];

        delete[] employeelist;
    }
    void calctotalpayroll()
    {
        double total = 0;

        cout << "\t\tEmployees Total Payroll :\n\n";
        for (int i = 0; i < employee_count; i++)
        {
            total += employeelist[i]->calculatepay();
        }

        cout << "\tTotal Payroll = " << total;
    }
    void addemployee()
    {
        int n;
        cout << "How many ? (0-" << employee_size - employee_count << ") : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int c;
            bool f = 1;
            cout << "\nChoose Employee NO." << employee_count + 1 << " Type : \n";
            cout << "\t1-Hourly Employee\n"
                 << "\t2-Commission Employee\n"
                 << "\t3-Salaried Employee\n"
                 << "\t4-Manger Employee\n";
            cout << "Enter Selection ==> ";
            cin >> c;

            switch (c)
            {
            case 1:
            {
                employeelist[employee_count] = new hourlyemployee();
            }
            break;
            case 2:
            {

                employeelist[employee_count] = new commissionemployee();
            }
            break;
            case 3:
            {
                employeelist[employee_count] = new salariedemployee();
            }
            break;

            case 4:
            {
                employeelist[employee_count] = new mangeremployee();
            }
            break;
            default:
                f = 0;
                break;
            }
            if (f)
            {
                cout << " Enter Employee NO." << employee_count + 1 << " INFO : \n";
                employeelist[employee_count]->getinfo();

                employeelist[employee_count]->addbenefit();
                employeelist[employee_count]->setid(employee_count + 1);
            }
            if (dep_count > 0)
            {
                int f;
                cout << "Do You Want to Assign This Employee to a Department? (1-Yes , 0-No) ";
                cin >> f;
                if (f)
                {
                    cout << "For which Department ? ";
                    for (int i = 0; i < dep_count; i++)
                    {
                        cout << d[i].print();
                    }
                    cout << "Enetr Selection : ";
                    cin >> f;
                    employeelist[employee_count]->setDepart(&d[f - 1]);
                    cout << "Employee Has Been Added Successfully!";
                }
            }
            employee_count++;
        }
    }
    void adddepartment()
    {
        int n;
        cout << "How many Departments ? ( 0 - " << 10 - dep_count << ") : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            d[dep_count].getinfo(dep_count);
            dep_count++;
        }
    }

    void assign_employee()
    {
        if (dep_count > 0)
        {
            int depid, empid;

            cout << "\t\tEmployees List :\n\n";
            cout << "-----------------------------------------------\n";
            for (int i = 0; i < employee_count; i++)
            {
                employeelist[i]->nameprint();
                cout << "-----------------------------------------------\n";
            }
            cout << endl;

            cout << "\t\tDepartment List :\n\n";
            cout << "-----------------------------------------------\n";
            for (int i = 0; i < dep_count; i++)
            {
                d[i].print_depandemp();
                cout << "-----------------------------------------------\n";
            }
            cout << "Enter Epmloyee's ID & Department ID Please : ";
            cout << "\nEMP ID : ";
            cin >> empid;
            cout << "\nDEP ID : ";
            cin >> depid;

            employeelist[empid - 1]->setDepart(&d[depid - 1]);
            cout << "Employee Has Been Added Successfully!";
        }
        else
            cout << "There is No Departments to Assign the Employee at !";
    }
    void editemployee()
    {
        int edid;

        if (employee_count == 0)
            cout << "\nThere are No Employees  to search for ! \n";
        else
        {
            for (int i = 0; i < employee_count; i++)
                employeelist[i]->nameprint();
            cout << "\nEnter Employee ID to Edit please : ";
            cin >> edid;
            while (edid > employee_count)
            {
                cout << "\nThere is No Employees with this Id\n";
                cout << "Please Enter valid ID : ";
                cin >> edid;
                if (edid <= employee_count)
                    break;
            }
            employeelist[edid - 1]->getinfo();

            int b;
            employeelist[edid - 1]->displaybe();
            cout << "Enetr how many Benefit You want to Edit : ";
            cin >> b;
            employeelist[edid - 1]->editbe(b);
            cout << "Employee Edited Sccessfully ! ";
        }
    }
    void delemployee()
    {

        if (employee_count == 0)
        {
            cout << "NO Employees EXIST!\n";
            return;
        }
        bool deleted = false;

        for (int i = 0; i < employee_count; i++)
        {
            employeelist[i]->nameprint();
        }
        int delid;
        cout << "Enter Employee's ID to Delete : ";
        cin >> delid;

        for (int i = 0; i < employee_count; ++i)
        {
            if (employeelist[i]->getid() == delid)
            {
                if (i == employee_count - 1)
                {
                    employee_count--;
                }
                else
                {
                    employeelist[i] = employeelist[employee_count - 1];
                    employee_count--;
                }
                deleted = true;
                break;
            }
        }
        if (deleted)
        {
            cout << "Employee DELETED SUCCESSFULLY !\n";
        }
        else
        {
            cout << "NO Employee EXIST!\n";
        }
    }
    void findemployee()
    {
        int id;
        if (employee_count == 0)
            cout << "\nThere are No Employees to search for ! \n";
        else
        {
            cout << "\nEnter EmployeeID to find please..";
            cin >> id;
            while (id > employee_count)
            {
                cout << "\nThere is No Employee with this Id\n";
                cout << "Please Enter valid ID : ";
                cin >> id;
                if (id <= employee_count)
                    break;
            }
            cout << "\n-------------------------------------------------------------------------------\n";
            cout << "Employee NO." << id << endl;
            cout << employeelist[id - 1]->displaydetails() << endl;
            employeelist[id - 1]->displaybe();
            cout << "\n-------------------------------------------------------------------------------\n";
        }
    }
    void showall()
    {

        cout << "\t\tEmployees List :\n\n";
        for (int i = 0; i < employee_count; i++)
        {
            cout << "\n__________________________________________________________________________________________\n";
            cout << "EMP NO. " << i + 1 << endl;
            cout << employeelist[i]->displaydetails() << endl;
            employeelist[i]->displaybe();
        }
    }
    void showdeps()
    {
        cout << "\t\tDepartments List :\n\n";
        cout << "\n_____________________________________\n";
        for (int i = 0; i < dep_count; i++)
        {
            d[i].print_depandemp();
        }
    }
    void addbenefitt()
    {
        int n;
        cout << "For which Employee ? ";
        for (int i = 0; i < employee_count; i++)
            employeelist[i]->nameprint();
        cout << "Enter Selection--> ";
        cin >> n;
        employeelist[n - 1]->addbenefit();
    }
    void delebe()
    {
        int n;
        cout << "For which Employee ? ";
        for (int i = 0; i < employee_count; i++)
            employeelist[i]->nameprint();
        cout << "Enter Selection--> ";
        cin >> n;
        employeelist[n - 1]->delbe();
    }
};

#endif