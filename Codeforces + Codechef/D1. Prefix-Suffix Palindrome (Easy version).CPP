#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
lli inf = 9e18;

bool is_palindrome(string &s)
{
    for(int i=0; i<s.length()/2; i++)
    {
        if(s[i] != s[s.length()-i-1])
            return 0;
    }
    return 1;
}

string largest_palindrome_prefix(string &s)
{
    lli n = s.length();
    string temp;
    string maxx;
    for(int i=0; i<n; i++)
    {
        temp += s[i];
        if(is_palindrome(temp))
            maxx = temp;
    }
    return maxx;
}

string largest_palindrome_suffix(string &s)
{
    lli n = s.length();
    string temp;
    string maxx;
    for(int i=n-1; i>=0; i--)
    {
        temp += s[i];
        if(is_palindrome(temp))
            maxx = temp;
    }
    return maxx;
}


int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;

        if(is_palindrome(s))
            cout<<s<<"\n";
        else
        {
            lli maxx = -1;
            for(int i=0; i<s.length()/2; i++)
            {
                if(s[i] != s[s.length()-i-1])
                    break;
                else
                    maxx = i;
            }

            lli st = maxx + 1;
            lli ed = s.length() - maxx - 2;
           // cout<<"st = "<<st<<" ed = "<<ed<<"\n";

            string x;

            for(int i=st; i<=ed; i++)
                x += s[i];

            string s1 = largest_palindrome_prefix(x);
            string s2 = largest_palindrome_suffix(x);

            for(int i=0; i<st; i++)
                cout<<s[i];

            if(s1.length() > s2.length())
                cout<<s1;
            else
                cout<<s2;

            for(int i=ed+1;i<s.length();i++)
                cout<<s[i];
            cout<<"\n";
        }
        t--;
    }
    return 0;
}
