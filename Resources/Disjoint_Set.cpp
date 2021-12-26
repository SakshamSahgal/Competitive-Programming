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

lli p[100000];
map<int,vector<int>> g;

int get_Parent(int x) //gets you absolute parent
{
    if(p[x] < 0) //-ve means absolute parent
        return x;
    else
    {
        int abs_parent = (get_Parent(p[x]));
        if(abs_parent != x)
            p[x] = abs_parent;
        return abs_parent;
    }

}

void array_printer(int n)
{
    cout<<"\n----------------\n";
    for(int i=1; i<=n; i++)
        cout<<p[i]<<" ";
    cout<<"\n----------------\n";
}

bool cycle_Detected(int a,int b)
{
    if(get_Parent(a) == get_Parent(b))
        return 1;
    else
        return 0;
}


void union_set(int a,int b)
{
    int pa = get_Parent(a);
    int pb = get_Parent(b);
    cout<<"abs parent of "<<a<<" is "<<pa<<" set size = "<<abs(p[pa])<<"\n";
    cout<<"abs parent of "<<b<<" is "<<pb<<" set size = "<<abs(p[pb])<<"\n";
    if(pa != pb)
    {
        if(abs(p[pa]) >= abs(p[pb])) //if set a is bigger
        {
            //adding set b to set a
            p[pa] += p[pb];
            p[pb] = pa;
            cout<<"adding set "<<b<<" to set "<<a<<" , now set size = "<<abs(p[pa])<<" with parent "<<pa<<"\n";
        }
        else
        {
            //adding set a to set b
            p[pb] += p[pa];
            p[pa] = pb;
            cout<<"adding set "<<a<<" to set "<<b<<" , now set size = "<<abs(p[pb])<<" with parent "<<pb<<"\n";
        }
    }
}

void Display()
{
    cout<<"\n----------------------\n";

    for(auto i:g)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n----------------------\n";
}


int main()
{
    //GO_FAST
    /*
    10
    1 2
    2 4
    4 5
    5 9
    9 1 //cycle detect
    9 2 //cycle
    6 7
    6 3
    7 1*/

    int n;
    cin>>n;
    memset(p, -1, sizeof(p));
    array_printer(n);
    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;
        if(cycle_Detected(x,y) == 1)
            cout<<"Cycle Detected\n";
        else
        {
            g[x].push_back(y);
            g[y].push_back(x);
            union_set(x,y);
            array_printer(n);
        }
    }
    Display();
    return 0;
}
