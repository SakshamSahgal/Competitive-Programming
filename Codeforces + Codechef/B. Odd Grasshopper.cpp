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
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli x,n;
        cin>>x>>n;
        if(x%2 == 0)
        {
            if(n%4 == 0)
                cout<<x<<"\n";
            else if(n%4 == 1)
                cout<<x - n<<"\n";
            else if(n%4 == 2)
                cout<<x+1<<"\n";
            else
                cout<<x+ n + 1<<"\n";
        }
        else
        {
            if(n%4 == 0)
                cout<<x<<"\n";
            else if(n%4 == 1)
                cout<<x + n<<"\n";
            else if(n%4 == 2)
                cout<<x-1<<"\n";
            else
                cout<<x - n - 1<<"\n";
        }


        t--;
    }
    return 0;
}
