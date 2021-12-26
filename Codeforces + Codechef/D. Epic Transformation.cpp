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
        vector<lli> a(n);
        map<lli,lli> f; //value freq;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }

        lli node = f.size();

        vector<lli> uf; //freq value
        bool foas = 1;
        lli foae = f.begin()->second;
        for(auto i:f)
        {
            if(i.second != foae)
                foas = 0;
            uf.push_back(i.second);
        }

        if(foas == 1)
        {
            if(node == 1)
                cout<<foae<<"\n";
            else
            {
                if(node%2 == 0)
                    cout<<0<<"\n";
                else
                {
                    if(foae%2 == 0)
                        cout<<0<<"\n";
                    else
                        cout<<1<<"\n";
                }
            }
        }
        else
        {
            sort(uf.begin(),uf.end(),greater<lli>());
            //vector_printer(uf);
            lli sum = uf[0];
            //cout<<"sum = "<<sum<<"\n";
            for(int i=0; i<uf.size()-1; i++)
                sum = abs(sum - uf[i+1]);
            cout<<sum<<"\n";
        }

        t--;
    }
    return 0;
}
