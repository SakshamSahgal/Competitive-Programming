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
    int x;
    cin>>x;

    if(x<40)
    cout<<(40-x)<<"\n";
    else if(x<70)
    cout<<(70-x)<<"\n";
    else if(x<90)
    cout<<(90-x)<<"\n";
    else
    cout<<"expert\n";


    return 0;
}
