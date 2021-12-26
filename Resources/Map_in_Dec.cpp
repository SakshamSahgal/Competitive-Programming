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

int main()
{
    //GO_FAST
        lli n;
        cin>>n;
        vector<lli> a(n);
        map<lli,lli,greater<lli>> f; //value freq;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }

        for(auto i:f)
            cout<<i.first<<" "<<i.second<<"\n";

    /*
     try testcase -
    6
    1 1 5 1 6 5
    */
    return 0;
}

