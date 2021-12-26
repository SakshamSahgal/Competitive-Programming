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
        lli a[n];
        lli ogcd=0;
        lli egcd=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(i%2 == 0)
                egcd = __gcd(egcd,a[i]);
            else
                ogcd = __gcd(ogcd,a[i]);
        }

        bool div=0;
        for(int i=0; i<n; i+=2)
        {
            if(!(a[i]%ogcd))
            {
                div = 1;
                break;
            }
        }

        if(div == 1)
        {
            div = 0;
            for(int i=1; i<n; i+=2)
            {
                if(!(a[i]%egcd))
                {
                    div = 1;
                    break;
                }
            }

            if(div == 0)
                cout<<egcd<<"\n";
            else
                cout<<"0\n";
        }
        else
            cout<<ogcd<<"\n";
        t--;
    }
    return 0;
}
