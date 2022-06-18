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


void Hanoi(int n,int st,int ed)
{
    if(n == 1)
        cout<<st<<" "<<ed<<"\n";
    else
    {
        int other = 6 - (st + ed);
        Hanoi(n-1,st,other);
        cout<<st<<" "<<ed<<"\n";
        Hanoi(n-1,other,ed);
    }
    return;
}

int main()
{
    int n;
    cout<<"Enter the No of rings in the Tower of HANOI : ";
    cin>>n;
    cout<<"No of steps to be Followed are : \n";
    Hanoi(n,1,3);
    return 0;
}
