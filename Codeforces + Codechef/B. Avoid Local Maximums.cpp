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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];
        lli c=0;
        for(int i=0; i<n;)
        {
            if(i != 0 && i != n-1)
            {
                if(a[i-1] < a[i] && a[i] > a[i+1])
                {
                    if(i + 3 < n)
                    {
                        int j = i+2;
                        if(a[j-1] < a[j] && a[j] > a[j+1])
                        {
                            a[i+1] = max(a[i],a[j]);
                            c++;
                            i+=4;
                        }
                        else
                        {
                            a[i] = max(a[i-1],a[i+1]);
                            c++;
                            i++;
                        }
                    }
                    else
                    {
                        a[i] = max(a[i-1],a[i+1]);
                        c++;
                        i++;
                    }
                }
                else
                    i++;
            }
            else
                i++;
        }
        cout<<c<<"\n";
        for(int i=0;i<n;i++)
            cout<<a[i]<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}

