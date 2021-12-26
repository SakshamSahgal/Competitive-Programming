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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    string s;
    cin>>s;
    int noq=0;
    int nos=0;
    int k;
    cin>>k;
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '?')
            noq++;
        else if(s[i] == '*')
            nos++;
    }

    int min_length = s.length() - 2*noq - 2*nos;
    if(k<min_length)
        cout<<"Impossible"<<"\n";
    else
    {
        if(nos == 0)
        {
            int max_length = s.length() - noq;
            if(k>max_length)
                cout<<"Impossible"<<"\n";
            else
            {
                int char_to_Remove = max_length - k;

                for(int i=0; i<(s.length()-1); i++)
                {
                    if(s[i+1] == '?')
                    {
                        if(char_to_Remove > 0)
                        {
                            char_to_Remove--;
                        }
                        else
                        {
                            cout<<s[i];
                        }
                    }
                    else
                    {
                        if(s[i]!='?')
                            cout<<s[i];
                    }

                }
                if(s[s.length()-1] != '?')
                    cout<<s[s.length()-1]<<"\n";
            }
        }
        else
        {
            int min_length_except_one = s.length() - 2*noq - 2*(nos-1);
            int char_to_add = k - min_length;
            bool star_found = 0;
            for(int i=0; i<(s.length()-1); i++)
            {
               if(s[i] != '?' && s[i] != '*')
               {
                   if(s[i+1] == '*' && star_found == 0)
                    {
                        star_found = 1;
                        for(int j=0;j<char_to_add;j++)
                            cout<<s[i];
                    }
                    else
                    {

                            if(s[i+1] != '*' && s[i+1] != '?')
                            cout<<s[i];

                    }

               }
            }
             if(s[s.length()-1] != '?' && s[s.length()-1] != '*')
                    cout<<s[s.length()-1]<<"\n";
        cout<<"\n";
        }
    }
    return 0;
}

