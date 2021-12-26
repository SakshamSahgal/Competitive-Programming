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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    string x;
    for(int i=0; i<n; i++)
    {
        if(s[i] != '1' && s[i] != '0')
        {
            if(s[i] == '4')
            {
                x+='2';
                x+='2';
                x+='3';
            }
            else if(s[i] == '6')
            {
                x+='5';
                x+='3';
            }
            else if(s[i] == '8')
            {
                x+='7';
                x+='2';
                x+='2';
                x+='2';
            }
            else if(s[i] == '9')
            {
                x+='3';
                x+='3';
                x+='2';
                x+='7';
            }
            else
                x+=s[i];
        }
    }
    sort(x.begin(),x.end(),greater<int>());
    cout<<x<<"\n";
    return 0;
}


