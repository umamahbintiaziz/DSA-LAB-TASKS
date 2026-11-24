#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;

    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

Node* insert(Node* root,int value)
{
    if(root==nullptr)
        return new Node(value);

    if(value<root->data)
        root->left=insert(root->left,value);

    else if(value>root->data)
        root->right=insert(root->right,value);

    return root;
}

void inorder(Node* n)
{
    if(n==nullptr) return;

    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
}

void preorder(Node* n)
{
    if(n==nullptr) return;

    cout<<n->data<<" ";
    preorder(n->left);
    preorder(n->right);
}

void freeTree(Node* n)
{
    if(n==nullptr) return;

    freeTree(n->left);
    freeTree(n->right);
    delete n;
}

int main()
{
    Node* root=nullptr;

    int values[]={45,15,79,90,10,55,12,20,50};

    for(int v:values)
    {
        root=insert(root,v);
    }

    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;

    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;

    freeTree(root);
    return 0;
}