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
using namespace std;
lli sod(lli n)
{
    lli sum=0;
    while(n!=0)
    {
        sum += n%10;
        n/=10;
    }
    return sum;
}
map<lli,lli> ans;
lli n=1;
lli x=1;
void precalc()
{

    while( x <= 10000  )
    {
        //cout<<"trying = "<<n<<" "<<sod(n)<<"\n";
        if(sod(n) == 10)
        {
            ans[x] = n;
            //cout<<n<<"\n";
            x++;
        }
        n++;
    }

}



int main()
{
    GO_FAST
    precalc();
    lli k;
    cin>>k;
    cout<<ans[k]<<"\n";
    return 0;
}
