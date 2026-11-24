#include <iostream>
using namespace std;

int main()
{
    float balance;
    float deposit;
    float withdrawal;
    float *ptr=&balance;
    cout<<"Enter initial balance: ";
    cin>>balance;

    cout<<"Enter deposit amount: ";
    cin>>deposit;
    *ptr=*ptr+deposit;
    cout<<"Balance after deposit: "<<*ptr<<endl;
    cout<<"Enter withdrawal amount: ";
    cin>>withdrawal;
    if (withdrawal<=*ptr)
    {
        *ptr=*ptr-withdrawal;
        cout<<"Balance after withdrawal: "<<*ptr<<endl;
    }
    else
    {
        cout<<"Insufficient balance."<<endl;
    }
    return 0;
}