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

//remember to use endl instead of \n for interactive problems.


void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int sum_btw(vector<int> &ps,int l,int r)
{
    if(l == 0)
        return ps[r];
    else
        ps[r] - ps[l-1];
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    cin>>n;
    vector<char> a(n);
    vector<int> ps(n,0);
    int s=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i] == 'p')
            s++;
        ps[i] = s;
    }

    vector_printer(ps);
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(a[i] == 't')
        {
            if(i == 0)

        }
    }

    return 0;
}

