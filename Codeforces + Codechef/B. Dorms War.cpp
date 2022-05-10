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
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;
        lli prefix[n];
        lli k;
        cin>>k;
        map<char,lli> sp;
        for(int i=0;i<k;i++)
        {
            char z;
            cin>>z;
            sp[z] = 1;
        }
        lli last = 0;
        for(int i=0;i<n;i++)
        {
            if(sp[s[i]] == 1)
                last = i;
            prefix[i] = last;
        }

        //array_printer(prefix,n);
        lli maxx = 0;
        for(int i=0;i<n;i++)
        {
            lli moves_req;
            if(sp[s[i]] == 1 && i != 0)
            {
                moves_req = i - prefix[i-1];
                //cout<<moves_req<<"\n";
                maxx = max(maxx,moves_req);
            }
        }
        cout<<maxx<<"\n";
        t--;
    }
    return 0;
}
