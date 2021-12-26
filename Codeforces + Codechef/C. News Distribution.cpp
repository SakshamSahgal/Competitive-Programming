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

int p[500001];

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
    //cout<<"abs parent of "<<a<<" is "<<pa<<" set size = "<<abs(p[pa])<<"\n";
    //cout<<"abs parent of "<<b<<" is "<<pb<<" set size = "<<abs(p[pb])<<"\n";
    if(pa != pb)
    {
        if(abs(p[pa]) >= abs(p[pb])) //if set a is bigger
        {
            //adding set b to set a
            p[pa] += p[pb];
            p[pb] = pa;
            //cout<<"adding set "<<b<<" to set "<<a<<" , now set size = "<<abs(p[pa])<<" with parent "<<pa<<"\n";
        }
        else
        {
            //adding set a to set b
            p[pb] += p[pa];
            p[pa] = pb;
            //cout<<"adding set "<<a<<" to set "<<b<<" , now set size = "<<abs(p[pb])<<" with parent "<<pb<<"\n";
        }
    }
}

int main()
{
    //GO_FAST
    memset(p, -1, sizeof(p));
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int s;
        cin>>s;
        int x[s];
        for(int j=0; j<s; j++)
            cin>>x[j];
        for(int j=0; j<s-1; j++)
            union_set(x[j],x[j+1]);
    }
    //array_printer(n);
    for(int i=1; i<=n; i++)
        cout<<abs(p[get_Parent(i)])<<" ";
    return 0;
}
