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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    lli ct=1;
    while(t)
    {
        lli r,c;
        cin>>r>>c;
        cout<<"Case #"<<(ct++)<<":\n";
        for(lli i=0; i < 2*r + 1 ; i++)
        {
            for( lli j=0; j < 2*c + 1 ; j++)
            {
                if( i < 2 && j < 2)
                    cout<<".";
                else
                {
                    if( i%2 == 0 && j%2 == 0)
                        cout<<"+";
                    else if(i%2 == 1 && j%2 == 0)
                        cout<<"|";
                    else if(i%2 == 0 && j%2 == 1)
                        cout<<"-";
                    else
                        cout<<".";
                }

            }
            cout<<"\n";
        }
        t--;
    }
    return 0;
}

