#include <iostream>
using namespace std;

int main()
{
    int arr[5];
    int *start=arr;
    int *end=arr+4;
    cout<<"Enter 5 elements:"<<endl;
    for(int i=0;i<5;i++)
    {
        cin>>arr[i];
    }
    while(start<end)
    {
        int temp=*start;
        *start=*end;
        *end=temp;
        start++;
        end--;
    }
    cout<<"Reversed Array:"<<endl;
    for(int i=0;i<5;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}