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

lli no_of_bits_req(string from,string to)
{
    lli c=0;
    for(int i=0;i<7;i++)
    {
        if(from[i] == '1' && to[i] == '0')
            return -1;

        if(from[i] == '0' && to[i] == '1')
            c++;
    }
    return c;
}


int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

        lli n,k;
        cin>>n>>k;
        map<string,char> m;
        map<lli,string> m2;
        m2[0] = "1110111";
        m2[1] = "0010010";
        m2[2] = "1011101";
        m2[3] = "1011011";
        m2[4] = "0111010";
        m2[5] = "1101011";
        m2[6] = "1101111";
        m2[7] = "1010010";
        m2[8] = "1111111";
        m2[9] = "1111011";

        m["1110111"] = '0';
        m["0010010"] = '1';
        m["1011101"] = '2';
        m["1011011"] = '3';
        m["0111010"] = '4';
        m["1101011"] = '5';
        m["1101111"] = '6';
        m["1010010"] = '7';
        m["1111111"] = '8';
        m["1111011"] = '9';
        string s;

        for(int i=0;i<n;i++)
        {
            string temp;
            cin>>temp;

            line_printer(20);
            for(int j=0;j<=9;j++)
                cout<<" moves req to make "<<j<<" = "<<no_of_bits_req(temp,m2[j])<<"\n";
            line_printer(20);

        }
        cout<<"\n my string  = "<<s<<"\n";

    return 0;
}

