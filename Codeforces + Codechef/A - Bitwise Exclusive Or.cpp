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
    int a,b;
    cin>>a>>b;

    for(int i=0;i<=255;i++)
    {
        if( (a^i) == b )
        {
           cout<<i;
            break;
        }

    }

    return 0;
}

