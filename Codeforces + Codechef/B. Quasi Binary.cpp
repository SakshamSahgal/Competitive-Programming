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
    int n;
    cin>>n;
    int maxx = INT_MIN;
    int nod = 0;
    vector<int> dig;

    while(n != 0)
    {
        maxx = max(maxx,n%10);
        nod++;
        dig.insert(dig.begin(),n%10);
        n/=10;
    }
    int x[maxx][nod];
    for(int i=0; i<nod; i++)
    {
        for(int j=0; j<maxx; j++)
        {
            if(j<dig[i])
                x[j][i] = 1;
            else
                x[j][i] = 0;
        }
    }

    cout<<maxx<<"\n";
    bool one_found=0;
    for(int i=0; i<maxx; i++)
    {
        one_found = 0;
        for(int j=0; j<nod; j++)
        {
            if(x[i][j] == 1)
                one_found = 1;
            if(one_found == 1)
                cout<<x[i][j];
        }

        cout<<" ";
    }
    return 0;
}
