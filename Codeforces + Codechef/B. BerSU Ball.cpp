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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n;
cin>>n;
usi a[n];
for(usi i=0;i<n;i++)
    cin>>a[i];

usi m;
cin>>m;
usi b[m];

for(usi i=0;i<m;i++)
    cin>>b[i];

sort(a,a+n);
sort(b,b+m);
/*cout<<"\n--------------------\n";
for(usi i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n--------------------\n";
for(usi i=0;i<m;i++)
    cout<<b[i]<<" ";
cout<<"\n--------------------\n"; */
usi pairs=0;

for(usi i=0;i<n;i++)
    {
        for(usi j=0;j<m;j++)
            {
                if( (b[j] != 0) && ( abs(a[i] - b[j])<=1 ) )
                    {
                    pairs++;
                    //cout<<a[i]<<" "<<b[j]<<"\n";
                    b[j] = 0;
                    break;
                    }
            }
    }
cout<<pairs<<"\n";
return 0;
}

