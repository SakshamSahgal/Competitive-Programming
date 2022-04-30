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
        cout<<v[i]+1<<" ";
    cout<<"\n------------------------\n";
}

bool is_good(vector<lli> &z)
{
    for(int i=0; i<z.size(); i++)
    {
        bool done[z.size()];
        memset(done,0,sizeof(done));
        lli cur = i;
        done[cur] = 1;
        cur = z[cur];

        while(cur != 0)
        {
            if(cur != 0 && done[cur] == 1)
                return 0;
            done[cur] = 1;
            cur = z[cur];
        }
        //cout<<"passed for i = "<<i<<"\n";
    }
    return 1;
}

lli c=0;

void fun(lli id,vector<lli> &a,lli k)
{
    if(id == k)
    {
        if(is_good(a))
        {
            //cout<<"passed ";
            c++;
            //vector_printer(a);
        }
        return;
    }
    for(int i=0;i<k;i++)
    {
        a[id] = i;
        fun(id+1,a,k);
    }
}

lli fast_Power(lli a,lli b,lli n)
{
    lli res = 1;
    while(b>0)
    {
        if((b&1) != 0) //b is odd
            res = ((res%n)*(a%n))%n;

        a = ((a%n)*(a%n))%n;
        b = b>>1; //b = b/2
    }
    return res;
}

lli mod = 1e9+7;
int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,k;
    cin>>n>>k;
    vector<lli> v(k);

    fun(0,v,k);


    lli g = fast_Power((n-k),(n-k),mod);

    lli ans = ((c%mod)*(g%mod))%mod;
    cout<<ans<<"\n";



    return 0;
}
