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
    string v[3];
    string x[4] = {"ABC","ARC","AGC","AHC"};
    cin>>v[0];
    cin>>v[1];
    cin>>v[2];

    for(int i=0;i<4;i++)
    {
        bool found = 0;
        for(int j=0;j<3;j++)
        {
            if(x[i] == v[j])
                found = 1;
        }
        if(found == 0)
        {
            cout<<x[i]<<"\n";
            break;
        }
    }
    return 0;
}
