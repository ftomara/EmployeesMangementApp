#include <iostream>

using namespace std;
#ifndef DEPARTMENT_H
#define DEPARTMENT_H

class department
{
private:
    int depatid;
    string departmentname;

public:
    department()
    {
    }

    ~department()
    {
    }
    void getinfo(int i)
    {

        depatid = i + 1;
        cin.ignore();
        cout << "Enter Department Name : ";
        getline(cin, departmentname);
    }
    string print()
    {
        return "\nID : " + to_string(depatid) + "\tDepartment Name : " + departmentname + "\n";
    }

    void print_depandemp()
    {
        cout << "ID : ";
        cout << depatid << endl;
        cout << "Department Name : ";
        cout << departmentname << endl;
    }
    int getid()
    {
        return depatid;
    }
    string getname()
    {
        return departmentname;
    }
};

#endif