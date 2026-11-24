#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data=value;
        next=NULL;
    }
};

int main()
{
    Node n1(2);
    Node n2(7);
    Node n3(3);

    n1.next=&n2;
    n2.next=&n3;
    n3.next=NULL;
    Node *ptr=&n1;
    cout<<"Linked List:"<<endl;
    while (ptr != NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->next;
    }
    return 0;
}