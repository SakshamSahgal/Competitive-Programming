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
        int s,i,e;
        cin>>s>>i>>e;
        if(e == 0)
        {
            if(s>i)
                cout<<1<<"\n";
            else
                cout<<0<<"\n";
        }

        else
        {
            if( (i+e-s)>=0 )
            {
                if(  ( e - ((i+e-s)/2) ) >= 0)
                    cout<< ( e - ((i+e-s)/2) )<<"\n";
                else
                    cout<<0<<"\n";
            }
                else
                    cout<<e+1<<"\n";
        }
        t--;
    }

    return 0;
}
