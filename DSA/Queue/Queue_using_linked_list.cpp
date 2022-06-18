#include<iostream>
using namespace std;


class Queue_using_Linked_list
{
    struct Node
    {
        int info;
        Node *link;
    };
    Node *Front = NULL, *Rear = NULL, *temp = NULL;

public:

    void enQueue(int x)
    {
        temp = NULL;
        temp = new Node;
        temp->info = x;
        temp->link = NULL;

        if(temp == NULL)
            cout<<"Overflow\n";
        else
        {
            if(Front == NULL && Rear == NULL)
            {
                Front = temp;
                Rear = temp;
            }
            else
            {
                Rear->link = temp;
                Rear = temp;
            }
        }
    }

    void Dequeue()
    {
        if(Front == NULL)
            cout<<"UnderFlow\n";
        else if(Front == Rear)
            Front = Rear = NULL;
        else
        {
            temp = Front;
            Front = Front->link;
            delete(temp);
        }

    }

    void Printer()
    {
        cout<<"\n---------------------\n";
        temp = Front;
        while(temp != NULL)
        {
            cout<<temp->info<<" ";
            temp = temp->link;
        }
        cout<<"\n---------------------\n";
    }

    int Qfront()
    {
        if(Front != NULL)
            return (Front->info);
        else
            return -1;
    }

    int Qrear()
    {
        if(Rear != NULL)
            return (Rear->info);
        else
            return -1;
    }
};


int main()
{
    Queue_using_Linked_list q;
    q.enQueue(10);
    q.enQueue(20);
    q.enQueue(30);
    q.enQueue(40);
    q.Printer();
    cout<<"Front = "<<q.Qfront()<<" Rear = "<<q.Qrear()<<"\n";
    q.Dequeue();
    q.Dequeue();
    cout<<"Front = "<<q.Qfront()<<" Rear = "<<q.Qrear()<<"\n";
    q.Printer();
    q.Dequeue();
    q.Dequeue();
    q.Printer();
    cout<<"Front = "<<q.Qfront()<<" Rear = "<<q.Qrear()<<"\n";
    q.Dequeue();

    return 0;
}
