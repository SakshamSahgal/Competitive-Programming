#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
/*
cout<<"         and   or\n";
for(int i=1;i<=50;i++)
{
    //cout<<"\n-----------------------------\n";
    for(int j=1;j<=50;j++)
    {
        //cout<<i<<" "<<j<<" "<<(i&j)<<" "<<(i^j)<<"    "<<<<"\n";
        if( (i&j) >= (i^j) )
        cout<<"("<<i<<","<<j<<") \n";
    }

    ///cout<<"\n-----------------------------\n";
}*/

int t;
cin>>t;
while(t)
{
    lli n;
    cin>>n;
    lli a[n];
    lli group_no;
    map<lli,lli> m;
    lli sum=0;
    for(lli i=0;i<n;i++)
    {
        cin>>a[i];
        group_no = floor(log(a[i])/log(2));
        m[group_no]++;
    }

    for(auto i = m.begin();i!=m.end();i++)
        sum += ((i->second)*(i->second-1))/2;

    cout<<sum<<"\n";
    t--;
}

return 0;
}
