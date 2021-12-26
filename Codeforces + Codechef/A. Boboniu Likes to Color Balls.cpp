#include<iostream>
#include<algorithm>
#include<vector>
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
        int r,g,b,w;
        cin>>r>>g>>b>>w;
        lli noe=0;
        lli noo=0;
        lli noz=0;

        if(r%2 == 0)
            noe++;
        else
            noo++;

        if(g%2 == 0)
            noe++;
        else
            noo++;

        if(b%2 == 0)
            noe++;
        else
            noo++;

        if(r == 0)
            noz++;

        if(g == 0)
            noz++;

        if(b == 0)
            noz++;

        if(w%2 == 1)
        {
            if(noe == 3)
                cout<<"YES\n";
            else if(noe == 2)
                cout<<"NO\n";
            else if(noe == 1)
            {
                if(noz == 0)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }
            else
                cout<<"YES\n";
        }
        else
        {
            if(noe == 3)
                cout<<"YES\n";
            else if(noe == 2)
                cout<<"YES\n";
            else if(noe == 1)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
        t--;
    }

    return 0;
}

