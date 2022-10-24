#include<iostream>
using namespace std;
int Queue[5];
int Front = 0, Rear =0;
int count=0;

void Enqueue(int item)
{
    if( ((Rear+1)%5) == Front)
        cout << "Full";
    else{
        Rear = (Rear + 1) % (5);
        Queue[Rear] = item;       // 1, 2, 3, 4
    }
}

int Dequeue()
{
    if(Front == Rear)
        cout << "Empty";
    else{
        Front = (Front + 1) % (5);
        int item = Queue[Front];
         return item;
    }
}

void View()
{
    int i=Front+1;                                  // 1
    do{
        cout<<Queue[i];                             // 1st
        i=(i+1)%5;                                  // 2

    }while(i!=(Rear+1)%5);
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
        else if(ch == 2)
        {
            item = Dequeue();
                cout << item;
        }
       else if(ch == 3)
           View();
        else if(ch == 4)
            break;
    }
    
}