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

    lli a,b,f,k;
    cin>>a>>b>>f>>k;

    lli c=0;
    lli m = 0;
    lli cur=b;
    bool fail=0;
    while(m<k)
    {
        if(m%2 == 0)
        {
            if(cur < f)
            {
                fail = 1;
                break;
            }
            else
            {
                if(cur < a)
                {
                    cur = b - a + f;
                    if(cur < 0)
                    {
                        fail = 1;
                        break;
                    }
                    else
                        c++;
                }
                else
                {
                    if(cur - a < a - f)
                    {
                        if(m == k-1)
                        {
                            m++;
                            break;
                        }
                        else
                        {
                            cur = b - a + f;
                            if(cur < 0)
                            {
                                fail = 1;
                                break;
                            }
                            else
                                c++;
                        }
                    }
                    else
                        cur -= a;
                }
            }
            m++;
        }
        else
        {
            if(cur < (a-f))
            {
                fail = 1;
                break;
            }
            else
            {
                if(cur < a)
                {
                    cur = b - f;
                    if(cur < 0)
                    {
                        fail = 1;
                        break;
                    }
                    else
                        c++;
                }
                else
                {
                    if(cur - a < f)
                    {
                        if(m == k-1)
                        {
                            m++;
                            break;
                        }
                        else
                        {
                            cur = b - f;
                            if(cur < 0)
                            {
                                fail = 1;
                                break;
                            }
                            else
                                c++;
                        }
                    }
                    else
                        cur -= a;
                }
            }
            m++;
        }
    }
    if(fail)
        cout<<-1<<"\n";
    else
        cout<<c<<"\n";

    return 0;
}
