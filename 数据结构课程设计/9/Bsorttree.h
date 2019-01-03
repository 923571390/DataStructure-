#ifndef Bsorttree_h
#define Bsorttree_h
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *left;
    Node *right;
    Node *parent;
};
class Bsorttree{
public:
    Bsorttree(){root = NULL;}
    ~Bsorttree(){};
    inline Node* getRoot() const { return this->root;}
    void create(int *dataset, int size);
    void insert(int value);
    bool insertnode(Node **root, int value);
    Node* searchnode(Node *root,int value);
    void search(int value);
    void display(Node *root);
    void print();
private:
    Node *root;
};
void Bsorttree:: create(int *dataset, int size) {
    for ( int i=0; i<size; i++ ) {
        insertnode(&root,dataset[i]);
    }
}
bool Bsorttree::insertnode(Node **root, int value) {
    Node *newnode = new Node;
    if ( newnode == NULL ) {
        return false;
    }
    newnode->data = value;
    newnode->left = newnode->right = newnode->parent = NULL;
    if( (*root) == NULL ) {
        *root = newnode;
        return true;
    }
    if ((*root)->left == NULL && (*root)->data > value ) {
        newnode->parent = (*root);
        (*root)->left = newnode;
        return true;
    }
    if((*root)->right == NULL && (*root)->data < value){
        newnode->parent = (*root);
        (*root)->right = newnode;
        return true;
    }
    if ( (*root)->data > value ) {
        insertnode( &(*root)->left,value);
    }
    else if ( (*root)->data < value ) {
        insertnode( &(*root)->right,value);
    }
    return true;
}
void Bsorttree:: insert(int value) {
    insertnode(&root,value);
}
Node* Bsorttree:: searchnode(Node *root,int value){
    if (root == NULL) {
        return NULL;
    }
    if (root ->data > value) {
        return searchnode(root->left,value);
    }
    else if (root ->data < value) {
        return searchnode(root->right,value);
    }
    else return root;
}
void Bsorttree:: search(int value){
    Node *p = this->searchnode(root,value);
    if(p==NULL) {
        cout <<value<<" not exist!" <<endl;
    }
    else {
        cout <<"search success!" <<endl;
    }
}
void Bsorttree::display(Node *root){
    if ( root == NULL ) {
        return;
    }
    display(root->left);
    cout<< root->data<<"->";
    display(root->right);
}
void Bsorttree::print(){
    Bsorttree::display(this->root);
    cout<<"end"<<endl;
}
#endif
