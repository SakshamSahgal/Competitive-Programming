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
        lli n;
        cin>>n;
        lli a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        lli st=0;
        lli ed=n-1;
        lli pa = -1;
        lli pb = -1;
        lli pa_i = -1;
        lli pb_i = -1;
        while(st <= ed)
        {
            //cout<<"comparing "<<a[st]<<" "<<a[ed]<<"\n";
            if(a[st] != a[ed])
            {
                pa = a[st];
                pb = a[ed];
                pa_i = st;
                pb_i = ed;
                //cout<<"possible "<<pa<<" "<<pb<<"\n";
                break;
            }
            else
            {
                st++;
                ed--;
            }
        }

        if(pa == -1 && pb == -1)
            cout<<"YES\n";
        else
        {
            //cout<<"Trying "<<pa<<"\n";
            st = pa_i + 1;
            ed = pb_i;

            bool fail1=0;

            while(st <= ed)
            {
                //cout<<"comparing "<<a[st]<<" "<<a[ed]<<"\n";
                if( a[st] != a[ed] )
                {
                    if(a[st] != pa && a[ed] != pa)
                    {
                        //cout<<pa<<" not possible \n";
                        fail1 = 1;
                        break;
                    }
                    else
                    {
                        if(a[st] == pa)
                        {
                            //cout<<"Removing "<<a[st]<<"\n";
                            st++;
                        }
                        else
                        {
                            //cout<<"Removing "<<a[ed]<<"\n";
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


            //cout<<"Trying "<<pb<<"\n";

            st = pa_i;
            ed = pb_i - 1;
            bool fail2=0;

            while(st <= ed)
            {
                // cout<<"comparing "<<a[st]<<" "<<a[ed]<<"\n";
                if( a[st] != a[ed] )
                {
                    if(a[st] != pb && a[ed] != pb)
                    {
                        //cout<<pb<<" not possible \n";
                        fail2 = 1;
                        break;
                    }
                    else
                    {
                        if(a[st] == pb)
                        {
                            // cout<<"Removing "<<a[st]<<"\n";
                            st++;
                        }
                        else
                        {
                            // cout<<"Removing "<<a[ed]<<"\n";
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

            if(fail1 == 1 && fail2 == 1)
                cout<<"NO\n";
            else
                cout<<"YES\n";

        }


        t--;
    }
    return 0;
}
