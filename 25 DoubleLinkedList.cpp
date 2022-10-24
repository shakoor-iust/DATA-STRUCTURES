//Simple Doubly Linked List
#include<iostream>
using namespace std;

struct node{
   int data;
   struct node*prev;
   struct node*next;
};

int main()
{
    struct node *t;     //Creating a node t
    t=(struct node*)new(struct node);
    t->prev=NULL;
    t->data=10;
    t->next=NULL;

    cout<<"Data: "<<t->data;


}