#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    vector<pair<int,int>> p;

    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        p.push_back({x,i+1});
    }

    sort(p.begin(),p.end());

    cout<<p[p.size()-2].second<<"\n";

    return 0;
}


