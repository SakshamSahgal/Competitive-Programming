#include<iostream>
using namespace std;

struct Node
{
    int x;
    int y;
    Node *link;
};

class Stack_Using_Linked_List
{
public:
    Node *top = NULL, *temp = NULL;
    void push(int r,int c)
    {
        temp = NULL;
        temp = new Node;
        temp->x = r;
        temp->y = c;
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

    void pop()
    {
        if(top == NULL)
            cout<<"Underflow\n";
        else
        {
            temp = top;
            top = top->link;
            delete(temp);
        }
    }

    void Printer()
    {
        cout<<"\n------------------\n";
        Node *tt = top;

        while(tt != NULL)
        {
            cout<<"("<<tt->x<<" "<<tt->y<<")\n";
            tt = tt->link;
        }
        cout<<"\n------------------\n";
    }

    Node *Top()
    {
        return top;
    }

    bool is_Empty()
    {
        if(top == NULL)
            return 1;
        else
            return 0;
    }
};


void Reverse(Stack_Using_Linked_List &x,int rt,int ct)
{
    if(x.Top() == NULL)
     {
         x.push(rt,ct);
         return;
     }
    else
    {
        int tempr = x.Top()->x;
        int tempc = x.Top()->y;
        x.pop();
        Reverse(x,rt,ct);
        x.push(tempr,tempc);
        return;
    }
}

void Empty(Stack_Using_Linked_List &x)
{
    if(x.top == NULL)
        return;
    else
    {
        Node *temp = x.Top();
        int r = temp->x;
        int c = temp->y;
        x.pop();
        Empty(x);
        //cout<<"("<<r<<" "<<c<<")\n";
        Reverse(x,r,c);
    }
}

int main()
{
    Stack_Using_Linked_List x;
    x.push(1,0);
    x.push(2,0);
    x.push(3,0);
    x.push(4,0);
    x.push(5,0);
    x.Printer();
    Empty(x);
    x.Printer();
    return 0;
}

