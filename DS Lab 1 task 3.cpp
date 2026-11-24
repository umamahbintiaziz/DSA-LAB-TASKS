#include <iostream>
using namespace std;

struct Employee
{
    int id;
    string name;
    float basicSalary;
    float allowance;
};

int main()
{
    Employee e;
    float grossSalary;
    float tax;
    float finalSalary;

    cout<<"Enter Employee ID: ";
    cin>>e.id;
    cout<<"Enter Employee Name: ";
    cin>>e.name;
    cout<<"Enter Basic Salary: ";
    cin>>e.basicSalary;
    cout<<"Enter Allowance: ";
    cin>>e.allowance;
    grossSalary=e.basicSalary+e.allowance;
    if(grossSalary>100000)
    {
        tax=grossSalary*0.05;
    }
    else
    {
        tax=grossSalary*0.02;
    }
    finalSalary=grossSalary-tax;
    cout<<"Employee Salary Details"<<endl;
    cout<<"Employee ID: "<<e.id<<endl;
    cout<<"Employee Name: "<<e.name<<endl;
    cout<<"Basic Salary: "<<e.basicSalary<<endl;
    cout<<"Allowance: "<<e.allowance<<endl;
    cout<<"Gross Salary: "<<grossSalary<<endl;
    cout<<"Tax: "<< tax<<endl;
    cout<<"Final Salary: "<<finalSalary<<endl;

    return 0;
}