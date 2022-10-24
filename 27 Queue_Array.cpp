#include <iostream>
using namespace std;
int queue[10];
int front = -1, rear = -1;          // Front for Deletion or Dequeue &&&&&&&&&&& Rear for Insertion or Enqueue

void Enqueue(int x)
{
    if (rear == 10 - 1)                          // If Queue is already full
    {
        cout << "Queue is Full" << endl;
    }
    else                                          // Else Elements will be inserted in Queue using Rear index pointer
    {
        rear++;
        queue[rear] = x;
    }
}

int Dequeue()
{ 
    int x = -1;                             
    if (rear == front)                           // If Queue is Empty
    {
        cout << "Queue is Empty" << endl;
    }
    else                                          // Else Elements will be Dequeued or Deleted using Front index pointer
    {
        front++;
        x = queue[front];
    }
    return x;                                      // X Will be returned with either an element or as -1, in that case Queue will be empty
}

void View()
{
    int i;                                   
    if (rear == front)                              // Condition for Empty Queue
    { 
        cout << "Queue is Empty" << endl;
    }
    else                                             // Else a loop will be intialised from front = 0 upto rear
    {
        for (i = front + 1; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }
    }
}
int main()
{
    int ch, item;
    while (1)
    {
        cout << "\n1 for EnQueue\n2 for DeQueue\n3 for View\n4 for Exit\n Enter Your Choice : ";
        cin >> ch;

        if (ch == 1)
        {
            cout << "Enter the Element : ";
            cin >> item;
            Enqueue(item);
        }
        else if (ch == 2)
        {
            item = Dequeue();
            if (item == -1)
                cout << "UnderFlow" << endl;
            else
                cout << item;
        }
        else if (ch == 3)
            View();
        else if (ch == 4)
            break;
    }
}