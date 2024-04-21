#include <iostream>
#include <string>
#include <ctime>
#include <unistd.h>
#include "hrsystem.cpp"

using namespace std;

void print(string s)
{
    cout << s;
}
int main()
{

    int c;
    hrsystem e(100);
    while (c != 0)
    {
        // sleep(2);
        // system("clear");
        print("\n\n\t\t\t\t----------------------------------------- \n");
        print("\n\n\t\t\t\t\" Welcome to Employee Mangement App \"\n");
        print("\n\n\t\t\t\t----------------------------------------- \n");
        print("\t\t1.Add New Employee \n");
        print("\t\t2.Edit Employee \n");
        print("\t\t3.Delete Employee\n");
        print("\t\t4.Add New Benefit \n");
        print("\t\t5.Delete Benefit\n");
        print("\t\t6.Add New Department\n");
        print("\t\t7.Assign Employee to Department\n");
        print("\t\t8.Calculate Salary \n");
        print("\t\t9.Information Reports \n");
        print("\t\t10.Information Reports For Departments \n");
        print("\t\t11.Search for Employee \n");
        print("\t\t0.Exit Program\n");
        print("Enter Selection --->  ");
        cin >> c;

        switch (c)
        {
        case 1:
            e.addemployee();
            break;
        case 2:
            e.editemployee();
            break;
        case 3:
            e.delemployee();
            break;
        case 4:
            e.addbenefitt();
            break;
        case 5:
            e.delebe();
            break;
        case 6:
            e.adddepartment();
            break;
        case 7:
            e.assign_employee();
            break;
        case 8:
            e.calctotalpayroll();
            break;
        case 9:
            e.showall();
            break;
        case 10:
            e.showdeps();
            break;
        case 11:
            e.findemployee();
            break;
        case 0:
            print("\t\t\t\t Session is over....\n");
            // sleep(2);
            // system("clear");
            break;
        default:
            print("\n\nINVALID\n");
            // sleep(2);
            // system("clear");
        }
    }

    return 0;
}