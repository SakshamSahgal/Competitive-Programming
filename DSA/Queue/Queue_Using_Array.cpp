#include<iostream>
using namespace std;

class Queue_using_Array
{
public:
    int *a;
    int sz;
    int Front=-1,Rear=-1;
    Queue_using_Array(int sizze)
    {
        sz = sizze;
        a = new int[sizze];
    }

    void Enqueue(int k)
    {
        if(Rear == sz-1)  //full
            cout<<"OverFlow\n";
        else if(Rear == -1) //empty
        {
            Front = Rear = 0;
            a[Rear] = k;
        }
        else
            a[++Rear] = k;

    }

    void Dequeue()
    {
        if(Rear == -1 || Rear < Front)
            cout<<"UnderFlow\n";
        else
            Front++;
    }

    void Printer()
    {
        if(Rear != -1)
        {
            int st = Front;
            if(st == -1)
                st++;

            for(int i=st; i<=Rear; i++)
                cout<<a[i]<<" ";

            cout<<"\n";
        }

    }
};

int main()
{
    Queue_using_Array q(10);
    q.Enqueue(12);
    q.Enqueue(13);
    q.Enqueue(14);
    q.Enqueue(15);
    q.Enqueue(16);
    q.Printer();
    q.Dequeue();
    q.Printer();
    return 0;
}
