#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
Node* front=NULL;
Node* rear=NULL;

bool isEmpty()
{
    return front==NULL;
}

void enqueue(int value)
{
    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=NULL;
    if(isEmpty())
    {
        front=newNode;
        rear=newNode;
    }
    else
    {
        rear->next=newNode;
        rear=newNode;
    }
    cout<<value<<" added to the queue."<<endl;
}

void dequeue()
{
    if(isEmpty())
    {
        cout<<"Queue is EMPTY!"<<endl;
        return;
    }
    Node* temp=front;
    cout<<temp->data<<" removed from the queue."<<endl;
    front=front->next;
    if(front==NULL)
    {
        rear=NULL;
    }
    delete temp;
}

void peek()
{
    if(isEmpty())
    {
        cout<<"Queue is EMPTY!"<<endl;
        return;
    }
    cout<<"Front element: "<<front->data<<endl;
}

void display()
{
    if(isEmpty())
    {
        cout<<"Queue is EMPTY!"<<endl;
        return;
    }
    Node* temp=front;
    cout<<"FRONT -> ";
    while(temp!=NULL)
    {
        cout<<temp->data<<" -> ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

int countNodes()
{
    int count=0;
    Node* temp=front;
    while(temp!=NULL)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void displayRear()
{
    if(isEmpty())
    {
        cout<<"Queue is EMPTY!"<<endl;
    }
    else
    {
        cout<<"Rear element: "<<rear->data<<endl;
    }
}

void clearQueue()
{
    while(!isEmpty())
    {
        Node* temp=front;
        front=front->next;
        delete temp;
    }
    rear=NULL;
    cout<<"Queue cleared"<<endl;
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
        cout<<"5. Count Nodes"<<endl;
        cout<<"6. Display Rear"<<endl;
        cout<<"7. Clear Queue"<<endl;
        cout<<"8. Exit"<<endl;
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
                cout<<"Total nodes: "<<countNodes()<<endl;
                break;
            }
            case 6:
            {
                displayRear();
                break;
            }
            case 7:
            {
                clearQueue();
                break;
            }
            case 8:
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
    while(choice!=8);
    while(!isEmpty())
    {
        Node* temp=front;
        front=front->next;
        delete temp;
    }
    rear=NULL;
    return 0;
}