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




void swap(vector<lli>& arr, lli i, lli j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

lli indexOf(vector<lli> &arr, lli ele)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == ele)
            return i;
    }
    return -1;
}

lli minSwaps(vector<lli> arr, lli N)
{
    lli ans = 0;
    vector<lli> temp(arr.begin(), arr.end());
    sort(temp.begin(), temp.end());

    for (int i = 0; i < N; i++)
    {

        if (arr[i] != temp[i])
        {
            ans++;
            swap(arr, i, indexOf(arr, temp[i]));
        }
    }
    return ans;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> a(n);

        for(int i=0; i<n; i++)
            cin>>a[i];

        lli z = minSwaps(a, n);
        cout<<3*z<<"\n";
        t--;
    }
    return 0;
}
