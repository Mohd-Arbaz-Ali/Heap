#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;

        Node(int x){
            data=x;
            left=right=NULL;
        }
};

void inorder(Node* root,vector<int>&v){
    if(root){
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
}

void preorder(Node* root,vector<int>v,int &i){
    if(root){
         root->data=v[i++];
         preorder(root->left,v,i);
         preorder(root->right,v,i);
    }
}

void bstToMinHeap(Node* root){
    vector<int>v;
    int i=0;
    inorder(root,v);
    preorder(root,v,i);
}

void printInorder(Node* root){
    if(root){
        printInorder(root->left);
        cout<<root->data<<" ";
        printInorder(root->right);
    }
}

void levelOrder(Node* root,vector<int> &v){
    if(!root)
        return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* t=q.front();
        q.pop();
        v.push_back(t->data);
        if(t->left){
            q.push(t->left);
        }
        if(t->right)
            q.push(t->right);
    }
}

int main(){
    Node* root=new Node(4);
    root->left=new Node(2);
    root->right=new Node(6);
    root->left->left=new Node(1);
    root->left->right=new Node(3);
    root->right->right=new Node(7);
    root->right->left=new Node(5);
    printInorder(root);
    cout<<endl;
    bstToMinHeap(root);
    printInorder(root);
    cout<<endl;
    vector<int> v;
    levelOrder(root,v);
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}