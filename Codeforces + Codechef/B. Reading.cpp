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

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> p; //value //index

    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        p.push_back({x,i});
    }

    sort(p.begin(),p.end());

    //pair_printer(p);

    cout<<p[n-k].first<<"\n";



    for(int i=n-1,j=0; j<k; i--,j++)
        cout<<p[i].second+1<<" ";

    return 0;
}


