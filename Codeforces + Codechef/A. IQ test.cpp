#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    usi n;
    cin>>n;
    int a[n];
    for(usi i=0; i<n; i++)
        cin>>a[i];
    int noo=0;
    int noe=0;

    for(usi i=0; i<3; i++)
    {
        if(a[i]%2 == 0)
            noe++;
        else
            noo++;
    }

    if(noo > noe)
    {
        for(usi i=0; i<n; i++)
        {
            if(a[i]%2 == 0)
                cout<<(i+1)<<"\n";
        }
    }
    else
    {
        for(usi i=0; i<n; i++)
        {
            if(a[i]%2 == 1)
                cout<<(i+1)<<"\n";
        }

    }
    return 0;
}

