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


pair<lli,lli> get_no(lli n)
{
    lli n1 = n;
    lli n2 = n;
    lli no2=0;
    lli no5=0;

    while(n1 && (n1%2 == 0))
    {
        n1/=2;
        no2++;
    }

    while(n2 && (n2%5 == 0))
    {
        n2/=5;
        no5++;
    }
    pair<lli,lli> p;
    p.first = no2;
    p.second = no5;
    return p;
}


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    pair<lli,lli> x;
    vector<vector<lli>> v(3,vector<lli>(1000001));
    vector<lli> y;
    map<lli,lli> f;
    for(lli i=0; i<=1000000; i++)
    {
        x = get_no(i);
        //cout<<" i = "<<i<<" {"<<x.first<<" "<<x.second<<"} \n";
        if(i == 0)
        {
            v[0][i] = x.first;
            v[1][i] = x.second;
            v[2][i] = min(v[0][i],v[1][i]);
        }
        else
        {
            v[0][i] = x.first + v[0][i-1];
            v[1][i] = x.second + v[1][i-1];
            v[2][i] = min(v[0][i],v[1][i]);
        }
        y.push_back(v[2][i]);
        f[v[2][i]]++;
    }
    //line_printer(20);
    //array_2d_printer(v,3,10000);
    //line_printer(20);
    //cout<<v[0][500000]<<" "<<v[1][500000]<<" "<<v[2][500000]<<"\n";
    lli m;
    cin>>m;

    if(f[m] != 0)
    {
        auto ptr = lower_bound(y.begin(),y.end(),m);
        lli index = ptr - y.begin();
        lli myf = f[m];
        cout<<myf<<" \n";
        for(int i=index,k=0;k<myf;k++,i++)
            cout<<i<<" ";
        cout<<"\n";
    }
    else
        cout<<0<<"\n";


    return 0;
}

