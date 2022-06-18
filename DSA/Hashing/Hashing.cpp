#include<iostream>
using namespace std;

struct Node
{
    int info;
    bool status;

    Node()
    {
        status=0;
    }
};

class Hashing_using_open_addressing
{
public:
    int sz;
    Node *Hashtable;

    Hashing_using_open_addressing(int sizze)
    {
        sz = sizze;
        Hashtable = new Node[sizze];
    }

    int hash_func(int k)
    {
        return (k%9);
    }

    void Insert_using_Linear_Probing(int k)
    {
        if( Hashtable[hash_func(k)].status == 0 )
        {
            Hashtable[hash_func(k)].info = k;
            Hashtable[hash_func(k)].status = 1;
        }
        else
        {
            int i=1;

            while( Hashtable[ (hash_func(k) + i)%sz ].status == 1)
                i++;

            Hashtable[ (hash_func(k) + i)%sz ].info = k;
            Hashtable[ (hash_func(k) + i)%sz ].status = 1;
        }
    }

    bool Searching_using_Linear_Probing(int k)
    {
        if( Hashtable[hash_func(k)].info == k )
            return 1;
        else
        {
            int i=1;
            int st = hash_func(k);
            while( (hash_func(k) + i)%sz != st )
            {
                if(Hashtable[(hash_func(k) + i)%sz ].status == 0)
                    return 0;
                else if(Hashtable[(hash_func(k) + i)%sz ].info == k)
                    return 1;
                i++;
            }
            return 0;
        }

    }

    void print_ht()
    {
        cout<<"\n------------------------------\n";
        for(int i=0; i<sz; i++)
        {
            if( Hashtable[i].status == 0)
                cout<<"NULL"<<" "<<Hashtable[i].status<<"\n";
            else
                cout<<Hashtable[i].info<<" "<<Hashtable[i].status<<"\n";
        }

        cout<<"\n------------------------------\n";
    }
};


int main()
{
    int n,k;
    cout<<"Enter no of Elements : ";
    cin>>n;
    Hashing_using_open_addressing h(10);
    h.print_ht();
    for(int i=0; i<n; i++)
    {
        cin>>k;
        h.Insert_using_Linear_Probing(k);
    }
    cout<<"Enter element to search : ";
    cin>>k;
    cout<<"Found : "<<h.Searching_using_Linear_Probing(k)<<"\n";
    h.print_ht();
    return 0;
}
