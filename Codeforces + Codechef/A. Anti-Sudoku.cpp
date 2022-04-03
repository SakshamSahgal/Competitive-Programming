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

void change(vector<string> &s,lli i,lli j)
{
    if(s[i][j] == '1')
        s[i][j] = '2';
    else
        s[i][j] = '1';
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        vector<string> s(9);

        for(int i=0;i<9;i++)
            cin>>s[i];

        change(s,0,0);
        change(s,1,3);
        change(s,2,6);

        change(s,3,1);
        change(s,4,4);
        change(s,5,7);

        change(s,6,2);
        change(s,7,5);
        change(s,8,8);

        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
                cout<<s[i][j];
            cout<<"\n";
        }


        t--;
    }
    return 0;
}
