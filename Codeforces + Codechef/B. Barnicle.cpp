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

    string s;
    cin>>s;
    lli ei = s.find("e");
    int pow = stoi(s.substr(ei+1));
    //cout<<"{ "<<ei<<" , "<<pow<<"} \n";
    s.erase(s.find("."),1);
    s.erase(s.find("e"));

    if( 1 + pow < s.length())
    {
        bool all_z=1;
        for(int i=1+pow; i<s.length(); i++)
            if(s[i] != '0')
                all_z = 0;

        if(all_z)
        {
            s.insert(1+pow,".");
            s.erase(s.find("."));
        }
        else
            s.insert(1+pow,".");
    }

    else if(1 + pow > s.length())
    {
        int z = s.length();
        for(lli i=1; i<=(1 + pow - z); i++)
            s += "0";
    }
    cout<<s<<"\n";
    return 0;
}
