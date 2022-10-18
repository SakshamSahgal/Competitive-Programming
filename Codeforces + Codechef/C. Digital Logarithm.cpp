#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

lli nod(lli x)
{
    lli d=0;
    while(x != 0)
    {
        x/=10;
        d++;
    }
    return d;
}

void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
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
        lli n;
        cin>>n;
        lli a[n];
        lli b[n];
        lli c=n;
        lli ans=0;
        map<lli,lli> fa;
        map<lli,lli> fb;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            fa[a[i]]++;
        }
        for(int i=0; i<n; i++)
        {
            cin>>b[i];
            fb[b[i]]++;
        }

        for(auto &&i:fa)
        {
            while(i.second != 0 && fb[i.first] != 0) //if present in both a and b
            {
                i.second--; //removing from a
                fb[i.first]--; //removing from b
                //cout<<"erasing "<<i.first<<" from both\n";
                c--;
            }
        }

        if(c != 0)
        {
            map<lli,lli> tfa;
            map<lli,lli> tfb;
            for(auto &&i:fa)
            {
                if(i.second != 0)
                {
                    if(i.first >= 10) //if more than one digit
                    {
                        //cout<<"converting in a "<<i.second<<" , "<<i.first<<" to "<<nod(i.first)<<"\n";
                        ans += i.second;
                        tfa[nod(i.first)] += i.second;
                    }
                    else
                        tfa[i.first] += i.second;
                }
            }
            fa = tfa;
            for(auto &&i:fb)
            {
                if(i.second != 0)
                {
                    if(i.first >= 10) //if more than 1 digit
                    {
                        //cout<<"converting in b "<<i.second<<" , "<<i.first<<" to "<<nod(i.first)<<"\n";
                        ans += i.second;
                        tfb[nod(i.first)] += i.second;
                    }
                    else
                        tfb[i.first] += i.second;
                }
            }
            fb = tfb;

            for(auto &&i:fa)
            {
                while(i.second != 0 && fb[i.first] != 0) //if present in both a and b
                {
                    i.second--;
                    fb[i.first]--;
                    //cout<<"erasing "<<i.first<<" from both\n";
                    c--;
                }
            }

            if(c != 0)
            {
                for(auto i:fa)
                {
                    if(i.first != 1)
                        ans += i.second;
                }
                for(auto i:fb)
                {
                    if(i.first != 1)
                        ans += i.second;
                }
            }
        }

        cout<<ans<<"\n";
        t--;
    }


    return 0;
}
