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

lli mini = INT_MAX;

lli max_xor(vector<lli> &v)
{
    lli maxx = 0;
    for(int i=0;i<v.size()-1;i++)
        maxx = max((v[i]^v[i+1]),maxx);

    return maxx;
}

void vector_printer( vector<lli> v)
{
   // cout<<"\n------------------------\n";
   // for(int i=0; i<v.size(); i++)
      //  cout<<v[i]<<" ";

    lli x= max_xor(v);
    cout<<" xor = "<<x;
    mini = min(mini,x);
   // cout<<"\n------------------------\n";
}
int main()
{
    //GO_FAST
    vector<lli> v = {0,6,1,2,3,4,5};
    cout<<"test ans = "<<max_xor(v)<<"\n";
    sort(v.begin(),v.end());
    do
        {
        vector_printer(v);
        }
    while(next_permutation(v.begin(),v.end()));
    cout<<"mini = "<<mini<<"\n";
    return 0;
}
