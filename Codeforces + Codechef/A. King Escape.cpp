#include<iostream>
#include<algorithm>
#include<vector>
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
    int n;
    cin>>n;
    int ax,ay,bx,by,cx,cy;
    cin>>ax>>ay;
    cin>>bx>>by;
    cin>>cx>>cy;

    if(bx>ax && by<ay && cx>ax && cy<ay)
        cout<<"YES\n";
    else if(bx>ax && by>ay && cx>ax && cy>ay)
        cout<<"YES\n";
    else if(bx<ax && by>ay && cx<ax && cy>ay)
        cout<<"YES\n";
    else if(bx<ax && by<ay && cx<ax && cy<ay)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}


