#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
    Node(int v) : data(v), left(nullptr), right(nullptr) {}
};

void preorder(Node* n)
{
    if(n==nullptr) return;
    cout<<n->data<<" ";
    preorder(n->left);
    preorder(n->right);
}

void inorder(Node* n)
{
    if(n==nullptr) return;
    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
}

void postorder(Node* n)
{
    if(n==nullptr) return;
    postorder(n->left);
    postorder(n->right);
    cout<<n->data<<" ";
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
    Node* root=new Node(10);
    root->left=new Node(5);
    root->right=new Node(15);

    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;

    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;

    cout<<"Postorder: ";
    postorder(root);
    cout<<endl;

    freeTree(root);
    return 0;
}