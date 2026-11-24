#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
int main()
{
    Node* head=nullptr;
    Node* temp=nullptr;
    int choice;
    do
    {
        cout<<"1. Insert at Start"<<endl;
        cout<<"2. Insert at End"<<endl;
        cout<<"3. Insert in Middle"<<endl;
        cout<<"4. Display List"<<endl;
        cout<<"5. Exit"<<endl;
        cout<<"Enter choice: ";
        cin>>choice;
        if (choice==1)
        {
            Node* newNode=new Node;
            cout<<"Enter value: ";
            cin>>newNode->data;
            newNode->next=head;
            head=newNode;
        }
        else if (choice==2)
        {
            Node* newNode=new Node;
            cout<<"Enter value: ";
            cin>>newNode->data;
            newNode->next=nullptr;
            if (head==nullptr)
            {
                head=newNode;
            }
            else
            {
                temp=head;
                while (temp->next!=nullptr)
                {
                    temp=temp->next;
                }
                temp->next=newNode;
            }
        }
        else if (choice==3)
        {
            int afterValue, newValue;
            cout<<"Enter value after which you want to insert: ";
            cin>>afterValue;
            cout<<"Enter new value: ";
            cin>>newValue;
            temp=head;
            while (temp!=nullptr && temp->data!=afterValue)
            {
                temp=temp->next;
            }
            if (temp==nullptr)
            {
                cout<<"Value not found";
            }
            else
            {
                Node* newNode=new Node;
                newNode->data=newValue;
                newNode->next=temp->next;
                temp->next=newNode;
            }
        }
        else if (choice==4)
        {
            cout<<"Linked List: ";
            temp=head;
            while (temp!=nullptr)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
    }
    while (choice!=5);
    return 0;
}