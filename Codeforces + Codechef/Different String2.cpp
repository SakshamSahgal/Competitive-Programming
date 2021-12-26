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

string no_to_bin(lli n,lli N)
{
    string x;
    vector<int> v;
    while(n!= 0)
    {
        v.insert(v.begin(),n%2);
        n/=2;
    }
    int temp = v.size();
    for(int k=0; k<(N-temp); k++)
    {
        v.insert(v.begin(),0);
    }
    for(int i=0; i<v.size(); i++)
        x += (v[i] + 48);
    return x;
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
        vector<string> v;
        for(int i=0; i<n; i++)
        {
            string x;
            cin>>x;
            //cout<<x<<"\n";
            v.push_back(x);
        }

        bool found=0;
        string tt;
        for(int i=0; i<102; i++)
        {
            found = 0;
            tt = no_to_bin(i,n);
            for(int j=0; j<n; j++)
            {
                if(v[j] == tt)
                {
                    found = 1;
                    break;
                }
            }
            if(found == 0)
            {
                cout<<tt<<"\n";
                break;
            }

        }

        t--;
    }
    return 0;
}

