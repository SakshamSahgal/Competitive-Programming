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
    lli a,b;
    cin>>a>>b;
    //zif(a!=b)
    cout<<(lli)pow((lli)32,(a-b))<<"\n";
    return 0;
}
