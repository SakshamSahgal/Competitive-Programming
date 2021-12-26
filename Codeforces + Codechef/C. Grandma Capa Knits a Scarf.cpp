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
using namespace std;

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;

        lli st=0;
        lli ed=n-1;
        char pa = '?';
        char pb = '?';
        lli pa_i=0;
        lli pb_i=0;
        while(st <= ed)
        {
           // cout<<"comparing "<<s[st]<<" "<<s[ed]<<"\n";
            if( s[st] != s[ed] )
            {
                pa = s[st];
                pb = s[ed];
                pa_i = st;
                pb_i = ed;
               // cout<<"possible "<<pa<<" "<<pb<<"\n";
                break;
            }
            else
            {
                st++;
                ed--;
            }
        }

        if(pa == '?' && pb == '?')
            cout<<0<<"\n";
        else
        {
           // cout<<"Trying "<<pa<<"\n";
            st = pa_i + 1;
            ed = pb_i;

            lli c1=1;

            bool fail1=0;

            while(st <= ed)
            {
               // cout<<"comparing "<<s[st]<<" "<<s[ed]<<"\n";
                if( s[st] != s[ed] )
                {
                    if(s[st] != pa && s[ed] != pa)
                    {
                      //  cout<<pa<<" not possible \n";
                        fail1 = 1;
                        break;
                    }
                    else
                    {
                        if(s[st] == pa)
                        {
                          //  cout<<"Removing "<<s[st]<<"\n";
                            st++;
                            c1++;
                        }
                        else
                        {
                          //  cout<<"Removing "<<s[ed]<<"\n";
                            ed--;
                            c1++;
                        }
                    }
                }
                else
                {
                    st++;
                    ed--;
                }
            }

          //  cout<<"Trying "<<pb<<"\n";

            st = pa_i;
            ed = pb_i - 1;

            lli c2=1;

            bool fail2=0;


            while(st <= ed)
            {
               // cout<<"comparing "<<s[st]<<" "<<s[ed]<<"\n";
                if( s[st] != s[ed] )
                {
                    if(s[st] != pb && s[ed] != pb)
                    {
                       // cout<<pb<<" not possible \n";
                        fail2 = 1;
                        break;
                    }
                    else
                    {
                        if(s[st] == pb)
                        {
                           // cout<<"Removing "<<s[st]<<"\n";
                            st++;
                            c2++;
                        }
                        else
                        {
                           // cout<<"Removing "<<s[ed]<<"\n";
                            c2++;
                            ed--;
                        }
                    }
                }
                else
                {
                    st++;
                    ed--;
                }
            }

            if(fail1 == 1)
                c1 = -1;
            if(fail2 == 1)
                c2 = -1;

           if(c1 == -1 && c2 == -1)
            cout<<-1<<"\n";
           else if(c1 == -1 && c2 != -1)
            cout<<c2<<"\n";
           else if(c1 != -1 && c2 == -1)
            cout<<c1<<"\n";
           else
            cout<<min(c1,c2)<<"\n";
        }
        t--;
    }
    return 0;
}
