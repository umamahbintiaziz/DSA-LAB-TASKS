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

void push(string word)
{
    Node* newNode=new Node;
    newNode->data=word;
    newNode->next=top;
    top=newNode;
    cout<<"Typed: "<<word<<endl;
}

void pop()
{
    if(isEmpty())
    {
        cout<<"Nothing to undo"<<endl;
    }
    else
    {
        Node* temp=top;
        cout<<"Undone: "<<temp->data<<endl;
        top=top->next;
        delete temp;
    }
}

void peek()
{
    if(isEmpty())
    {
        cout<<"Editor is empty"<<endl;
    }
    else
    {
        cout<<"Last word: "<<top->data<<endl;
    }
}

int size()
{
    int count=0;
    Node* current=top;
    while(current!=NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}

void display()
{
    if(isEmpty())
    {
        cout<<"Editor is empty"<<endl;
    }
    else
    {
        Node* current=top;
        cout<<"Words (latest first): ";
        while(current!=NULL)
        {
            cout<<current->data<<" ";
            current=current->next;
        }
        cout<<endl;
    }
}

int main()
{
    int choice;
    string word;

    do
    {
        cout<<"\nMENU"<<endl;
        cout<<"1. Type Word"<<endl;
        cout<<"2. Undo"<<endl;
        cout<<"3. Last Word"<<endl;
        cout<<"4. Word Count"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;

        switch(choice)
        {
            case 1:
            {
                cout<<"Enter word: ";
                cin>>word;
                push(word);
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
                cout<<"Word count: "<<size()<<endl;
                break;
            }
            case 5:
            {
                display();
                break;
            }
            case 6:
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
    while(choice!=6);

    while(!isEmpty())
    {
        Node* temp=top;
        top=top->next;
        delete temp;
    }

    return 0;
}