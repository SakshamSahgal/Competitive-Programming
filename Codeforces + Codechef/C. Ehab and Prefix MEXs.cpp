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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;



int main()
{
    GO_FAST

    lli n;
    cin>>n;
    lli a[n+1];
    lli b[n+1];
    set<lli> ava;
    set<lli> empt;
    map<lli,lli> beg;

    for(lli i=0; i<=1e6; i++)
        ava.insert(i);

    for(lli i=1; i<=n; i++)
    {
        empt.insert(i);
        cin>>a[i];
        b[i] = -1;
        beg[a[i]] = i+1;
    }

    for(lli i=1; i<=n; i++)
    {
        while(1)
        {
            lli mini = *(ava.begin());
            if(mini < a[i])
            {
                auto ptr = empt.lower_bound(beg[mini]);
                if(ptr == empt.end())
                {
                    cout<<"-1\n";
                    return 0;
                }
                else
                {
                    ///cout<<"gonna put "<<mini<<" at = "<<(*ptr)<<"\n";
                    b[(*ptr)] = mini;
                    ava.erase(ava.begin());
                    empt.erase(ptr);
                }
            }
            else
                break;
        }
    }

    lli c = 100001;
    for(lli i=1;i<=n;i++)
    {
        if(b[i] == -1)
            b[i] = c++;
    }

    for(lli i=1;i<=n;i++)
        cout<<b[i]<<" ";
    cout<<"\n";
    return 0;
}
