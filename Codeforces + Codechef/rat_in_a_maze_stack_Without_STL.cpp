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
        Node *tt = top;

        while(tt != NULL)
        {
            cout<<"("<<tt->x<<" "<<tt->y<<")\n";
            tt = tt->link;
        }
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
    int n,m;
    cin>>n>>m;

    char grid[n][m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>grid[i][j];

    int i=0;
    int j=0;
    Stack_Using_Linked_List path;

    path.push(0,0);
    while(1)
    {
        if( i == n-1 && j == m-1 )
        {
            Empty(path);
            path.Printer();
            break;
        }
        else if( j+1 < m && grid[i][j+1] == '1')
        {
            path.push(i,j+1);
            j++;
        }
        else if( i+1 < n && grid[i+1][j] == '1')
        {
            path.push(i+1,j);
            i++;
        }
        else
        {
            path.pop();
            grid[i][j] = '0';
            if(path.is_Empty() == 1)
            {
                cout<<"No way out\n";
                break;
            }
            else
            {
                i = path.Top()->x;
                j = path.Top()->y;
            }
        }
    }
    return 0;
}
