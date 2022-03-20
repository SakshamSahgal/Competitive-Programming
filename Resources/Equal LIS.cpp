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
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        if(n%2)
        {
            cout << "YES" << endl;
            for(int i = 1; i <= (n/2); i++)
            {
                cout << i << " ";
            }
            cout << n << " ";
            for(int i = n-1; i > (n/2); i--)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else if(n != 2)
        {
            cout << "YES" << endl;
            cout << (n/2) << " ";
            for(int i = 1; i < (n/2); i++)
            {
                cout << i << " ";
            }
            for(int i = n; i > (n/2); i--)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "NO" << endl;

        }
    }


    return 0;
}
