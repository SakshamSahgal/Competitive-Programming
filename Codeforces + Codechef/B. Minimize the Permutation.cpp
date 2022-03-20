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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;


lli aage(vector<lli> &v,lli ind)
{
    lli mini = v[ind];
    lli index=-1;
    for(int i = ind+1;i<v.size();i++)
    {
        if(v[i] < mini)
        {
             mini = v[i];
             index = i;
        }
    }
    return index;
}

void vector_printer( vector<lli> v)
{
    //cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    //cout<<"\n------------------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> v(n);
        for(int i=0; i<n; i++)
            cin>>v[i];

        lli st=0;
        while(st != n-1)
        {
            lli id = aage(v,st);
            //cout<<"at = "<<st<<" next = "<<id<<"\n";
            if(id == -1)
                st++;
            else
            {
                lli that = v[id];
                v.erase(v.begin() + id);
                v.insert(v.begin() + st,that);
                st = id;
            }
        }
        vector_printer(v);
        cout<<"\n";
        t--;
    }
    return 0;
}

