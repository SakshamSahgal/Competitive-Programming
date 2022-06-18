#include<iostream>
using namespace std;


class Circular_Queue_Using_Array
{
    public:
    int sz;
    int *a;
    int Front=-1,Rear = -1;
    Circular_Queue_Using_Array(int sizee)
    {
        sz = sizee;
        a = new int [sz];
    }

    void Enqueue(int k)
    {
        if(Front == -1 && Rear == -1) //empty
        {
            Front = Rear = 0;
            a[Rear] = k;
        }
        else if( (Rear+1)%sz == Front ) //full
            cout<<"OverFlow\n";
        else
        {
            Rear = (Rear+1)%sz;
            a[Rear] = k;
        }
    }

    void Deqeue()
    {
        if( Front == -1 && Rear == -1 ) //empty
            cout<<"underflow\n";
        else if(Front == Rear)
            Front = Rear = -1;
        else
            Front = (Front+1)%sz;
    }

    void Printer()
    {
        cout<<"\n------------------\n";
        if(Rear != -1)
        {
            if(Rear >= Front)
            {
                for(int i=Front;i<=Rear;i++)
                    cout<<a[i]<<" ";
            }
            else
            {
                for(int i=Front;i<sz;i++)
                    cout<<a[i]<<" ";
                for(int i=0;i<=Rear;i++)
                    cout<<a[i]<<" ";
            }
        }
        cout<<"\n------------------\n";
    }

};

int main()
{
    Circular_Queue_Using_Array q(10);
    q.Enqueue(12);
    q.Enqueue(13);
    q.Enqueue(14);
    q.Enqueue(15);
    q.Enqueue(16);
    q.Printer();
    q.Deqeue();
    q.Deqeue();
    q.Printer();
    q.Deqeue();
    q.Deqeue();
    q.Printer();
    q.Deqeue();
    return 0;
}
