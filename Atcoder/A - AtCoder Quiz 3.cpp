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

int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    if(n <= 9)
        cout<<"AGC00"<<n<<"\n";
    else if(n<=41)
        cout<<"AGC0"<<n<<"\n";
    else
        cout<<"AGC0"<<n+1<<"\n";
    return 0;
}
