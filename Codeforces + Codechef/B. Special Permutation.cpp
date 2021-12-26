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
        lli n,a,b;
        cin>>n>>a>>b;
        vector<lli> fh;
        vector<lli> sh;
        map<lli,lli>rem;

        fh.push_back(a);
        for(int i=n; i>=a+1 && fh.size()<= n/2 - 1; i--)
        {
            if(i != b)
                fh.push_back(i);
        }


        //vector_printer(fh);

        if(fh.size() < n/2)
        {
            cout<<"-1\n";
            goto l;
        }
        else
        {
            sh.push_back(b);
            rem[b] = 1;
            for(auto i:fh)
                rem[i] = 1;

            for(int i=1; i<=n; i++)
            {
                if(rem[i] == 0)
                {
                    if( i > b)
                    {
                        cout<<"-1\n";
                        goto l;
                    }
                    else
                        sh.push_back(i);
                }
            }

        //vector_printer(sh);

            for(auto i:fh)
                cout<<i<<" ";
            for(auto i:sh)
                cout<<i<<" ";
            cout<<"\n";
        }
l:
        t--;
    }
    return 0;
}
