#include <iostream>
using namespace std;

int main()
{
    int marks[10];
    int sum=0;
    int highest, lowest;
    int pass=0, fail=0;
    float average=sum/10.0;
    cout<<"Enter marks of 10 students:"<<endl;
    for(int i=0;i<10;i++)
    {
        cin>>marks[i];
    }
    highest=marks[0];
    lowest=marks[0];
    cout<<"Student Marks:"<<endl;
    for(int i=0;i<10;i++)
    {
        cout<<marks[i]<< " ";
        sum=sum+marks[i];
        if(marks[i]>highest)
        {
            highest=marks[i];
        }
        if(marks[i]<lowest)
        {
            lowest=marks[i];
        }
        if(marks[i]>=50)
        {
            pass++;
        }
        else
        {
            fail++;
        }
    }
    cout<<"Average Marks: "<<average<<endl;
    cout<<"Highest Marks: "<<highest<<endl;
    cout<<"Lowest Marks: "<<lowest<<endl;
    cout<<"Passed Students: "<<pass<<endl;
    cout<<"Failed Students: "<<fail<<endl;
    return 0;
}