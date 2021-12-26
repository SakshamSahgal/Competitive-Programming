#include<iostream>
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

int main()
{
    Doubly_link_list d;
    d.insert_node(5);
    d.insert_node(4);
    d.insert_node(3);
    d.insert_node(2);
    d.insert_node(1);
    d.Printer();
    d.Deletion(3);
    d.Printer();
    return 0;
}
