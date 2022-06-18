#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including

#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}

using namespace std;
using namespace __gnu_pbds;

typedef tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<lli,null_type,less_equal<lli>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
//accending order -> less<int>
//decending order -> greater<int>
//if you want character ordered set change the int to char

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        lli a[n];
        lli y[n];
        for(lli i=0; i<n; i++)
        {
            cin>>a[i];
            if( (k + a[i])%2 == 0 )
                y[i] = (k + a[i])/2;
            else
                y[i] = -1;
        }
        //array_printer(y,n);
        ordered_multiset xx;
        lli ans=0;
        for(lli i=0; i<n; i++)
        {
            lli mini=0;
            lli maxx=0;

            if(y[i] != -1)
            {
                bool fail=0;

                for(lli j=0; j<=59; j++)
                {
                    lli set_ai = (a[i]>>j)%2;
                    lli set_y = (y[i]>>j)%2;
                    if(set_ai == 1 && set_y == 0)
                    {
                        //cout<<"i = "<<i<<" failed because "<<j<<" bit \n";
                        fail=1;
                        break;
                    }
                    else
                    {
                        if(!set_ai && set_y)
                        {
                            maxx += powl(2,j);
                            mini += powl(2,j);
                        }
                        else if(set_ai && set_y)
                            maxx += powl(2,j);
                    }
                }

                if(!fail)
                {
                    //cout<<"i = "<<i<<" mini = "<<mini<<" maxx = "<<maxx<<"\n";
                    lli bada = (xx.order_of_key(maxx+1));
                    lli chota = (xx.order_of_key(mini));

                    //cout<<"array tn = \n";
                    //for(int i=0; i<xx.size(); i++)
                     //   cout<<(*xx.find_by_order(i))<<" ";
                   // cout<<"\n";
                    //cout<<bada-chota<<"\n";
                    ans += (bada - chota);
                }
            }
                xx.insert(a[i]);
        }

        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
