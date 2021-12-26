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
int n;
class Node
{
public:
    int info;
    Node *link;
};
Node *start = NULL, *temp, *last = NULL;
void insert_node(lli x)
{
    temp = new Node;
    temp->info = x;
    temp->link = NULL;
    if(start == NULL)
    {
        start = temp;
        last = temp;
    }
    else
    {
        last->link = temp;
        last = temp;
    }

}

void printer()
{
    temp = start;
    while(temp != NULL)
    {
        cout<<temp->info<<" ";
        temp = temp->link;
    }
}

void insert_btw(int x,int val)
{
    Node *t1 = new Node;

    t1->info = val;
    t1->link = NULL;

    if(x == 0)
    {
        t1->link = start;
        start = t1;
    }
    else
    {
        temp = start;
        for(int i=1; i<x; i++)
        {
            temp = temp->link;
        }

        t1->link = temp->link;
        temp->link = t1;

    }

}

int main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        lli x;
        cin>>x;
        insert_node(x);
    }
    cout<<"\n";
    printer();

    insert_btw(2,35);
    cout<<"\n";
    printer();
    return 0;
}
