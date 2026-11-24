#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* top=NULL;

bool isEmpty()
{
    return top==NULL;
}

void push(int x)
{
    Node* newNode=new Node;
    newNode->data=x;
    newNode->next=top;
    top=newNode;
}

void pop()
{
    if(isEmpty())
    {
        cout<<"Stack Underflow"<<endl;
    }
    else
    {
        Node* temp=top;
        cout<<temp->data;
        top=top->next;
        delete temp;
    }
}

int main()
{
    int num,remainder;

    cout<<"Enter decimal number: ";
    cin>>num;

    if(num<0)
    {
        cout<<"Enter a non-negative number"<<endl;
    }
    else if(num==0)
    {
        cout<<"Binary: 0"<<endl;
    }
    else
    {
        while(num>0)
        {
            remainder=num%2;
            push(remainder);
            num=num/2;
        }

        cout<<"Binary: ";
        while(!isEmpty())
        {
            pop();
        }
        cout<<endl;
    }

    return 0;
}