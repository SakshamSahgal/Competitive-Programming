#include<iostream>
using namespace std;


struct Node
{
    int r;
    int c;
    Node *link;
};

class Stack_Using_Linked_List
{
public:
    Node *top = NULL, *temp = NULL;
    void push(int x,int y)
    {
        temp = NULL;
        temp = new Node;
        temp->r = x;
        temp->c = y;
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
        cout<<"\n";
        Node *tt = top;

        while(tt != NULL)
        {
            cout<<"("<<tt->r<<" "<<tt->c<<")->";
            tt = tt->link;
        }
        cout<<"\n";
    }

    Node* Top()
    {
        return top;
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
        int tempr = x.Top()->r;
        int tempc = x.Top()->c;
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
        int r = temp->r;
        int c = temp->c;
        x.pop();
        Empty(x);
        //cout<<"("<<r<<" "<<c<<")\n";
        Reverse(x,r,c);
    }
}


int main()
{
    Stack_Using_Linked_List x;
    int n,m;
    cin>>n>>m;
    char grid[n][m];

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            cin>>grid[i][j];
    }

    int i=0;
    int j=0;
    x.push(0,0);
    while(1)
    {
        if(i == n-1 && j == m-1)
        {
            cout<<"Path Followed = :\n";
            Empty(x);
            x.Printer();
            break;
        }
        else if( j+1 < m && grid[i][j+1] == '1')
        {
            //right
            x.push(i,j+1);
            j++;
        }
        else if( i+1 < n && grid[i+1][j] == '1')
        {
            //down
            x.push(i+1,j);
            i++;
        }
        else
        {
            grid[i][j] = 0;
            if(x.Top()->r == 0 && x.Top()->c == 0)
            {
                cout<<"No way out\n";
                break;
            }
            else
            {
                x.pop();
                i = x.Top()->r;
                j = x.Top()->c;
            }
        }
    }

    return 0;
}
