
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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

lli ans=0;

void try_it(vector<lli> a,lli i)
{
    if(i < a.size())
    {
        a[i] = 0;
        try_it(a,i+1);
        a[i] = 1;
        try_it(a,i+1);
        a[i] = 2;
        try_it(a,i+1);
    }
    else
    {
        //vector_printer(a);
        lli c=0;
        for(int i=1;i<a.size()-1;i++)
        {
            if( ( a[i] > a[i-1] && a[i] > a[i+1] ) || ( a[i] < a[i-1] && a[i] < a[i+1] ) )
                c++;
        }

        ans += c;
    }
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        ans = 0;
        lli n;
        cin>>n;
        vector<lli> a(n);
        try_it(a,0);
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
