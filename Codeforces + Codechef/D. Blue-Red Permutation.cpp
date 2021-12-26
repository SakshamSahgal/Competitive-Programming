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
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> r;
        vector<lli> b;
        lli a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        string s;
        cin>>s;

        for(int i=0;i<n;i++)
        {
            if(s[i] == 'R')
                r.push_back(a[i]);
            else
                b.push_back(a[i]);
        }

        sort(r.begin(),r.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        //vector_printer(r);
        //vector_printer(b);
        lli cc=n;
        for(int i=0;i<r.size();i++)
        {
            if(r[i] <= cc)
            {
                cc--;
            }
            else
            {
                cout<<"NO\n";
                goto k;
            }
        }

        for(int i=0;i<b.size();i++)
        {
            if(b[i] >= cc)
                cc--;
            else
            {
                cout<<"NO\n";
                goto k;
            }
        }
        cout<<"YES\n";
        k:
        t--;
    }
    return 0;
}
