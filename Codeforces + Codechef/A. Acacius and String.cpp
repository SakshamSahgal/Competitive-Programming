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
        string s;
        cin>>s;
        lli c=0;
        string to_match = "abacaba";
        for(int i=0; i<n-6; i++)
        {
            string temp = s.substr(i,7);
            if(temp == to_match)
                c++;
        }
        //cout<<c<<"\n";
        if(c > 1)
            cout<<"No\n";
        else
        {
            if(c == 1)
            {
                for(int i=0; i<n; i++)
                {
                    if(s[i] == '?')
                        s[i] = 'z';
                }

                cout<<"YES\n";
                cout<<s<<"\n";
            }
            else
            {
                for(int i=0; i<n-6; i++)
                {
                    bool pass1 = 0;
                    bool pass2 = 0;
                    bool pass3 = 0;
                    bool pass4 = 0;

                    lli sp_bef = i;
                    lli sp_aft = n - i - 7;

                    if(sp_bef >= 4)
                    {
                        string tp1 = s.substr(i-4,4);
                        if(tp1 != "abac")
                            pass1 = 1;
                    }
                    else
                        pass1 = 1;

                    if(sp_bef >= 6)
                    {
                        string tp2 = s.substr(i-6,6);
                        if(tp2 != "abacab")
                            pass2 = 1;
                    }
                    else
                        pass2 = 1;

                    if(sp_aft >= 4)
                    {
                        string tp3 = s.substr(i+7,4);
                        if(tp3 != "caba")
                            pass3 = 1;
                    }
                    else
                        pass3 = 1;

                    if(sp_aft >= 6)
                    {
                        string tp4 = s.substr(i+7,6);
                        if(tp4 != "bacaba")
                            pass4 = 1;
                    }
                    else
                        pass4 = 1;

                    //cout<<"i = "<<i<<" pass = {"<<pass1<<" , "<<pass2<<" , "<<pass3<<" , "<<pass4<<"} space before , aft = "<<sp_bef<<" , "<<sp_aft<<"\n";

                    if(pass1 && pass2 && pass3 && pass4)
                    {
                        bool matched=1;
                        for(int j=i,k=0;j<i+7;j++,k++)
                        {
                            if(s[j] != '?' && s[j] != to_match[k])
                            {
                                matched = 0;
                                break;
                            }
                        }

                        if(matched == 1)
                        {
                            for(int j=i,k=0;j<i+7;j++,k++)
                                s[j] = to_match[k];

                            for(int j=0;j<n;j++)
                            {
                                if(s[j] == '?')
                                    s[j] = 'z';
                            }

                            cout<<"YES\n";
                            cout<<s<<"\n";
                            goto l;
                        }
                    }

                }
                cout<<"No\n";
            }

        }

l:
        t--;

    }
    return 0;
}

