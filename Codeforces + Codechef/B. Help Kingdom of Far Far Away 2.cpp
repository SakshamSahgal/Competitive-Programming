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
    string s;
    cin>>s;

    int decimal_index=-1;
    int length_before_decimal;
    string intpart;

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '.')
            break;

        if(s[i] != '-')
            intpart+=s[i];
    }

    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '.')
        {
            decimal_index=i;
            break;
        }
    }

    if(s[0] == '-')
    {
        if(decimal_index != -1)
            length_before_decimal = decimal_index - 1;
        else
            length_before_decimal = s.length() - 1;

        cout<<"($";

        if(length_before_decimal <= 3)
        {
            for(int i=1; i<=length_before_decimal; i++)
                cout<<s[i];

            if(decimal_index != -1)
            {
                if( decimal_index + 2 < s.length() )
                    cout<<"."<<s[decimal_index+1]<<s[decimal_index+2]<<")";
                else
                {
                    if(decimal_index + 1 < s.length())
                        cout<<"."<<s[decimal_index+1]<<"0)";
                    else
                        cout<<".00)";
                }
            }
            else
                cout<<".00)";
        }
        else
        {
            vector<char> c;
            for(int i=intpart.length()-1,j=0; i>=0; i--,j++)
            {
                if((j-2)%3 != 0)
                    c.insert(c.begin(),intpart[i]);
                else
                {
                    if(i!= 0)
                    {
                        c.insert(c.begin(),intpart[i]);
                    c.insert(c.begin(),',');
                    }
                    else
                     c.insert(c.begin(),intpart[i]);

                }
            }

            for(int i=0; i<c.size(); i++)
                cout<<c[i];

            if(decimal_index != -1)
            {
                if( decimal_index + 2 < s.length() )
                    cout<<"."<<s[decimal_index+1]<<s[decimal_index+2]<<")";
                else
                {
                    if(decimal_index + 1 < s.length())
                        cout<<"."<<s[decimal_index+1]<<"0)";
                    else
                        cout<<".00)";
                }
            }
            else
                cout<<".00)";
        }
    }
    else
    {
        cout<<"$";

       vector<char> c;
            for(int i=intpart.length()-1,j=0; i>=0; i--,j++)
            {
                if((j-2)%3 != 0)
                    c.insert(c.begin(),intpart[i]);
                else
                {
                    if(i!= 0)
                    {
                        c.insert(c.begin(),intpart[i]);
                    c.insert(c.begin(),',');
                    }
                    else
                     c.insert(c.begin(),intpart[i]);

                }
            }

        for(int i=0; i<c.size(); i++)
                cout<<c[i];


        if(decimal_index != -1)
        {
            if( decimal_index + 2 < s.length() )
                cout<<"."<<s[decimal_index+1]<<s[decimal_index+2];
            else
            {
                if(decimal_index + 1 < s.length())
                    cout<<"."<<s[decimal_index+1]<<"0";
                else
                    cout<<".00";
            }
        }
        else
            cout<<".00";
    }

    return 0;
}


