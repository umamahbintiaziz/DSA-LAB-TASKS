#include <iostream>
#include <string>
using namespace std;

struct Product
{
    string name;
    int code;
    float price;
};
int main()
{
    int n;
    cout<<"Enter the number of products: ";
    cin>>n;
    Product* p=new Product[n];
    for (int i=0;i<n;i++)
    {
        cout<<"Enter the details for product "<<i+1<<endl;
        cout<<"Name: ";
        cin>>p[i].name;
        cout<<"Code: ";
        cin>>p[i].code;
        cout<<"Price: ";
        cin>>p[i].price;
    }
    cout<<"Product Details"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<"Product: "<<i+1<<endl;
        cout<<"Name: "<<p[i].name<<endl;
        cout<<"Code: "<<p[i].code<<endl;
        cout<<"Price: "<<p[i].price<<endl;
    }
    delete[] p;
    p = nullptr;

    return 0;
}