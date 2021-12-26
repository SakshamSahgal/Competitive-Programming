#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n,k;
        cin>>n>>k;
        lli p[n];

        for(int i=0;i<n;i++)
               cin>>p[i];

        lli sum=p[0];
        lli x=0;
        lli maxx = INT_MIN;
        for(int i=1;i<n;i++)
        {
            double inf = p[i]/((sum)*(1.0));
            //cout<<inf<<" ";
            if( inf > (k/100.0) )
                x = ceil( ( (p[i])*(100.0) )/k ) - sum;
            else
                x = 0;

            sum+=p[i];
            maxx = max(x,maxx);
            //cout<<"x = "<<x<<"\n";
        }
        cout<<maxx<<"\n";
        t--;
    }
    return 0;
}


