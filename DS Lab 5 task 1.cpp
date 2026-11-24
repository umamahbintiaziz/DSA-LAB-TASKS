#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};
int main()
{
    int n;
    cout<<"Enter number of values: ";
    cin>>n;
    Node* head=nullptr;
    Node* temp=nullptr;
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
    int value;
    cout<<"Enter value to insert at beginning: ";
    cin>>value;
    Node* newNode=new Node;
    newNode->data=value;
    newNode->next=head;
    head=newNode;
    cout<<"Linked List: ";
    temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<< " ";
        temp=temp->next;
    }

    return 0;
}