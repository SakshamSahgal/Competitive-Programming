#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

struct Node
{
    int val;
    Node *prev;
    Node *next;
};

Node *Head = NULL;
Node *Tail = NULL;
int size=0;

void push(int val)
{
    size++;
    Node x;
    x.val=val;
    x.prev=NULL;
    x.next=NULL;
    if(Head == NULL)
    {
        Head = &x;
        Tail = &x;
    }
    else
    {
        Tail->next = &x;
        x.prev = Tail;
        Tail = &x;
    }
}

void erase(Node *tmp)
{
    size--;
    if(tmp->prev == NULL)
        Head = tmp->next;
    else if(tmp->next == NULL)
        Tail = tmp->prev;
    else
    {
        tmp->prev->next=tmp->next;
        tmp->next->prev=tmp->prev;
    }
    delete(tmp);
}

void print()
{
    Node *tmp = Head;
    if(tmp != NULL)
    {
        cout<<tmp->val<<" ";
        tmp = tmp->next;
    }
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    push(2);
    push(3);
    print();
    return 0;
}
