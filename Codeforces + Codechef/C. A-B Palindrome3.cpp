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
        lli a,b;
        cin>>a>>b;
        string s;
        cin>>s;

        lli noz=0;
        lli noo=0;
        lli noq=0;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '0')
                noz++;
            else if(s[i] == '1')
                noo++;
            else
                noq++;
        }

        if(noz > a || noo > b)
            cout<<"-1\n";
        else
        {
            lli n = s.length();
            a -= noz;
            b -= noo;

            for(int i=0; i<n/2; i++)
            {
                if(s[i] == '0' && s[n-i-1] == '?')
                {
                    s[n-i-1] = '0';
                    a-=1;
                }
                else if(s[i] == '?' && s[n-i-1] == '0')
                {
                    s[i] = '0';
                    a-=1;
                }
                else if(s[i] == '1' && s[n-i-1] == '?')
                {
                    s[n-i-1] = '1';
                    b-=1;
                }
                else if(s[i] == '?' && s[n-i-1] == '1')
                {
                    s[i] = '1';
                    b-=1;
                }

                if(a < 0 || b < 0)
                {
                    cout<<"-1\n";
                    goto k;
                }
            }

            lli l=0;
            lli r=s.length() - 1;

            while(l <= r)
            {
                // cout<<"( "<<l<<" , "<<r<<") \n";
                if(l == r)
                {
                    if(s[l] == '?')
                    {
                        if(a>=b)
                        {
                            s[l] = '0';
                            a-=1;
                        }
                        else
                        {
                            s[l] = '1';
                            b-=1;
                        }
                    }
                }
                else
                {
                    if(s[l] == '?' && s[r] == '?')
                    {
                        if(a >= b)
                        {
                            s[l]='0';
                            s[r]='0';
                            a-=2;
                        }
                        else
                        {
                            s[l]='1';
                            s[r]='1';
                            b-=2;
                        }
                    }
                    else if( ( s[l] == '0' && s[r] == '1' ) || ( s[l] == '1' && s[r] == '0' ) )
                    {
                        cout<<"-1\n";
                        goto k;
                    }
                }

                if(a < 0 || b < 0)
                {
                    cout<<"-1\n";
                    goto k;
                }

                l++;
                r--;
            }
            cout<<s<<"\n";
        }

k:
        t--;
    }
    return 0;
}
