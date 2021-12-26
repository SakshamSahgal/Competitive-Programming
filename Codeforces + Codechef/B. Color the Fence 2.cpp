#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int v;
    cin>>v;
    string ans;
    int rem_paint = v;

    int a[10];
    int min_paint;
    int extra;
    int max_value_with_min_paint;
    bool aage_mila = 0;
    bool atleast_one_found=0;
    for(int i=1; i<=9; i++)
    {
        cin>>a[i];
        if(a[i] <= v)
            atleast_one_found = 1;
    }

    if(atleast_one_found == 0)
    {
        cout<<"-1\n";
        return 0;
    }
j:

    min_paint = INT_MAX;


    for(int i=9; i>=1; i--)
    {
        if( a[i] < min_paint )
        {
            min_paint = a[i];
            max_value_with_min_paint = i;
        }
    }

    if(min_paint > rem_paint)
        goto h;

    extra = rem_paint%min_paint;
    aage_mila = 0;
    for(int i = 9; i > max_value_with_min_paint ; i--)
    {
        if((min_paint + extra) >= a[i])
        {
            aage_mila = 1;
            ans += (i+48);
            rem_paint -= a[i];
            goto j;
        }
    }

    if(aage_mila == 0)
    {
        ans+= (max_value_with_min_paint+48);
        rem_paint -= min_paint;
        goto j;
    }


h:
    cout<<ans<<"\n";

    return 0;
}


