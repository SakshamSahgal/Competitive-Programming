#include<iostream>
#include <cstdlib>   // rand and srand
#include <ctime>     // For the time function
using namespace std;
struct Node
{
    int info;
    Node *pre;
    Node *next;
};

int generate_random_btw(int a, int b)
{
    return (a + rand()%(b-a+1));
}

class Linked_list
{
public:
    Node *start = NULL, *last = NULL, *temp;

    void insert_node(int val)
    {
        temp = new Node;
        temp->info = val;
        temp->pre = NULL;
        temp->next = NULL;

        if(start == NULL)
        {
            start = temp;
            last = temp;
            temp->next = start;
            temp->pre = start;
        }
        else
        {
            last->next = temp;
            temp->pre = last;
            temp->next = start;
            start->pre = temp;
            last = temp;
        }
    }

    void printer()
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
            while(temp != start);
        }
        else
            cout<<"EMPTY\n";

        cout<<"\nstart = "<<start->info<<" last = "<<last->info;
        cout<<"\n--------------------------\n";
    }

    void create_random_linked_list()
    {
        int inst = 1;
        while(inst)
        {
            insert_node(generate_random_btw(10,50));
            inst = generate_random_btw(0,7);
        }
    }


};


int main()
{
    Linked_list l1;
    l1.create_random_linked_list();
    l1.printer();

    return 0;
}
