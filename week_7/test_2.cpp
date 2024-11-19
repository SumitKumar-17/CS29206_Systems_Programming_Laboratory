#include<iostream>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}node;

node * insert(node *root, int data){
    if(root == NULL){
        node *temp = new node();
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if(data <= root->data){
        root->left = insert(root->left, data);
    }else{
        root->right = insert(root->right, data);
    }
    return root;
}

void print(node *n){
    if(n==NULL) return;

    print(n->left);
    cout<<n->data<<" ";
    print(n->right);
}

int main(){
    // given order using the insert function: 6, 9, 3, 2, 10, 7, 5, 8, 4.
    //inset in a bst
    struct node *T = NULL;
    T = insert(T, 6);
    T = insert(T, 9);
    T = insert(T, 3);
    T = insert(T, 2);
    T = insert(T, 10);
    T = insert(T, 7);
    T = insert(T, 5);
    T = insert(T, 8);
    T = insert(T, 4);
    
    cout<<"size_of(T): "<<sizeof(T)<<endl;

    print(T);

    // T=NULL;

    // delete(T);
    //writing T=NULL; will not free the memory allocated to T.
    // we need to make a loop and then free the whole of the variable poiter allocated to T.

    // T -> left = T -> right = NULL;
    delete(T->left);
    delete(T->right);
    delete(T);



    return 0;

}