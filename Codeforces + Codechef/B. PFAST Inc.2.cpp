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

bool available(string a,string b,vector<pair<string,string>> &gussa)
{
    for(auto i:gussa)
    {
        if( ( i.first == a && i.second == b ) || (i.first == b && i.second == a) )
            return 1;
    }
    return 0;
}


bool is_good(vector<string> &x,vector<pair<string,string>> &gussa)
{
    for(auto i:x)
    {
        for(auto j:x)
        {
            if(i!=j && available(i,j,gussa))
                return 0;
        }
    }
    return 1;
}

void vector_printer( vector<string> v)
{
    //cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<"\n";
    //cout<<"\n------------------------\n";
}

int main()
{
    //GO_FAST
    lli n,m;
    cin>>n>>m;
    vector<string> v(n); //all people
    vector<pair<string,string>> gussa(m); //pair who are gussa
    vector<string> ans;

    for(int i=0; i<n; i++)
        cin>>v[i];

    for(int i=0; i<m; i++)
        cin>>gussa[i].first>>gussa[i].second;

    lli max_good=0;
    for(int i=1; i<(pow(2,n)); i++)
    {
        vector<string> s;

        for(int j=0,k=n-1; j<n; j++,k--)
        {
            if((i>>k)%2)
            {
                //cout<<1<<" ";
               // cout<<v[j]<<" ";
                s.push_back(v[j]);
            }
        }

       // cout<<"\n----\n";

        if(s.size() > max_good)
        {
            if(is_good(s,gussa))
            {
                max_good = s.size();
                ans = s;
            }
        }

    }
    cout<<max_good<<"\n";
    sort(ans.begin(),ans.end());
    vector_printer(ans);

    return 0;
}
