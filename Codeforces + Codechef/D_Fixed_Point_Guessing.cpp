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
    // freopen("input.txt", "r", stdi#include<iostream>
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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {

        t--;
    }
    return 0;
}n);
    // freopen("myout.txt", "w", stdout);
    lli t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if(n == -1)
            return 0;
        lli l = 1;
        lli h = n;
        lli ans = -1;
        while (l < h)
        {
            int mid = (l + h) / 2;
            cout << "? " << l << " " << mid <<endl;
            lli a[mid - l + 1];
            lli c = 0;
            for (int i = 0; i < (mid - l + 1); i++)
            {
                cin >> a[i];
                if(a[i] != -1)
                {
                    if (a[i] >= l && a[i] <= mid)
                    c++;
                }
                else
                    return 0;
                
            }

            if (c % 2)
                h = mid;
            else
                l = mid + 1;
        }

        cout << "! " << l << endl;
    }

    return 0;
}