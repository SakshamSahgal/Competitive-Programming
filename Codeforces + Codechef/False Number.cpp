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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        if(s[0]!='1')
            cout<<1<<s<<"\n";
        else
        {
            cout<<s[0]<<"0";
            for(int i=1;i<s.length();i++)
            cout<<s[i];
            cout<<"\n";
        }
        t--;
    }

    return 0;
}

