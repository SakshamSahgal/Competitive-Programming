#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
        int y;
        cin>>y;
        if(y == 1)
            cout<<1<<"\n";
        else
        {
            double d = (-1 + sqrt((8*y)+17))/2.0;
           // cout<<d<<"\n";
            if(d - (int)d == 0)
                cout<<d<<"\n";
            else
            {
                int z = floor(d);
                if(  (((z*z) + z )/2.0) == y )
                    cout<<floor(d)<<"\n";
                else
                    cout<<ceil(d)<<"\n";
            }
        }
        t--;
    }

    return 0;
}
