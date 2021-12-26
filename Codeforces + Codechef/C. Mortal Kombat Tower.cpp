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

        for(int i=0; i<n; i++)
            cin>>a[i];

        lli c=0;
        lli i=0;
        lli ans=0;
        while(i < n)
        {
            if(c%2 == 0) //friend
            {
                if(  i+1 < n )
                {
                    if(a[i] == 0 && a[i+1] == 0)
                        i+=2;
                    else if(a[i] == 0 && a[i+1] == 1)
                        i++;
                    else if(a[i] == 1 && a[i+1] == 0)
                    {
                        ans++;
                        i+=2;
                    }
                    else
                    {
                        ans++;
                        i++;
                    }
                }
                else
                {
                    if(a[i] == 0)
                        i++;
                    else
                    {
                        ans++;
                        i++;
                    }
                }
            }
            else  //me
            {
                if(  i+1 < n )
                {
                    if(a[i] == 0 && a[i+1] == 0)
                        i+=1;
                    else if(a[i] == 0 && a[i+1] == 1)
                        i+=2;
                    else if(a[i] == 1 && a[i+1] == 0)
                        i++;
                    else
                        i+=2;
                }
                else
                    i++;
            }
            c++;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
