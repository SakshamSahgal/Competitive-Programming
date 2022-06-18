#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

struct Node
{
    int info;
    Node *next;
};

class Queue_Using_Linked_List
{
public:
    Node *temp=NULL,*Front = NULL,*Rear = NULL;

    void Enqueue(int k)
    {
        temp = NULL;
        temp = new Node;
        temp->info = k;
        temp->next = NULL;

        if(temp == NULL)
            cout<<"OverFlow\n";
        else
        {
            if(Front == NULL && Rear == NULL)
            {
                Front = Rear = temp;
            }
            else
            {
                Rear->next = temp;
                Rear = temp;
            }

            Rear->next = Front;
        }
    }

    void Dequeue()
    {
        if(Front == NULL) //empty element
            cout<<"UnderFlow\n";
        else if(Front == Rear) //last element
        {
            temp = Front;
            delete(temp);
            Front = NULL;
            Rear = NULL;
        }
        else
        {
            temp = Front;
            Front = Front->next;
            delete(temp);
            Rear->next = Front;
        }
    }

    void Display()
    {
        cout<<"\n------------------\n";
        temp = Front;
        while(temp->next != Front)
        {
            cout<<temp->info<<" ";
            temp = temp->next;
        }
        cout<<Rear->info<<"\n";
        cout<<"\n------------------\n";
    }
};

int main()
{
    Queue_Using_Linked_List q;
    q.Enqueue(12);
    q.Enqueue(13);
    q.Enqueue(14);
    q.Enqueue(15);
    q.Enqueue(16);
    q.Display();
    q.Dequeue();
    q.Display();
    q.Dequeue();
    q.Display();
    return 0;
}
