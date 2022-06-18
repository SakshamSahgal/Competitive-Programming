#include<iostream>
using namespace std;


class Dequeue_using_Array
{
public:
    int sz;
    int *a;
    int Front=-1,Rear = -1;

    Dequeue_using_Array(int sizze)
    {
        sz = sizze;
        a = new int [sz];
    }

    void Push_front(int k)
    {
        if(Front == -1 && Rear == -1)
        {
            Front = Rear = 0;
            a[Front] = k;
        }
        else
        {
            if(Front == 0)
                cout<<"Front Overflow\n";
            else
                a[--Front] = k;
        }
    }

    void Push_Rear(int k)
    {
        if(Front == -1 && Rear == -1)
        {
            Front = Rear = 0;
            a[Front] = k;
        }
        else
        {
            if( Rear == sz-1 )
                cout<<"Rear Overflow\n";
            else
                a[++Rear] = k;
        }
    }

    void Pop_Front()
    {
        if(Front == -1 && Rear == -1)
            cout<<"Underflow\n";
        else if(Front == Rear)
            Front = Rear = -1;
        else
            Front++;
    }

    void Pop_Rear()
    {
        if(Front == -1 && Rear == -1)
            cout<<"Underflow\n";
        else if(Front == Rear)
            Front = Rear = -1;
        else
            Rear--;
    }

    void Display()
    {
        if(Front == -1 && Rear == -1)
            cout<<"Empty\n";
        else
        {
            cout<<"\n----------------\n";
            for(int i=Front; i<=Rear; i++)
                cout<<a[i]<<" ";
            cout<<"\n----------------\n";
        }
    }
};

int main()
{
    Dequeue_using_Array de(10);
    de.Push_front(10);
    de.Display();
    de.Push_Rear(20);
    de.Push_Rear(30);
    de.Display();
    de.Pop_Front();
    de.Display();
    de.Pop_Rear();
    de.Display();
    de.Pop_Front();
    de.Display();
    de.Pop_Rear();
    return 0;
}
