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
    vector<string> v;

    for(int i=0; i<n; i++)
    {
        string ss;
        cin>>ss;
        v.push_back(ss);
    }

    lli maxx = INT_MIN;
    for(int i=0; i<7; i++)
    {
        lli col=0;
        for(int j=0; j<n; j++)
        {
            if(v[j][i] == '1')
                col++;
        }
        //cout<<col<<"\n";
        maxx = max(col,maxx);
    }
    cout<<maxx<<"\n";

    return 0;
}
