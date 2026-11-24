#include <iostream>
using namespace std;
const int MAX=5;
int stk[MAX];
int top=-1;

void push(int x)
{
    if(top==MAX-1)
    {
        cout<<"Stack overflow\n";
    }
    else
    {
        top++;
        stk[top]=x;
        cout<<x<<" pushed\n";
    }
}

void pop()
{
    if(top==-1)
    {
        cout<<"Stack underflow\n";
    }
    else
    {
        cout<<"Popped: "<<stk[top]<<"\n";
        top--;
    }
}

int search(int x)
{
    int steps=1;
    for(int i=top;i>=0;i--)
    {
        if(stk[i]==x)
            return steps;
        steps++;
    }
    return -1;
}

int main()
{
    int x;
    cout<<"Enter 5 integers:\n";
    for(int i=0;i<5;i++)
    {
        cin>>x;
        push(x);
    }

    cout<<"Enter 6th integer: ";
    cin>>x;
    push(x);

    cout<<"\nEnter value to search (present): ";
    cin>>x;
    cout<<"Search result: "<<search(x)<<"\n";

    cout<<"Enter value to search (absent): ";
    cin>>x;
    cout<<"Search result: "<<search(x)<<"\n";

    cout<<"\nPopping all elements:\n";
    for(int i=0;i<5;i++)
    {
        pop();
    }

    pop();

    return 0;
}