#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

bool string_Compare(string s,string t)
{
    if(s.length() != t.length())
        return 0;
    else
    {
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != t[i])
            {
                //cout<<"Checking for "<<s[i]<<" \n";
                if(s[i] == '0' || s[i] == 'o' || s[i] == 'O')
                {
                    //cout<<"first condition\n";
                    if(t[i] != '0' && t[i] != 'o' && t[i] != 'O')
                        return 0;
                }
                else if(s[i] == 'l' || s[i] == 'L' || s[i] == 'I' || s[i] == 'i' || s[i] == '1')
                {
                    //cout<<"second condition\n";
                    if(t[i] != 'l' && t[i] != 'L' && t[i] != 'I' && t[i] != 'i' && t[i] != '1')
                    {
                        //cout<<"Returning 0\n";
                         return 0;
                    }

                }
                else
                {
                  //cout<<"Third condition\n";
                    if(s[i]>=97 && s[i]<=122) //small
                    {
                        if(t[i] != (s[i] - 32 ))
                            return 0;
                    }
                    else if(s[i] >= 65 && s[i]<=90) //capital
                    {
                        if(t[i] != (s[i] + 32 ))
                            return 0;
                    }
                    else
                    {
                        return 0;
                    }

                }
            }
        }
        return 1;
    }
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    string s;
    cin>>s;
    int n;
    cin>>n;
    string x;
    string ans;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        if(string_Compare(s,x) == 1)
        {
             ans= "No";
             //cout<<"Match found at "<<i<<"\n";
        }

    }

    if(ans != "No")
        ans = "Yes";

    cout<<ans<<"\n";
    return 0;
}
