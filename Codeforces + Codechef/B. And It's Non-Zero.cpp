#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<stack>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

map<lli,vector<lli>> g;

void Decimal_to_binary(lli n)
{
    lli temp = n;
    lli c=0;
    while(n!=0)
    {
        if(n%2 == 1)
         g[c].push_back(temp);
        n/=2;
        c++;
    }
}

void display(map<lli,vector<lli>> g)
{
    cout<<"\n-------------------\n";
    for(auto i:g)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
}

lli no_of_elements(lli l,lli r,lli p)
{
    if(g[p].size() == 0)
        return 0;
    else
    {
        if(g[p][0] > r )
            return 0;
        else if( g[p][(g[p].size() - 1)] < l )
            return 0;
        else
        {
            auto st = lower_bound(g[p].begin(),g[p].end(),l);
            auto ed = lower_bound(g[p].begin(),g[p].end(),r);
            lli sti = st - g[p].begin();
            lli edi = ed - g[p].begin();

            if(r < (*ed))
                edi--;

            edi = min(((lli)(g[p].size()-1)),edi);
           // cout<<"st = "<<sti<<"ed = "<<edi<<"\n";
            return edi - sti + 1;
        }
    }
}

int main()
{
    GO_FAST

    for(int i=1;i<=200000;i++)
        Decimal_to_binary(i);

    //display(g);

    int t;
    cin>>t;
    while(t)
    {
        lli l,r;
        cin>>l>>r;
        lli maxx = 0;
        for(int i=0;i<=18;i++)
        {
            maxx = max(maxx,no_of_elements(l,r,i));
            //cout<<"for p = "<<i<<" elements = "<<no_of_elements(l,r,i)<<"\n";
        }
        cout<< r-l+1 - maxx<<"\n";
        t--;
    }
    return 0;
}
