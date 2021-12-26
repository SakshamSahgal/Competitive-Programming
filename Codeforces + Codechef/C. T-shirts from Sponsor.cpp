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
    GO_FAST
    lli a[5];
    map<string,lli> m;
    map<lli,string> mm;
    m["S"] = 0;
    m["M"] = 1;
    m["L"] = 2;
    m["XL"] = 3;
    m["XXL"] = 4;

    mm[0] = "S";
    mm[1] = "M";
    mm[2] = "L";
    mm[3] = "XL";
    mm[4] = "XXL";

    for(int i=0; i<5; i++)
        cin>>a[i];
    lli k;
    cin>>k;

    for(int i=0; i<k; i++)
    {
        string s;
        cin>>s;
        lli j=0;

        while(1)
        {
            if( m[s]+j>=0 && m[s]+j < 5 && a[m[s]+j] > 0)
            {
                a[m[s]+j]--;
                cout<<mm[m[s]+j]<<"\n";
                break;
            }
            else if(m[s]-j>=0 && m[s]-j < 5 &&a[m[s]-j] > 0)
            {
                a[m[s]-j]--;
                cout<<mm[m[s]-j]<<"\n";
                break;
            }
            else
                j++;
        }
    }

    return 0;
}
