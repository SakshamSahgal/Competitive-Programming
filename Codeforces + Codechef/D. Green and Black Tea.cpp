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
    lli n,k,g,b;
    cin>>n>>k>>g>>b;
    lli gc=0;
    lli bc=0;
    char last;
    string s;
    while(1)
    {
        //cout<<"-- G = "<<g<<" "<<"B = "<<b<<" -- \n";
        if(b == 0 && g == 0)
        {
            cout<<s<<"\n";
            return 0;
        }

        if(b > g)
        {
            if(bc < k)
            {
                b--;
                bc++;
                gc=0;
                s += "B";
                last = 'B';
                //cout<<"B";
            }
            else
            {
                if(g != 0)
                {
                   g--;
                   bc=0;
                   gc++;
                   //cout<<"G";
                   last = 'G';
                   s += "G";
                }
                else
                {
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
        else if(b < g)
        {
            if(gc < k)
            {
                g--;
                gc++;
                bc=0;
                //cout<<"G";
                last = 'G';
                s += "G";
            }
            else
            {
                if(b != 0)
                {
                    b--;
                    bc++;
                    gc=0;
                    //cout<<"B";
                    last = 'B';
                    s += "B";
                }
                else
                {
                    cout<<"NO\n";
                    return 0;
                }
            }
        }
        else
        {
            if(last == 'G')
            {
                bc++;
                gc=0;
                b--;
                last = 'B';
                //cout<<"B";
                s += "B";
            }
            else
            {
                gc++;
                bc=0;
                g--;
                last = 'G';
                //cout<<"G";
                s += "G";
            }
        }
    }


    return 0;
}
