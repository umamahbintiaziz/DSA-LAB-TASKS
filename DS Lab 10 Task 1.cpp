#include <iostream>
#include <string>
using namespace std;

struct Node
{
    string data;
    Node* next;
};

Node* top=NULL;

bool isEmpty()
{
    return top==NULL;
}

void push(string page)
{
    Node* newNode=new Node;
    newNode->data=page;
    newNode->next=top;
    top=newNode;
    cout<<"Visited: "<<page<<endl;
}

void pop()
{
    if(isEmpty() || top->next==NULL)
    {
        cout<<"Cannot go back"<<endl;
    }
    else
    {
        Node* temp=top;
        top=top->next;
        delete temp;
        cout<<"Current page: "<<top->data<<endl;
    }
}

void peek()
{
    if(isEmpty())
    {
        cout<<"No page visited"<<endl;
    }
    else
    {
        cout<<"Current page: "<<top->data<<endl;
    }
}

void display()
{
    if(isEmpty())
    {
        cout<<"History is empty"<<endl;
    }
    else
    {
        Node* current=top;
        cout<<"Browser History: "<<endl;
        while(current!=NULL)
        {
            cout<<current->data<<endl;
            current=current->next;
        }
    }
}

int main()
{
    int choice;
    string page;
    do
    {
        cout<<"\nMENU"<<endl;
        cout<<"1. Visit Page"<<endl;
        cout<<"2. Back"<<endl;
        cout<<"3. Current Page"<<endl;
        cout<<"4. History"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                cout<<"Enter page name: ";
                cin>>page;
                push(page);
                break;
            }
            case 2:
            {
                pop();
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

    while(!isEmpty())
    {
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    return 0;
}