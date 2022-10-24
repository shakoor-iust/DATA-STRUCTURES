#include<iostream>
using namespace std;

void create();
void view();
void insert();
void del();

struct node{
	int data;
	struct node *next;
	
	
};
struct node *head=NULL, *tail=NULL;

int main()
{
	int ch;
	while(1)
	{
		cout<<"\n1 for create, 2 for view, 3 for insert, 4 for delete, 5 for exit: "<<endl;
		cin>>ch;
		if(ch==1)
		create();
		if(ch==2)
		view();
		if(ch==3)
		insert();
		if(ch==4)
		del();
        if(ch==5)
		break;
	}
	
}
void create()
{
	int n, i;
	struct node *temp;
	cout<<"Enter number of nodes"<<endl;
	cin>>n;
	for(i=1; i<=n;i++)
	{
		temp=(struct node*)new(struct node);              
		cout<<"Enter data for node"<<i<<":"<<endl;
		cin>>temp->data;
		temp->next=NULL;
		if(head==NULL)                    
		{
			head=temp;
			tail=temp;
		}
		else
		{
			tail->next=temp;
			tail=temp;
			
		}
		
	}
	
}
void view()
{
	struct node *trav;
	trav=head;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;          
	
	}
}
void insert()
{
	struct node *trav,*temp;
	int value, choice, flag=0;
	trav=head;
	temp=(struct node*)new(struct node);	
	cout<<"Enter the data for new node:"<<endl;
	cin>>temp->data;
    temp->next=NULL;
    cout<<"Enter the node data after/before which you want to insert the node:"<<endl;
	cin>>value;
	cout<<"1 for insertion after, 2 for insertion before"<<endl;
	cin>>choice;
	if(choice==1)
	{
	    while(trav->data!=value)
		    trav=trav->next;
			
		temp->next=trav->next;
		trav->next=temp;
			
	}
	else
	{
		while(trav->next->data!=value)
		    trav=trav->next;
		temp->next=trav->next;
		trav->next=temp;
			
	}	
}
void del() 
{
    int item;
    struct node *temp, *trav;
    cout<<"Enter item to be deleted ";
    cin>>item;
    if (head->data == item) 
    {
        temp = head;
        head = head->next;
		temp->next=NULL;
        free(temp);
    }
    else 
    {
        trav = head;
        while(trav->next->data != item)
            trav = trav->next;
        temp = trav->next;
        if(trav->next == tail)
        {
            trav->next = NULL;
            free(temp);
        }
        else
        {
            trav->next = trav->next->next;
            free(temp);
        }

    }
}



