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
        sort(a,a+n);

        lli i=0;
        lli c=0;
        while(i < n)
        {
            lli j = i;
            lli l = j-i+1;
            //cout<<"\ni = "<<i<<" j = "<<j<<" ";
            while( j < n && a[j] > l)
            {
                j++;
                if(j == n)
                {
                    j--;
                    break;
                }
                else
                  l = j-i+1;
                //cout<<" j = "<<j<<" ";
            }
            //cout<<"\n";
            if(a[j] <= l)
                c++;

            i = j+1;
        }

        cout<<c<<"\n";
        t--;
    }
    return 0;
}
