#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
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
        lli n,k;
        cin>>n>>k;
        lli a[n];
        lli sum=0;
        double maxx = INT_MIN;
        lli s=0;
        lli pmax=0;
        for(int i=0;i<n;i++)
            cin>>a[i];

        sum+=a[0];
        bool inf_req=0;
        for(int i=1;i<n;i++)
            {
                double inf = ((a[i]*1.0)/sum);
                //cout<<setprecision(20)<<"inflation coff = "<<inf<<"\n";

                if(inf > (k/100.0) )
                    inf_req = 1;


                if(inf > maxx)
                {
                    maxx = inf;
                    s = sum;
                    pmax=a[i];
                }

                sum+=a[i];

            }

        if(inf_req == 1)
        {
            if( (pmax*100)%k == 0)
               cout<<setprecision(6)<<(pmax*100)/k - s<<"\n";
            else
                cout<<setprecision(6)<<(pmax*100)/k - s + 1<<"\n";
        }

        else
            cout<<0<<"\n";
        t--;
    }
    return 0;
}


