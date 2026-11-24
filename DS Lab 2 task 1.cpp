#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    int *p1=&a;
    int *p2=&b;
    int *p3=&c;
    int maximum=*p1;
    cout<<"Enter three numbers: ";
    cout<<"Enter first number: ";
    cin>>a;
	cout<<"Enter second number: ";
	cin>>b;
	cout<<"Enter third number: ";
	cin>>c;
    if(*p2>maximum)
    {
        maximum=*p2;
    }
    if (*p3>maximum)
    {
        maximum=*p3;
    }
    cout<<"Maximum value: "<<maximum<<endl;
    return 0;
}