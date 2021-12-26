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
        lli n;
        cin>>n;
        char a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        n = unique(a, a + n) - a;

        if(n == 1)
            cout<<"SAHID\n";
        else if(n == 2)
            cout<<"RAMADHIR\n";
        else
        {
            if( (n-2)%3 == 0)
                cout<<"RAMADHIR\n";
            else
                cout<<"SAHID\n";
        }
        t--;
    }
    return 0;
}
