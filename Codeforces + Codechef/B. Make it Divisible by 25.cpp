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

vector<lli> v;

void no_to_vec(lli n)
{
    while(n!= 0)
    {
        v.insert(v.begin(),n%10);
        n/=10;
    }
}


lli moves_to_xy(int x, int y)
{
    lli m=INT_MAX;
    lli fx = -1;
    lli fy = -1;
    for(int i=v.size()-1; i>=0; i--)
    {
        if(v[i] == y && fy == -1)
        {
            fy = i;
            continue;
        }


        if(fy != -1 && fx == -1 && v[i] == x)
        {
            fx = i;
            break;
        }

    }
    //cout<<"fx = "<<fx<<" fy = "<<fy<<"\n";
    if(fx == -1 || fy == -1)
        return INT_MAX;
    else
    {
        if(fx < fy)
            m = v.size() - (fx + 1) - 1;
        else
            return INT_MAX;
    }

    return m;
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
        no_to_vec(n);
        lli a = moves_to_xy(0,0);
        lli b = moves_to_xy(2,5);
        lli c = moves_to_xy(5,0);
        lli d = moves_to_xy(7,5);
        //cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
        v.clear();
        cout<<min(min(a,b),min(c,d))<<"\n";
        t--;
    }
    return 0;
}
