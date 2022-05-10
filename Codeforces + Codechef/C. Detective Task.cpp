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
        string s;
        cin>>s;
        lli n = s.length();
        lli noo = 0;
        lli noz = 0;
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
                noo++;
            if(s[i] == '0')
                noz++;
        }

        if(noo == 0 && noz == 0)
            cout<<s.length()<<"\n";
        else
        {
            lli last_one = -1;
            lli first_zero = -1;

            for(int i=0;i<n;i++)
            {
                if(s[i] == '1')
                    last_one = i;

                if(s[i] == '0' && first_zero == -1)
                    first_zero = i;

            }

            if(last_one == -1 && first_zero != -1)
                cout<<first_zero + 1<<"\n";
            else if(first_zero == -1 && last_one != -1)
                cout<<n - last_one<<"\n";
            else
                cout<<(abs(last_one - first_zero) + 1)<<"\n";
        }
        t--;
    }
    return 0;
}
