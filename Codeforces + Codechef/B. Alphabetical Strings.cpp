#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

bool continuity_check(int freq[],char maxx)
{

    for(int i = (maxx-97); i>=0; i--)
    {
        if(freq[i]!=1)
            return 0;
    }
    return 1;
}

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
        int freq[26] = {0};
        char maxx = 'a';
        int index[26] = {0};
        for(int i=0; i<s.length(); i++)
        {
            freq[(s[i]-97)]++;
            index[(s[i]-97)] = i;
            if(s[i] > maxx)
                maxx = s[i];
        }

        /*
        cout<<maxx<<"\n";

        cout<<"\n---------------------------\n";
        for(int i=0; i<26; i++)
        {
            cout<<i<<" "<<freq[i]<<"\n";
        }

        for(int i=0; i<26; i++)
        {
            cout<<i<<" "<<index[i]<<"\n";
        }
        cout<<"\n---------------------------\n"; */

        if(continuity_check(freq,maxx) == 1)
        {
            if(s.length() == 1)
                cout<<"YES\n";
            else
            {
                int r=index[0];
                int l=index[0];

                for(int i=1; i<=(maxx-97); i++)
                {
                    //cout<<s[index[i]]<<" at ";
                    if(index[i] == r+1 || index[i] == l-1)
                    {
                        if(index[i] == r+1)
                        {
                            //cout<<s[index[i]]<<" at right\n";
                            r++;
                        }
                        else
                        {
                            //cout<<s[index[i]]<<" at left\n";
                            l--;
                        }

                    }
                    else
                    {
                        cout<<"NO\n";
                        goto k;
                    }
                }
                cout<<"YES\n";
            }

        }
        else
            cout<<"NO\n";
k:
        t--;
    }

    return 0;
}


