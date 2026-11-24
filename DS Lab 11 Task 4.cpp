#include <iostream>
#include <stack>
using namespace std;
#define SIZE 5
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
        cout<<"Queue is FULL!"<<endl;
        return;
    }
    rear++;
    items[rear]=value;
}

void dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is EMPTY!"<<endl;
        return;
    }
    front++;
    if(front>rear)
    {
        front=0;
        rear=-1;
    }
}

void display()
{
    if(isEmpty())
    {
        cout<<"Queue is EMPTY!"<<endl;
        return;
    }
    cout<<"Queue: ";
    for(int i=front;i<=rear;i++)
    {
        cout<<items[i]<<" ";
    }
    cout<<endl;
}

void reverseQueue()
{
    stack<int> s;
    while(!isEmpty())
    {
        s.push(items[front]);
        dequeue();
    }
    while(!s.empty())
    {
        enqueue(s.top());
        s.pop();
    }
    cout<<"Queue reversed successfully!"<<endl;
}

int main()
{
    int choice,value;
    do
    {
        cout<<"\nMENU"<<endl;
        cout<<"1. Enqueue"<<endl;
        cout<<"2. Dequeue"<<endl;
        cout<<"3. Display"<<endl;
        cout<<"4. Reverse Queue"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                cout<<"Enter value: ";
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
                display();
                break;
            }
            case 4:
            {
                reverseQueue();
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