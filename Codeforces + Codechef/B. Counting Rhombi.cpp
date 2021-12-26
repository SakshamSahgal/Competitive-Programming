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
    lli w,h;
    cin>>w>>h;
    if(w<2 || h<2)
        cout<<0<<"\n";
    else
    {
        lli sum=0;
        for(int i=h;i>=2;i--)
            {
                   sum += (i/2)*( w*(w/2) - (((w/2))*(2 + ((w/2)-1)*2  ) )/2);
            }
        cout<<sum<<"\n";
    }



    return 0;
}


