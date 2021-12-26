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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    usi n;
    cin>>n;
    usi a[n];
    vector <usi> v;
    for(usi i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i] == 1)
            v.push_back(i);
    }
    if(v.size() == 0)
        cout<<0<<"\n";
    else if(v.size() == 1)
        cout<<1<<"\n";
    else
    {
        lli sum=1;
        for(usi i=0; i<(v.size()-1); i++)
           sum *= (v[i+1] - v[i]);
        cout<<sum<<"\n";
    }
    return 0;
}

