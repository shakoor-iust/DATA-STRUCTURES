// Doubly Linked List with Create/View/Insert/Delete FXNS
#include <iostream>
#include <stdlib.h>
using namespace std;
void create();
void view();
void insert();
void del();

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head = NULL, *tail = NULL;

int main()
{
    int choice;
    while (1)
    {
        cout << "\n1 For Create, 2 For View, 3 For Insert, 4 For Delete" << endl;
        cin >> choice;
        if (choice == 1)
            create();
        else if (choice == 2)
            view();
        else if (choice == 3)
            insert();
        else if (choice == 4)
            del();
        else
            break;
    }
}

void create()
{
    int n, i;
    cout << "Enter the no.of Nodes: " << endl;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        struct node *temp;
        temp = (struct node *)new (struct node);
        cout << "Enter the Data for Node " << i << ": " << endl;
        cin >> temp->data;
        temp->prev = NULL;
        temp->next = NULL;
        if (head == NULL)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->prev = tail;
            tail->next = temp;
            tail = temp;
        }
    }
}

void view()
{
    int ch;
    cout << "1 For Simple View, 2 For Reverse View: " << endl;
    cin >> ch;
    if (ch == 1)
    {
        struct node *trav;
        trav = head;

        while (trav != NULL)
        {
            cout << trav->data << " ";
            trav = trav->next;
        }
    }
    else if (ch == 2)
    {
        struct node *trav1;
        trav1 = tail;
        while (trav1 != NULL)
        {
            cout << trav1->data << " ";
            trav1 = trav1->prev;
        }
    }
    else
        cout << "Wrong Option " << endl;
}

void insert()
{
    int ch, data;
    struct node *temp, *trav1;
    temp = (struct node *)new (struct node);
    cout << "1 For Insertion After, 2 For Insertion Before: " << endl;
    cin >> ch;
    if (ch == 1)
    {
        trav1 = head;
        cout << "Enter the data for the node after which you want to Insert New node: " << endl;
        cin >> data;
        cout << "Enter the data for New Node: " << endl;
        cin >> temp->data;
        temp->prev = NULL;
        temp->next = NULL;
        while (trav1->data != data)
        {
            trav1 = trav1->next;
        }
        if (trav1 != tail)
        {
            trav1->next->prev = temp;
            temp->next = trav1->next;
            trav1->next = temp;
            temp->prev = trav1;
        }
        else // Node After Tail
        {
            trav1->next = temp;
            temp->prev = trav1;
            tail = temp;
        }
    }

    else if (ch == 2)
    {
        trav1 = head;
        cout << "Enter the data for the node Before which you want to Insert New node: " << endl;
        cin >> data;
        cout << "Enter the data for New Node: " << endl;
        cin >> temp->data;
        temp->prev = NULL;
        temp->next = NULL;
        while (trav1->data != data)
        {
            trav1 = trav1->next;
        }
        if (trav1 != head)
        {
            trav1->prev->next = temp;
            temp->prev = trav1->prev;
            temp->next = trav1;
            trav1->prev = temp;
        }

        else // Before Head
        {
            trav1->prev = temp;
            temp->next = trav1;
            head = temp;
        }
    }
    else
        cout << "Wrong option " << endl;
}

void del()
{
    struct node *temp, *trav;
    int item;
    cout << "Enter the Data for the Node you want to Delete: " << endl;
    cin >> item;
    if (head->data == item) // If Node to be deleted is Head
    {
        temp = head;
        head = head->next;
        temp->next=NULL;
        head->prev=NULL;
        delete (temp);
    }
    else // For Tail and Intermediate nodes
    {
        trav = head;
        while (trav->next->data != item)
        {
            trav = trav->next;
        }
        temp = trav->next; 

        if (trav->next == tail) // If Node to be deleted is Tail
        {
            trav->next = NULL;
            temp->prev=NULL;
            delete (temp);
            tail=trav;
        }
        else // For Intermediate Node
        {

            trav->next = temp->next;
            temp->next->prev=trav;
            temp->next=NULL;
            temp->prev=NULL;
            delete(temp);
        }
    }
}