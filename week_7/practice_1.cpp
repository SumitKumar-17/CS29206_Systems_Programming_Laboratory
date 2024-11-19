#include <iostream>
using namespace std;

typedef struct node{
    int data;
    node *next;
}node ;

node *insert(node *L,int data){

    node * list=L;
    while(L->next){
        if(L->next->data==data){
            L->next=L->next->next;
            return list;
        }
        if(L->next->data>data)break;

        L=L->next;
    }
    return list;
}

int main(){
    node *l =new node;
    l=insert(l,5);
    l=insert(l,14);
    l=insert(l,18);
    l=insert(l,4);
    l=insert(l,13);
    l=insert(l,20);
    l=insert(l,8);
    l=insert(l,9);
    l=insert(l,5);
    l=insert(l,14);
    l=insert(l,18);
    l=insert(l,13);
    l=insert(l,20);

    while(l->next){
        cout<<l->next->data<<endl;
        l=l->next;
    }
    return 0;
}