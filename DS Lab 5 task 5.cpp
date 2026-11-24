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
    int n;
    cout<<"Enter number of values: ";
    cin>>n;
    for (int i=0;i<n;i++)
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
    int beforeValue, newValue;
    cout<<"Enter value before which you want to insert: ";
    cin>>beforeValue;
    cout<<"Enter new value: ";
    cin>>newValue;
    temp=head;
    Node* previous=nullptr;
    while (temp!=nullptr && temp->data!=beforeValue)
    {
        previous=temp;
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
        if (temp==head)
        {
            newNode->next=head;
            head=newNode;
        }
        else
        {
            newNode->next=temp;
            previous->next=newNode;
        }
    }
    cout<<"Linked List: ";
    temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}