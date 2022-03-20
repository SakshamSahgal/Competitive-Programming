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
        lli l,r,m;
        cin>>l>>r>>m;
        for(lli a=l; a<=r; a++)
        {
            lli mini = l-r;
            lli maxx = r-l;
            if(m%a == 0)
            {
                cout<<a<<" "<<l<<" "<<l<<"\n";
                break;
            }
            else
            {
                if(m < a)
                {
                    lli to_add = a-m;
                    if(maxx < to_add)
                        continue;
                    else
                    {
                        for(lli b=l; b<=r; b++)
                        {
                            lli c = to_add + b;
                            if( c >= l && c <= r )
                            {
                                cout<<a<<" "<<b<<" "<<c<<"\n";
                                goto k;
                            }
                        }
                    }
                }
                else
                {
                    lli low = -m%a;
                    lli high = a - m%a;
                   // cout<<"low = "<<low<<" high = "<<high<<"\n";
                    if(mini <= low)
                    {
                        for(lli b=l; b<=r; b++)
                        {
                            lli c = low + b;
                            if( c >= l && c <= r )
                            {
                                cout<<a<<" "<<b<<" "<<c<<"\n";
                                goto k;
                            }
                        }
                    }
                    else if( maxx >= high)
                    {
                        for(lli b=l; b<=r; b++)
                        {
                            lli c = high + b;
                            if( c >= l && c <= r )
                            {
                                cout<<a<<" "<<b<<" "<<c<<"\n";
                                goto k;
                            }
                        }
                    }
                    else
                        continue;
                }
            }
        }
k:
        t--;
    }
    return 0;
}

