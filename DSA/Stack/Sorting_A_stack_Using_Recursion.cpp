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
        cout<<"\n-----------------\n";
        Node *tt = top;

        while(tt != NULL)
        {
            cout<<tt->info<<"\n";
            tt = tt->link;
        }
        cout<<"\n-----------------\n";
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

void Sort_it(Stack_Using_Linked_List &x,int val)
{

    if(x.Top() == NULL)
    {
        x.push(val);
        return;
    }
    else
    {
        if(x.Top()->info > val)
        {
            int temp = x.Top()->info;
            x.pop();
            Sort_it(x,val);
            x.push(temp);
        }
        else
            x.push(val);
        return;
    }
}

void Empty(Stack_Using_Linked_List &x)
{
    if(x.Top() == NULL)
        return;
    else
    {
        int temp = x.Top()->info;
        x.pop();
        Empty(x);
        //cout<<"["<<temp<<"]\n";
        Sort_it(x,temp);
    }
}

int main()
{
    Stack_Using_Linked_List x;
    x.push(5);
    x.push(4);
    x.push(3);
    x.push(2);
    x.push(1);
    cout<<"Original Stack : \n";
    x.Printer();
    Empty(x);
    cout<<"Stack after Sorting : \n";
    x.Printer();
    return 0;
}
