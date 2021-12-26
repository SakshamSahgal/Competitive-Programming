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
int arr[39801] = {0};
int main()
{
    GO_FAST
    lli a,b,c,d;
    cin>>a>>b;
    cin>>c>>d;

    for(int i=b;i<=39800;i+=a)
        arr[i] = 1;

    for(int i=d;i<=39800;i+=c)
    {
        if(arr[i] == 1)
        {
            cout<<i<<"\n";
            goto p;
        }
    }
    cout<<"-1\n";
    p:
    return 0;
}
