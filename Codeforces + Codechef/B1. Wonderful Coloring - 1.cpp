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
int t;
cin>>t;
while(t)
    {
    string s;
    cin>>s;
    map<char,int> freq;
    for(int i=0;i<s.length();i++)
        freq[s[i]]++;

    lli c=0;
    for(auto i = freq.begin();i!= freq.end();i++)
    {
        if( i->second >= 2)
            c+=2;
        else
            c+=1;
    }

    cout<<c/2<<"\n";

    t--;
    }

return 0;
}
