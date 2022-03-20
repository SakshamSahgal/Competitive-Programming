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

lli pre[100000];

void pre_calc_xor()
{
    pre[0] = 0;
    for(int i=1; i<100000; i++)
        pre[i] = pre[i-1]^i;
}

int main()
{
    GO_FAST
    pre_calc_xor();
    int t;
    cin>>t;
    while(t)
    {
        lli n,x;
        cin>>n>>x;
        if(n == 1)
            cout<<x<<"\n";
        else if(n == 2)
            cout<<0<<" "<<x<<"\n";
        else
        {
            lli prev = pre[n-2];
            lli last = x^prev;
           // cout<<prev<<" "<<last<<"\n";

            if(last >= n && last <= 500000)
            {
                for(int i=0; i<=n-2; i++)
                    cout<<i<<" ";

                cout<<last<<"\n";
            }
            else
            {
                if(last >= 0 && last <= n-1) //repitition
                {
                    if(last != 0)
                    {
                        lli a0 = (powl(2,18));

                        cout<<a0<<" ";

                        for(lli i=1; i<=n-2; i++)
                            cout<<i<<" ";

                        last += powl(2,18);
                        cout<<last<<"\n";
                    }
                    else
                    {
                        lli a = 1 + pow(2,18);
                        cout<<0<<" "<<a<<" ";
                        for(lli i=2; i<=n-2; i++)
                            cout<<i<<" ";

                        last += powl(2,18);
                        cout<<last<<"\n";
                    }
                }
                else //last > 500000
                {
                    if( last - powl(2,18) > n-2 )
                    {
                        lli a0 = (powl(2,18));

                        cout<<a0<<" ";

                        for(lli i=1; i<=n-2; i++)
                            cout<<i<<" ";

                        last -= powl(2,18);

                        cout<<last<<"\n";
                    }
                    else
                    {
                        lli c = last - powl(2,18);
                        for(lli i=0;i<=(n-2);i++)
                        {
                            if(i == c)
                            {
                                lli temp = i + powl(2,18);
                                cout<<temp<<" ";
                            }
                            else
                                cout<<i<<" ";
                        }
                        last -= powl(2,18);
                        cout<<last<<"\n";
                    }
                }
            }
        }
        t--;
    }
    return 0;
}
