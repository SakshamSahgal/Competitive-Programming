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
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        map<lli,lli> freq;
        for(int i=0; i<n; i++)
        {
            lli x;
            cin>>x;
            freq[x]++;
        }
        lli sum=0;
        for(auto i=freq.begin();i!=freq.end();i++)
                sum += (i->second)*(n - i->second);

        cout<<sum<<"\n";


        t--;
    }


    return 0;
}
