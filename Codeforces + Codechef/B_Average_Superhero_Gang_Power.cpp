#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
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

long double rem_avg(long double s, int i, long double rem, lli a[])
{
    return ((s - (long double)a[i]) / ((rem - 1) * (1.0)));
}

long double inc_avg(long double s, int i, long double rem, lli a[])
{
    return ((s + 1) / (rem * 1.0));
}

int main()
{
    // GO_FAST
    // freopen("input.txt", "r", stdin);
    // freopen("myout.txt", "w", stdout);

    lli n, k, m;
    cin >> n >> k >> m;
    lli M = m;
    lli a[n];
    long double s = 0;
    long double avg;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }

    bool khatam = 0;
    avg = s / (n * 1.0);
    sort(a, a + n);

    int i = 0;
    long double rem = n;
    int kk = k;

    long double arr[n+1] = {0.0};

    arr[n] = (s + min((long double)m,(rem*k)))/rem; //no delete & all inc 
    for (int i = 0; i < min(n,M); i++)
    {
        s -= a[i];
        rem--;
        m--;
       arr[i] = max ( s/rem  , (s + min((long double)m,(rem*k)))/rem);
    }
    //array_printer(arr,n+1);

    for(int i=0;i<=n;i++)
        avg = max(avg,arr[i]);
    cout << setprecision(20) << avg << "\n";

    return 0;
}