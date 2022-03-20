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
        lli n;
        cin>>n;

        lli a[n];

        for(int i=0; i<n; i++)
            cin>>a[i];

        string s;
        cin>>s;

        lli b[n];
        for(int i=0; i<n; i++)
            b[i] = a[i];

        sort(b,b+n);

        if(n == 1)
            cout<<0<<"\n";
        else
        {
            bool all_s=1;
            bool all_n=1;
            for(int i=0; i<n; i++)
            {
                if(s[i] == 'S')
                    all_n = 0;
                if(s[i] == 'N')
                    all_s = 0;
            }

            if(all_n || all_s)
            {
                for(int i=0; i<n; i++)
                {
                    if(b[i] != a[i])
                    {
                        cout<<"-1\n";
                        goto l;
                    }
                }
                cout<<0<<"\n";
            }
            else
            {
                lli ans1=inf,ans2=inf,ans3=inf,ans4=inf;
                if(s[0] == 'S')
                {
                    lli last_n = 1;
                    for(int i=n-1; i>0; i--)
                    {
                        if(s[i] == 'N')
                        {
                            last_n = i;
                            break;
                        }
                    }
                    bool all_set = 1;
                    bool req=0;
                    for(int i=0; i<last_n; i++)
                    {
                        if(a[i] != b[i])
                        {
                            req = 1;
                            break;
                        }
                    }

                    if(req)
                        ans1 = 1;
                    else
                        ans1 = 0;

                    for(int i=last_n+1; i<n; i++)
                    {
                        if(a[i] != b[i])
                        {
                            all_set = 0;
                            break;
                        }
                    }

                    if(!all_set)
                        ans1++;
                }
                if(s[0] == 'N')
                {
                    lli last_s = 1;
                    for(int i=n-1; i>0; i--)
                    {
                        if(s[i] == 'S')
                        {
                            last_s = i;
                            break;
                        }
                    }

                    bool req=0;
                    for(int i=0; i<last_s; i++)
                    {
                        if(a[i] != b[i])
                        {
                            req = 1;
                            break;
                        }
                    }

                    if(req)
                        ans2 = 1;
                    else
                        ans2 = 0;

                    bool all_set = 1;
                    for(int i=last_s+1; i<n; i++)
                    {
                        if(a[i] != b[i])
                        {
                            all_set = 0;
                            break;
                        }
                    }

                    if(!all_set)
                        ans2++;
                }

                if(s[n-1] == 'S')
                {
                    lli first_n = n-2;

                    for(int i=0; i<n-1; i++)
                    {
                        if(s[i] == 'N')
                        {
                            first_n = i;
                            break;
                        }
                    }

                    bool req=0;

                    for(int i=first_n; i<n; i++)
                    {
                        if(a[i] != b[i])
                        {
                            req=1;
                            break;
                        }
                    }

                    if(req)
                        ans3 = 1;
                    else
                        ans3 = 0;

                    bool all_set = 1;
                    for(int i=0; i<first_n; i++)
                    {
                        if(a[i] != b[i])
                        {
                            all_set = 0;
                            break;
                        }
                    }

                    if(!all_set)
                        ans3++;
                }

                if(s[n-1] == 'N')
                {
                    lli first_s = n-2;

                    for(int i=0; i<n-1; i++)
                    {
                        if(s[i] == 'S')
                        {
                            first_s = i;
                            break;
                        }
                    }

                    bool req=0;

                    for(int i=first_s; i<n; i++)
                    {
                        if(a[i] != b[i])
                        {
                            req=1;
                            break;
                        }
                    }

                    if(req)
                        ans4 = 1;
                    else
                        ans4 = 0;

                    bool all_set = 1;
                    for(int i=0; i<first_s; i++)
                    {
                        if(a[i] != b[i])
                        {
                            all_set = 0;
                            break;
                        }
                    }

                    if(!all_set)
                        ans4++;
                }

                cout<<min(min(ans1,ans2),min(ans3,ans4))<<"\n";
            }

        }
l:
        t--;
    }
    return 0;
}

