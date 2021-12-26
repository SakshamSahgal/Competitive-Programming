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

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli ans[n];
        vector<lli> e;
        vector<lli> o;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(i%2 == 0)
                e.push_back(a[i]);
            else
                o.push_back(a[i]);
        }

        sort(e.begin(),e.end(),greater<lli>());
        sort(o.begin(),o.end());

        // vector_printer(e);
        //vector_printer(o);

        for(int i=0,j=0;i<e.size();i++,j+=2)
                ans[j] = e[i];
        for(int i=0,j=1;i<o.size();i++,j+=2)
                ans[j] = o[i];

        lli postfix[n];
        lli sum=0;
        for(int i=0,j=n-1;i<n;i++,j--)
        {
            cout<<ans[i]<<" ";

            if(j%2 == 1)
                sum += ans[j];
            postfix[j] = sum;
        }
        cout<<"\n";
        lli x=0;
        for(int i=0;i<n;i+=2)
            x += ans[i]*postfix[i];
        cout<<x<<"\n";
        t--;
    }
    return 0;
}
