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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        bool d[n][5];
        for(lli i=0; i<n; i++)
        {
            for(lli j=0; j<5; j++)
                cin>>d[i][j];
        }


        for(int i=0; i<5; i++)
        {
            for(int j=i+1; j<5; j++)
            {
                lli both=0,first=0,second=0;
                bool fail=0;
                for(int k=0; k<n; k++)
                {

                    if(d[k][i] == 0 && d[k][j] == 0)
                    {
                        fail=1;
                        break;
                    }
                    else if(d[k][i] == 1 && d[k][j] == 1)
                        both++;
                    else if(d[k][i] == 1)
                        first++;
                    else
                        second++;


                }

                if(fail == 0 && second <= n/2 && first <= n/2)
                {
                    cout<<"YES\n";
                    goto l;
                }
            }
        }
        cout<<"NO\n";
l:
        t--;
    }
    return 0;
}
