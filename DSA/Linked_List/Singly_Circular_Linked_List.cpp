#include<iostream>
#include <cstdlib>   // rand and srand
#include <ctime>     // For the time function

using namespace std;

struct Node
{
    int info;
    Node *link;
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
        temp->link = NULL;

        if(start == NULL)
        {
            start = temp;
            last = temp;
            start->link = start;
        }
        else
        {
            last->link = temp;
            temp->link = start;
            last = temp;
        }
    }

    void delete_node()
    {
        if(start != NULL) //if not empty
        {
            if(start->link == start) //only one node
            {
                delete(temp);
                start = NULL;
                last = NULL;
            }
            else if(temp == start)
            {
                start = start->link;
                last->link = start;
                delete(temp);
            }
            else if(temp == last)
            {
                Node *pre = last;
                Node *current = start;

                while(current != temp)
                {
                    pre = current;
                    current = current->link;
                }

                pre->link = start;
                last = pre;
                delete(temp);
            }
            else
            {
                Node *pre = last;
                Node *current = start;

                while(current != temp)
                {
                    pre = current;
                    current = current->link;
                }

                pre->link = temp->link;
                delete(temp);
            }
        }
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

    void Printer()
    {
        cout<<"\n-------------------\n";
        if(start == NULL)
        {
            cout<<"Empty\n";
        }
        else
        {
            temp = start;
            do
            {
                cout<<temp->info<<" ";
                temp = temp->link;
            }
            while(temp != start);
            cout<<"\nstart = "<<start->info<<" last = "<<last->info<<"\n";
        }
        cout<<"\n-------------------\n";
    }


    void take_input()
    {
        int n;
        cout<<"enter Size : ";
        cin>>n;

        for(int i=0; i<n; i++)
        {
            int x;
            cin>>x;
            insert_node(x);
        }
    }

};

int main()
{
    int seed = time(0);
    srand(seed);
    Linked_list l1;
    l1.create_random_linked_list();
    l1.Printer();
    cout<<"After deleting first element : \n";
    l1.temp = l1.last;
    l1.delete_node();
    l1.Printer();
    cout<<"After deleting last element : \n";
    l1.temp = l1.start;
    l1.delete_node();
    l1.Printer();
    Linked_list l2;
    l2.take_input();
    l2.Printer();
    return 0;
}

