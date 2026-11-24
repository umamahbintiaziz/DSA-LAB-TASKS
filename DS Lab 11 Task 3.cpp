#include <iostream>
using namespace std;
#define SIZE 4
int items[SIZE];
int front=0;
int rear=-1;
int itemCount=0;

bool isEmpty()
{
    return itemCount==0;
}

bool isFull()
{
    return itemCount==SIZE;
}

void enqueue(int value)
{
    if(isFull())
    {
        cout<<"Queue is FULL! Cannot add "<<value<<endl;
        return;
    }
    int old=rear;
    rear=(rear+1)%SIZE;
    items[rear]=value;
    itemCount++;
    cout<<value<<" added at index "<<rear;
    cout<<" [rear = ("<<old<<" + 1) % "<<SIZE;
    cout<<" = "<<rear<<"]"<<endl;
}

void dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is EMPTY! Nothing to remove."<<endl;
        return;
    }
    int old=front;
    cout<<items[front]<<" removed from index "<<front;
    front=(front+1)%SIZE;
    itemCount--;
    cout<<" [front = ("<<old<<" + 1) % "<<SIZE;
    cout<<" = "<<front<<"]"<<endl;
}

void peek()
{
    if(isEmpty())
    {
        cout<<"Queue is EMPTY!"<<endl;
        return;
    }
    cout<<"Front element: "<<items[front]<<endl;
}

void display()
{
    if(isEmpty())
    {
        cout<<"Queue is EMPTY!"<<endl;
        return;
    }
    cout<<"FRONT -> ";
    for(int i=0;i<itemCount;i++)
    {
        int index=(front+i)%SIZE;
        cout<<items[index]<<" ";
    }
    cout<<"<- REAR"<<endl;
    cout<<"(front = "<<front<<", rear = "<<rear;
    cout<<", count = "<<itemCount<<")"<<endl;
}

int main()
{
    int choice,value;
    do
    {
        cout<<"\nMENU"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Peek"<<endl;
        cout<<"4. Display"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter printer job ID: ";
                cin>>value;
                enqueue(value);
                break;
            }
            case 2:
            {
                dequeue();
                break;
            }
            case 3:
            {
                peek();
                break;
            }
            case 4:
            {
                display();
                break;
            }
            case 5:
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
    while(choice!=5);
    return 0;
}