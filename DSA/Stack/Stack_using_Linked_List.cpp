#include<iostream>
#include <cstdlib> // rand and srand
#include <ctime> // For the time function
using namespace std;


int generate_random_btw(int a, int b)
{
    return (a + rand()%(b-a+1));
}

class Stack_Using_Linked_List
{
    struct Node
    {
        int info;
        Node *link;
    };

public:
    Node *top = NULL, *temp = NULL;
    void push(int val)
    {
        temp = NULL;
        temp = new Node;
        temp->info = val;
        temp->link = NULL;

        if(temp == NULL)
            cout<<"Overflow\n";
        else
        {
            if(top == NULL)
                top = temp;
            else
            {
                temp->link = top;
                top = temp;
            }
        }
    }

    int pop()
    {
        if(top == NULL)
            cout<<"Underflow\n";
        else
        {
            int val = top->info;
            temp = top;
            top = top->link;
            delete(temp);
            return val;
        }
    }

    void Printer()
    {
        Node *tt = top;

        while(tt != NULL)
        {
            cout<<tt->info<<"\n";
            tt = tt->link;
        }
    }

    int Top()
    {
        return top->info;
    }
};



int main()
{
    int seed = time(0);
    srand(seed);
    Stack_Using_Linked_List s;
    Random_Insert(s);
    s.Printer();
    return 0;
}
