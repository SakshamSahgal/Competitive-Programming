#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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
    lli n;
    cin>>n;
    lli a[n];
    map<lli,lli> freq;
    for(int i=0;i<n;i++)
        {
        cin>>a[i];
        a[i] = a[i] - i;
        freq[a[i]]++;
        }
    lli sum=0;
    for(auto ptr = freq.begin();ptr!=freq.end();ptr++)
        sum+=(((ptr->second)*(ptr->second - 1))/2);

    cout<<sum<<"\n";
    t--;
    }
return 0;
}

