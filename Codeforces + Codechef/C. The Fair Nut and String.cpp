    #include<bits/stdc++.h>
    #define lli long long int
    #define ld long double
    #define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    // basic debugging macros
    lli __i__,__j__;
    lli inf = 9e18;
    #define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
    #define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
    #define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
    using namespace std;
    typedef pair<lli,lli> pll;

    lli mod = 1e9+7;


    int main()
    {
        //GO_FAST
        //freopen("input.txt", "r", stdin);
        //freopen("myout.txt", "w", stdout);
        string s;
        cin>>s;
        vector<lli> z;
        lli c=0;

        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == 'a')
                c++;
            else if(s[i] == 'b' && c != 0)
            {
                z.push_back(c);
                c=0;
            }
        }

        if(c != 0)
            z.push_back(c);

        if(z.size() ==  0)
            cout<<0<<"\n";
        else
        {
            lli ans=1;
            for(auto i:z)
              ans = ((ans%mod)*((i+1)%mod))%mod;
            cout<<(ans-1)<<"\n";
        }

        return 0;
    }

