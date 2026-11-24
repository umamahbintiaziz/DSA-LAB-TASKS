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

Node* findMin(Node* root)
{
    while(root!=nullptr && root->left!=nullptr)
        root=root->left;

    return root;
}

Node* deleteNode(Node* root,int key)
{
    if(root==nullptr)
        return nullptr;

    if(key<root->data)
        root->left=deleteNode(root->left,key);

    else if(key>root->data)
        root->right=deleteNode(root->right,key);

    else
    {
        if(root->left==nullptr)
        {
            Node* temp=root->right;
            delete root;
            return temp;
        }

        if(root->right==nullptr)
        {
            Node* temp=root->left;
            delete root;
            return temp;
        }

        Node* succ=findMin(root->right);
        root->data=succ->data;
        root->right=deleteNode(root->right,succ->data);
    }

    return root;
}

void inorder(Node* n)
{
    if(n==nullptr) return;

    inorder(n->left);
    cout<<n->data<<" ";
    inorder(n->right);
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

    cout<<"Original BST: ";
    inorder(root);
    cout<<endl;

    root=deleteNode(root,15);
    cout<<"After deleting 15: ";
    inorder(root);
    cout<<endl;

    root=deleteNode(root,45);
    cout<<"After deleting 45: ";
    inorder(root);
    cout<<endl;

    freeTree(root);
    return 0;
}