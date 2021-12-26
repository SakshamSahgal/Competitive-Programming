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

lli calc(lli v,lli k)
{
    lli sum=v;
    lli temp = k;
    while( v/temp != 0 )
    {
        sum += v/temp;
        temp *= k;
    }
    return sum;
}

lli binary_search_it(lli n,lli k)
{
    lli st = 1;
    lli ed = n;
    lli mid;
    lli ans= INT_MAX;
    lli c;
    while(st<=ed)
    {
        mid =(st+ed)/2;
        c = calc(mid,k);
        if(c == n)
            return mid;
        else if(c < n)
            st = mid+1;
        else
        {
            ed = mid -1;
            ans = min(ans,mid);
        }
        //cout<<"searching = "<<mid <<" its value = "<<c<<" v till now =  "<<ans<<" its ans = "<<calc(ans,k)<<"\n";
    }
    return ans;
}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    lli n,k;
    cin>>n>>k;
    cout<<binary_search_it(n,k);


    return 0;
}


