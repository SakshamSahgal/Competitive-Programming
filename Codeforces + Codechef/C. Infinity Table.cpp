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

        lli k;
        cin>>k;
        lli x = ceil(sqrt(k));
        lli st = x*x -2*x + 2;
        lli st2 = x*x;
        //cout<<x<<" = "<<x<<"\n";
        for(lli i = st,j=1;j<= x;j++,i++)
            {
                if(i == k)
                {
                    cout<<j<<" "<<x<<"\n";
                   goto o;
                }

            }

        for(lli i = st2,j=1;j<=x;j++,i--)
            {
                if(k == i)
                {
                    cout<<x<<" "<<j<<"\n";
                    goto o;
                }

            }

        o:
        t--;
    }
    return 0;
}


