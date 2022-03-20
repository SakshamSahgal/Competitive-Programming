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
    int t;
    cin>>t;
    while(t)
    {
        lli n0,n1,n2;
        cin>>n0>>n1>>n2;
        if(n1%2 == 0)
        {
            if(n0 == 0)
            {
                for(int i=0; i<n1+1; i++)
                {
                    if(i%2==0)
                        cout<<1;
                    else
                        cout<<0;
                }
                for(int i=0; i<n2; i++)
                    cout<<1;
            }
            else if(n2 == 0)
            {
                for(int i=0; i<n0; i++)
                    cout<<0;
                for(int i=0; i<n1+1; i++)
                {
                    if(i%2==0)
                        cout<<0;
                    else
                        cout<<1;
                }

            }
            else
            {
                for(int i=0;i<n0+1;i++)
                    cout<<0;
                for(int i=0;i<n2+1;i++)
                    cout<<1;
                for(int i=0;i<n1-1;i++)
                {
                    if(i%2==0)
                        cout<<0;
                    else
                        cout<<1;
                }
            }
        }
        else
        {
            for(int i=0;i<n0;i++)
                cout<<0;
            for(int i=0;i<n1+1;i++)
            {
                if(i%2 ==0)
                    cout<<0;
                else
                    cout<<1;
            }
            for(int i=0;i<n2;i++)
                cout<<1;
        }
        cout<<"\n";
        t--;
    }
    return 0;
}
