#include<iostream>
#define ulli unsigned long long int
#define usi unsigned int
using namespace std;
int prime(ulli n)
{
if(n==1)
    return 0;
else
    {
    for(ulli i=2;i<=(n/2);i++)
        if(n%i==0)
            return 0;

        return 1;
    }
}





int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned int t;
cin>>t;
while(t--)
    {
        ulli x,y;
        cin>>x>>y;
        bool checker = 0;
        for(ulli i=2;i<=x;i++)
            {
                //cout<<"I this time = "<<i<<"\n";
                if( (prime(i) == 1) && ((x-y)%i == 0) )
                    {
                        checker = 1;
                        cout<<"YES\n";
                        break;
                    }
            }

            if(checker == 0)
                cout<<"NO\n";
    }



return 0;
}
