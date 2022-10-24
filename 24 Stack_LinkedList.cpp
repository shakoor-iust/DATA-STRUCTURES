#include<iostream>
using namespace std;
void push();
void pop();
void view();

struct node 
{
    int data;
    struct node *next;
};
struct node *top;

int main() 
{
    int choice;
    while(1) 
    {
        cout<<"1 for push, 2 for pop, 3 for view, 4 for exit ";
        cin>>choice;
        if (choice == 1)
        {
            push();
        }
        else if (choice == 2)
        {
            pop();
        }
        else if (choice == 3)
        {
            view();
        }
        else if (choice == 4)
        {
           break;
        }
    }
}

void push()
{
    int n;
    struct node *temp;
    temp = (struct node*)new(struct node);
    cout<<"Enter data to be pushed ";
    cin>>temp->data;
    temp->next=NULL;
    if (top == NULL) 
    {
       top=temp;
    }
    else 
    {
        temp->next=top;
        top=temp;
    }

}
void pop()
{
    struct node* temp;
    temp=top;
    top=top->next;
    free(temp);
}
void view() 
{ 
    struct node *trav;
    trav=top;
    while(trav != NULL)
        cout<<trav->data<<" ";
        trav=trav->next;
    
}
