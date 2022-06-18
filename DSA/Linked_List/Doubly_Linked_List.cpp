#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


struct Node
{
    int info;
    Node *next;
    Node *prev;
};



class Doubly_link_list
{
    Node *start = NULL, *last = NULL, *temp;
public:
    void insert_node(int val)
    {
        temp = new Node;
        temp->info = val;
        temp->prev = NULL;
        temp->next = NULL;

        if(start == NULL)
        {
            start = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            temp->prev = last;
            last = temp;
        }
    }

    void Printer()
    {
        cout<<"\n--------------------------\n";
        if(start != NULL)
        {
            temp = start;
            do
            {
                cout<<temp->info<<" ";
                temp = temp->next;
            }
            while(temp != NULL);
        }
        else
            cout<<"EMPTY\n";
        cout<<"\n--------------------------\n";
    }

    void Deletion(int val)
    {
        if(start->info == val)
            start = start->next;
        else if(last->info == val)
            last = last->prev;
        else
        {
            if(start != NULL)
            {
                temp = start;
                do
                {
                    //cout<<temp->info<<" ";
                    if(val == temp->info)
                    {
                        temp->next->prev = temp->prev;
                        temp->prev->next = temp->next;

                    }
                    temp = temp->next;
                }
                while(temp != NULL);
            }

        }
    }

};


void Convert_it(Doubly_link_list &d)
{

   vector<pair<int,int>> v;

   v.push_back({5,1233});
   v.push_back({1,123});
   v.push_back({2,12});
   v.push_back({3,1323});
   v.push_back({4,133});


    sort(v.begin(),v.end());

    for(int i=0;i<5;i++)
        cout<<v[i].first<<" ";

    cout<<"\n";

    for(int i=0;i<5;i++)
        d.insert_node(v[i].second);

    d.Printer();
}

int main()
{
    Doubly_link_list d;
    Convert_it(d);
    return 0;
}
