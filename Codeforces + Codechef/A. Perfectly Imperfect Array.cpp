#include<iostream>
#include<algorithm>
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
usi t;
cin>>t;
while(t)
    {
    int n;
    cin>>n;
    int a[n];
    double temp;
    bool found = 0;
    for(int i=0;i<n;i++)
        {
        cin>>a[i];
        temp = sqrt(a[i]);
        if( (temp - (int)temp) != 0 )
            found = 1;
        }
        if(found == 1)
            cout<<"YES\n";
        else
            {
                cout<<"NO\n";
            }


    t--;
    }

return 0;
}

