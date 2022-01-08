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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        lli res = 0 ;
        lli p = 1;
        for (lli i = 0; i < 32; ++i)
        {
            lli c = 0;
            for (lli j = 0; j < n; ++j)
            {
                if (a[j] % 2 != 1)
                {
                }
                else
                {
                    c++;
                }
                a[j] = a[j] / 2;
            }
            if (c > 1)
            {
                res = res + p;
            }
            p = p * 2;

        }

        cout << res <<"\n";


        t--;
    }
    return 0;
}



