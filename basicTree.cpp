#include <iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;
    
    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildTree(node* root){
    cout<<"enter the value of the data"<<endl;
    int data;
    cin>>data;
    root=new node(data);
    
    if(data==-1){
        return NULL;
    }
    
    cout<<"enter the value of the left child "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter the value of the right child "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}

void LevelOrderTransversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            
            if(temp->right){
                q.push(temp->right);
            }
            
            if(temp->left){
                q.push(temp->left);
            }
        }
    }
}



int main() {
    node* root=NULL;
    root=buildTree(root);
    LevelOrderTransversal(root);

    return 0;
}
