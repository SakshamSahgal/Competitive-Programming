#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<unordered_map>
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
        int n,a,b;
        cin>>n>>a>>b;
        lli ans=0;
        string s;
        cin>>s;
        auto str = unique(s.begin(),s.end());
        string x = string(s.begin(), str);
        int n1 = x.length();
        //cout<<x<<"\n";
        if(n1 == 1)
        cout<<max( n*(a+b), (n*a + b ))<<"\n";
        else
        cout<<max( n*(a+b), (n*a + (n1/2 + 1)*b ))<<"\n";
        t--;
    }
    return 0;
}

