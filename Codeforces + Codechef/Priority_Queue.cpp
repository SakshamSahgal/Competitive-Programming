#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;


void Display_priority_queue_max(priority_queue<lli,vector<lli>> p)
{
    while(!p.empty())
    {
        cout<<p.top()<<"\n";
        p.pop();
    }
}
void Display_priority_queue_min(priority_queue<lli,vector<lli>,greater<lli>> p)
{
    while(!p.empty())
    {
        cout<<p.top()<<"\n";
        p.pop();
    }
}


int main()
{
    //GO_FAST
    priority_queue<lli,vector<lli>> max_heap; //priority queue is a container adaptor so it takes a container (vector)
    max_heap.push(1);                         // by default it is a max heap
    max_heap.push(2);
    max_heap.push(3);
    max_heap.push(4);

    priority_queue<lli,vector<lli>,greater<lli>> min_heap;

    min_heap.push(4);
    min_heap.push(3);
    min_heap.push(2);
    min_heap.push(1);

    cout<<"Max heap -> \n";
    Display_priority_queue_max(max_heap);
    cout<<"Min Heap -> \n";
    Display_priority_queue_min(min_heap);

    return 0;
}

