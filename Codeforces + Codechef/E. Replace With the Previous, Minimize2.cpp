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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}




int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        if(k >= 25)
        {
            for(int i=0; i<s.length(); i++)
                s[i] = 'a';
            cout<<s<<"\n";
        }
        else
        {
            vector<lli> pref(n);
            for(int i=0; i<n; i++)
            {
                lli id = s[i] - 'a';
                pref[i] = (i == 0) ? id : max(pref[i-1],id);
            }

            //vector_printer(pref);
            lli id = -1;

            for(int i=0; i<n; i++)
            {
                if(pref[i] <= k)
                    id = i;
                else
                    break;
            }

            id++;

            if(id == n)
            {
                for(int i=0; i<s.length(); i++)
                    s[i] = 'a';
                cout<<s<<"\n";
            }
            else
            {
                char my_maxx;
                if(id != 0)
                {
                    my_maxx = s[id-1];
                    for(int i=0; i<id; i++)
                        my_maxx = max(s[i],my_maxx);
                    for(int i=0; i<n; i++)
                    {
                        if(s[i] <= my_maxx)
                            s[i] = 'a';
                    }
                }

                if(id != 0)
                    k -= pref[id-1];

                char z = s[id];
                char to = z - k;
                for(int i=id; i<n; i++)
                {
                    if(s[i] <= z && s[i] > to)
                        s[i] = to;
                }
                //cout<<"id = "<<id<<"maxx = "<<my_maxx<<"\n";
                cout<<s<<"\n";
            }
        }
        t--;
    }
    return 0;
}
