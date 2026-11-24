#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* prev;
    Node* next;
};
int main()
{
    Node* first=new Node();
    Node* second=new Node();
    Node* third=new Node();
    Node* fourth=new Node();
    Node* fifth=new Node();
    
    first->data=101;
    second->data=102;
    third->data=103;
    fourth->data=104;
    fifth->data=105;
    
    first->prev=nullptr;
    first->next=second;
    
    second->prev=first;
    second->next=third;
    
    third->prev=second;
    third->next=fourth;
    
    fourth->prev=third;
    fourth->next=fifth;
    
    fifth->prev=fourth;
    fifth->next=nullptr;
    
    Node* head=first;
    Node* tail=fifth;
    
    Node* newNode=new Node();
    newNode->data=100;
    newNode->prev=nullptr;
    newNode->next=head;
    head->prev=newNode;
    head=newNode;
    
    Node* middleNode=new Node();
    middleNode->data=1035;
    middleNode->prev=third;
    middleNode->next=fourth;
    third->next=middleNode;
    fourth->prev=middleNode;
    
    Node* lastNode=new Node();
    lastNode->data=106;
    lastNode->prev=tail;
    lastNode->next=nullptr;
    tail->next=lastNode;
    tail=lastNode;
    
    Node* temp=head;
    head=head->next;
    head->prev=nullptr;
    delete temp;
    
    temp=fourth;
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    delete temp;
    
    temp=tail;
    tail=tail->prev;
    tail->next=nullptr;
    delete temp;
    
    cout<<"Final List: ";
    temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return 0;
}