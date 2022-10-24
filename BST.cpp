#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};
struct node *root=NULL,*trav,*temp;

void create() 
{
    int n;
    cout<<"Enter no. of nodes to insert: ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
    temp = (struct node*)new(struct node);
    cout<<"Enter data: ";
    cin>>temp->data;
    temp->left=NULL;
    temp->right=NULL;
    if(root==NULL){
       root=temp;
    }
    else{
        trav = root;
        while(1){
           if(temp->data < trav->data)
           {
              if(trav->left==NULL)
              {
                trav->left=temp;
                break;
              }
              else
              {
                trav=trav->left;
              }
           }
           else if(temp->data > trav->data)
           {
              if(trav->left==NULL)
              {
                trav->right=temp;
                break;
              }
              else
              {
                trav=trav->right;
              }
           }
           else
           {
            cout<<"Dublicate elements not allowed";
           }
        }
       
    }
    }
}

void pre_order(struct node* root)
{
   if(root!=NULL)
   {
    cout<<root->data;
    pre_order(root->left);
    pre_order(root->right);
   }
}

void in_order(struct node* root)
{
   if(root!=NULL)
   {
    in_order(root->left);
    cout<<root->data;
    in_order(root->right);
   }
}

void post_order(struct node* root)
{
   if(root!=NULL)
   {
    post_order(root->left);
    post_order(root->right);
    cout<<root->data;
   }
}

void search(int item)
{
    trav=root;
    int flag=0;
    while(trav!=NULL)
    {
        if(trav->data==item)
        {
            cout<<"Item found"<<endl;
            flag=1;
            break;
        }
        else
        {}
            if(item < trav->data)
            {
                trav = trav->left;
            }
            else if(item > trav->data)
            {
                trav = trav->right;
            }
    }

    if(flag==0)
    {
        cout<<"Item not found"<<endl;
    }
}

void max()
{
    trav = root;
    while(trav->right!=NULL)
    {
        trav=trav->right;
    }
    cout<<trav->data<<endl;
}

void min()
{
    trav = root;
    while(trav->left!=NULL)
    {
        trav=trav->left;
    }
    cout<<trav->data<<endl;
}

int main()
{
    int choice;
    while(1)
    {
        cout<<"1 for create, 2 for display, 3 for search, 4 for max-value, 5 for min_value"<<endl;
        cin>>choice;
        if (choice == 1)
        {
            create();
        }
        else if (choice == 2)
        {
            cout<<"pre_order:"<<endl;;
            pre_order(root);
            cout<<endl;

            cout<<"in_order:"<<endl;;
            in_order(root);
            cout<<endl;
            
            cout<<"post_order:"<<endl;
            post_order(root);
            cout<<endl;

        }
        else if (choice == 3)
        {
            int item;
            cout<<"enter item to be searched: ";
            cin>>item;
            search(item);
        }    
        else if (choice == 4)
        {
            max();
        }    
        else if (choice == 5)
        {
            min();
        }     
        else
        {
            break;
        }    
    }
    

    

    

    

}

