#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
bool is_vovel(char ch)
    {
    if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
        return 1;
    else
        return 0;
    }
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
string s,t;
cin>>s>>t;
if(s.length() == t.length())
    {

    for(usi i=0;i<s.length();i++)
        {
            if(is_vovel(s[i]) != is_vovel(t[i]))
                {
                cout<<"NO\n";
                goto x;
                }
        }
    cout<<"YES\n";
    }
else
    cout<<"NO\n";
x:

return 0;
}

