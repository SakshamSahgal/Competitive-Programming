#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

lli flip_bits(lli x)
{
lli temp = ceil(log(x)/log(2));
lli temp2 = (pow(2,temp)-1);
return (x&temp2);
}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int t;
cin>>t;
while(t)
    {
    lli n;
    cin>>n;
    lli x[n];
    lli y[n];
    for(int i=0;i<n;i++)
    {
        cin>>x[i];
        y[i] = flip_bits(x[i]);
    }

    //y[0]=0;

    for(int i=0;i<n;i++)
        cout<<y[i]<<" ";
    cout<<"\n";
    t--;
    }

return 0;
}
