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
    Node* newNode=new Node;
    cout<<"Enter value to insert at end: ";
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
    cout<<"Linked List: ";
    temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<< " ";
        temp=temp->next;
    }
    return 0;
}