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
    int tt;
    cin>>tt;
    while(tt)
    {
        lli n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        map<char,set<lli>> g;

        for(int i=0; i<s.length(); i++)
            g[s[i]].insert(i);

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != t[i])
            {
                if(s[i] == 'a' && t[i] == 'b' || s[i] == 'b' && t[i] == 'c')
                {
                    if(s[i] == 'a')
                    {
                        auto nxt_c = g['c'].lower_bound(i);
                        auto nxt_b = g['b'].lower_bound(i);

                        if(nxt_b == g['b'].end())
                        {
                            cout<<"NO\n";
                            goto l;
                        }
                        else
                        {
                            if(nxt_c != g['c'].end())
                            {
                                if(*nxt_c < *nxt_b)
                                {
                                    cout<<"NO\n";
                                    goto l;
                                }
                                else
                                {
                                    s[(*nxt_b)] = 'a';
                                    s[i] = 'b';
                                    lli a_fr = i;
                                    lli a_to = *nxt_b;
                                    lli b_fr = *nxt_b;
                                    lli b_to = i;
                                    g['a'].erase(g['a'].find(a_fr));
                                    g['a'].insert(a_to);
                                    g['b'].erase(g['b'].find(b_fr));
                                    g['b'].insert(b_to);
                                }
                            }
                            else
                            {
                                s[(*nxt_b)] = 'a';
                                s[i] = 'b';
                                lli a_fr = i;
                                lli a_to = *nxt_b;
                                lli b_fr = *nxt_b;
                                lli b_to = i;
                                g['a'].erase(g['a'].find(a_fr));
                                g['a'].insert(a_to);
                                g['b'].erase(g['b'].find(b_fr));
                                g['b'].insert(b_to);
                            }
                        }
                    }
                    else
                    {
                        auto nxt_c = g['c'].lower_bound(i);
                        auto nxt_a = g['a'].lower_bound(i);
                        if(nxt_c == g['c'].end())
                        {
                            cout<<"NO\n";
                            goto l;
                        }
                        else
                        {
                            if(nxt_a != g['a'].end())
                            {
                                if( *nxt_a < *nxt_c)
                                {
                                    cout<<"NO\n";
                                    goto l;
                                }
                                else
                                {
                                    s[(*nxt_c)] = 'b';
                                    s[i] = 'c';
                                    lli b_fr = i;
                                    lli b_to = (*nxt_c);
                                    lli c_fr = (*nxt_c);
                                    lli c_to = i;
                                    g['b'].erase(g['b'].find(b_fr));
                                    g['b'].insert(b_to);
                                    g['c'].erase(g['c'].find(c_fr));
                                    g['c'].insert(c_to);
                                }
                            }
                            else
                            {
                                s[(*nxt_c)] = 'b';
                                s[i] = 'c';
                                lli b_fr = i;
                                lli b_to = (*nxt_c);
                                lli c_fr = (*nxt_c);
                                lli c_to = i;
                                g['b'].erase(g['b'].find(b_fr));
                                g['b'].insert(b_to);
                                g['c'].erase(g['c'].find(c_fr));
                                g['c'].insert(c_to);
                            }
                        }
                    }
                }
                else
                {
                    cout<<"NO\n";
                    goto l;
                }

            }

        }
        cout<<"YES\n";
l:
        tt--;
    }
    return 0;
}
