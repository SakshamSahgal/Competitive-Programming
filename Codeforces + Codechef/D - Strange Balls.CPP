#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<stack>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

void stack_printer(stack<pair<lli,lli>> s)
{
    line_printer(20);
    vector<pair<lli,lli>> v;
    while(!s.empty())
    {
        //cout<<s.top().first<<" "<<s.top().second<<"\n";
        v.push_back(s.top());
        s.pop();
    }

    for(auto i:v)
        cout<<(i.first)<<" "<<(i.second)<<"\n";
    line_printer(20);
}

int main()
{
    GO_FAST

        lli n;
        cin>>n;
        lli a[n];
        stack<pair<lli,lli>> p;
        int sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(p.empty())
            {
                p.push({a[i],1});
                sum++;
            }
            else
            {
                sum++;
                if(a[i] == p.top().first)
                    p.top().second++;
                else
                p.push({a[i],1});
                if(p.top().first == p.top().second)
                {
                    sum -= p.top().second;
                    p.pop();
                }
            }
            //stack_printer(p);
            cout<<sum<<"\n";

    }
    return 0;
}
