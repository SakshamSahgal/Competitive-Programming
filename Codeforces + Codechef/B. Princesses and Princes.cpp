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

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        map<lli,vector<lli>> g;
        for(int i=1;i<=n;i++)
        {
            lli k;
            cin>>k;
            for(int j=1;j<=k;j++)
            {
                lli x;
                cin>>x;
                g[i].push_back(x);
            }
        }
        //display(g);
        bool taken[n+1] = {0};
        vector<lli> unmarraged;
        bool rem_daughter[n+1] = {0};
        for(auto i:g)
        {
            for(auto j:i.second)
            {
                if(taken[j] == 0)
                {
                    rem_daughter[i.first] = 1;
                    taken[j] = 1;
                    break;
                }
            }
        }

        for(int i=1;i<=n;i++)
            if(rem_daughter[i] == 0)
                unmarraged.push_back(i);

        if(unmarraged.size() == 0)
            cout<<"OPTIMAL\n";
        else
        {

            lli ava = 0;
            for(int i=1;i<=n;i++)
            {
                if(taken[i] == 0)
                    {
                        ava = i;
                        break;
                    }
            }

            if(ava == 0)
                cout<<"OPTIMAL\n";
            else
            {
                cout<<"IMPROVE\n";
                cout<<unmarraged[0]<<" "<<ava<<"\n";
            }
        }

        t--;
    }
    return 0;
}
