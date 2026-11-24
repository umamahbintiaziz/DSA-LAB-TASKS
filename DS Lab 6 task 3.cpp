#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};
void deleteByValue(Node*& head, int value)
{
    if (head==nullptr)
    {
        cout<<"Value not found"<<endl;
        return;
    }
    if (head->data==value)
    {
        Node* temp=head;
        head=head->next;
        delete temp;
        return;
    }
    Node* temp=head;
    while (temp->next!=nullptr && temp->next->data!=value)
    {
        temp=temp->next;
    }
    if (temp->next==nullptr)
    {
        cout<<"Value not found"<<endl;
    }
    else
    {
        Node* deleteNode=temp->next;
        temp->next=deleteNode->next;
        delete deleteNode;
    }
}
void display(Node* head)
{
    Node* temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    Node* n1=new Node;
    Node* n2=new Node;
    Node* n3=new Node;
    Node* n4=new Node;
    Node* n5=new Node;
    
    n1->data=10;
    n2->data=20;
    n3->data=30;
    n4->data=40;
    n5->data=50;
    
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=n5;
    n5->next=nullptr;
    
    Node* head=n1;
    int value;
    cout<<"Enter value to delete: ";
    cin>>value;
    deleteByValue(head,value);
    display(head);
    return 0;
}