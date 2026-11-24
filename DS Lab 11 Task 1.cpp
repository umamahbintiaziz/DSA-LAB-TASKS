#include <iostream>
using namespace std;
#define SIZE 6
int items[SIZE];
int front=0;
int rear=-1;

bool isEmpty()
{
    return front>rear;
}

bool isFull()
{
    return rear==SIZE-1;
}

void enqueue(int value)
{
    if(isFull())
    {
        cout<<"Waiting room is FULL!"<<endl;
        return;
    }
    rear++;
    items[rear]=value;
    cout<<"Token "<<value<<" issued"<<endl;
}

void dequeue()
{
    if(isEmpty())
    {
        cout<<"No customers waiting"<<endl;
        return;
    }
    cout<<"Serving customer with token "<<items[front]<<endl;
    front++;
}

void display()
{
    if(isEmpty())
    {
        cout<<"No customers waiting"<<endl;
        return;
    }
    cout<<"Waiting customers: ";
    for(int i=front;i<=rear;i++)
    {
        cout<<items[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    int choice,token;
    do
    {
        cout<<"\nMENU"<<endl;
        cout<<"1. Issue Token"<<endl;
        cout<<"2. Serve Customer"<<endl;
        cout<<"3. Show Waiting Customers"<<endl;
        cout<<"4. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                cout<<"Enter token number: ";
                cin>>token;
                enqueue(token);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                display();
                break;
            }
            case 4:
            {
                cout<<"Exit"<<endl;
                break;
            }
            default:
            {
                cout<<"Invalid choice"<<endl;
            }
        }
    }
    while(choice!=4);
    return 0;
}