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
        lli p1=0;
        lli p2=0;
        lli m1=0;
        lli m2=0;
        lli found=0;
        lli s=0;
        lli no=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            s += a[i];
            if(a[i]%3 != 0)
            {
                found = 1;
                no++;
                lli y = ( a[i] - (a[i]/3)*3);
                // cout<<-y<<"\n";
                if(  y == 1 )
                {
                    m1++;
                    p2++;
                }
                else if(y == 2)
                {
                    m2++;
                    p1++;
                }
            }
        }
        if(found == 0)
            cout<<0<<"\n";
        else
        {
            if(s%3 != 0)
                cout<<-1<<"\n";
            else
            {
                // cout<<m1<<" "<<p2<<" "<<m2<<" "<<p1<<"\n";
                 cout<< min(m1,p1) + 2*(max(m1,p1) - min(m1,p1))/3<<"\n";
            }

        }
        t--;
    }
    return 0;
}
