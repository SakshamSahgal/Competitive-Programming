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
        int n;
        cin>>n;
        lli d[n+1];
        for(int i=1;i<=n;i++)
                cin>>d[i];

        sort(d+1,d+n+1);

        if(n<=2)
            cout<<0<<"\n";
        else
        {
            lli a=0,b=0,s=0;
            for(int i=1,j=n;i<=(n-1);i++,j--)
                {
                    a += (n-i)*d[i];
                    b += (n-i)*d[j];
                    s += d[i+1] - d[i];
                }
            //cout<<s<<"<- s\n";
            //cout<<a<<"<- a \n";
            //cout<<b<<"<- b \n";
            cout<<(s + (a-b))<<"\n";
        }

        t--;
    }
    return 0;
}


