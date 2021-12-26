#include<iostream>
#include<algorithm>
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
    usi t;
    cin>>t;
    while(t)
    {
        int n,r;
        cin>>n>>r;
        int a[n];
        int b[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=0; i<n; i++)
            cin>>b[i];

        if(n == 1)
        {
            cout<<b[0]<<"\n";
        }
        else
        {
            lli x=0;
            lli maxi=0;
            for(int i=0; i<n; i++)
            {

                if(i == 0)
                    {
                    x+=b[i];
                    //cout<<x<<" ";
                    if(x>maxi)
                        maxi = x;
                    }


                else
                    {

                        x-= r*(a[i]-a[i-1]);
                        if(x<0)
                            x=0;
                        x+=b[i];
                        //cout<<x<<" ";
                        if(x>maxi)
                            maxi = x;
                    }
            }

        cout<<maxi<<"\n";
        }

        t--;
    }

    return 0;
}

