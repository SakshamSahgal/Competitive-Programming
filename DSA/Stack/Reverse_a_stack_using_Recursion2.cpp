#include<iostream>
#include <cstdlib> // rand and srand
#include <ctime> // For the time function
using namespace std;

struct Node
{
    int info;
    Node *link;
};

class Stack_Using_Linked_List
{
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

void Reverse_stack(Stack_Using_Linked_List &x,int val)
{
    if(x.top == NULL)
    x.push(val);
    else
    {
        int temp = x.Top();
        x.pop();
        Reverse_stack(x,val);
        x.push(temp);
    }
    return;
}

void Empty(Stack_Using_Linked_List &x)
{

    if(x.top == NULL)
        return;
    else
    {
        int this_ele = x.Top();
        x.pop();
        Empty(x);
        Reverse_stack(x,this_ele);
    }
}

int generate_random_btw(int a, int b)
{
    return (a + rand()%(b-a+1));
}

void Random_Insert(Stack_Using_Linked_List &a)
{
    cout<<"Randomly Generated Stack = : \n";
    int n = generate_random_btw(3,10);
    cout<<"Size = "<<n<<"\n";
    for(int i=0; i<n; i++)
        a.push(generate_random_btw(10,50));
}


int main()
{
    int seed = time(0);
    srand(seed);
    Stack_Using_Linked_List x;
    Random_Insert(x);
    cout<<"Original Stack : \n";
    x.Printer();
    cout<<"stack after reversing : \n";
    Empty(x);
    x.Printer();
    return 0;
}
