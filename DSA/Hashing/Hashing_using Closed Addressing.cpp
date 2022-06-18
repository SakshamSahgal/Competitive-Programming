#include<iostream>
using namespace std;

struct Node
{
int value;
Node *Link;
};

class Hashing_using_closed_Addressing
{
    public:
    int sz;
    Node **hash_Table;
    public:
    int hash_function(int k)
    {
        return ( ( 2*k + 3 ) % 10 );
    }

    Hashing_using_closed_Addressing(int sizze)
    {
        sz = sizze;
        hash_Table = new Node *[sz];
        for(int i=0;i<sz;i++)
            hash_Table[i] = NULL;
    }

    void insert_ele(int k)
    {
        Node *temp = new Node;
        temp->value = k;
        temp->Link = NULL;

        if( hash_Table[ hash_function(k) ] == NULL )
        {
            hash_Table[hash_function(k)] = temp;
        }
        else
        {
              temp->Link = hash_Table[hash_function(k)];
              hash_Table[hash_function(k)] = temp;
        }
    }

    void Print_table()
    {
        for(int i=0;i<sz;i++)
        {
            cout<<"Index = "<<i<<" -> ";
             Node *temp;
             temp = hash_Table[i];
             while(temp != NULL)
             {
                 cout<<temp->value<<" ";
                 temp = temp->Link;
             }
             cout<<"\n";
        }
    }

    bool Searching(int k)
    {
        Node *temp = hash_Table[hash_function(k)];
        while(temp != NULL)
        {
            if(temp->value == k)
                return 1;
            temp = temp->Link;
        }
        return 0;
    }
};

int main()
{
    Hashing_using_closed_Addressing h(10);
    h.insert_ele(3);
    h.insert_ele(2);
    h.insert_ele(9);
    h.insert_ele(6);
    h.insert_ele(11);
    h.insert_ele(13);
    h.insert_ele(7);
    h.insert_ele(12);
    h.Print_table();

    cout<<"Found element : "<<h.Searching(12)<<"\n";
    cout<<"Found element : "<<h.Searching(7)<<"\n";
    cout<<"Found element : "<<h.Searching(69)<<"\n";

    return 0;
}
