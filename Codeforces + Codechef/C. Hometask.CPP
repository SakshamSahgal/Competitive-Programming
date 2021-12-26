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
    int k;
    cin>>k;
    map<char,char> m;
    for(int i=0; i<k; i++)
    {
        char x,y;
        cin>>x>>y;
        m[x] = y;
        m[y] = x;
    }
    int ans = 0;
    bool found=0;

    do
    {
        found = 0;
        for(int i=0; i<(s.length()-1); i++)
        {
            if( m[s[i]] == s[i+1] )
            {
                found=1;
                cout<<"found at index = "<<i<<" "<<i+1<<"\n";
                int peeche=0;
                int aage=0;

                for(int j=i; j>=0; j--)
                {
                    if(s[j] == s[i])
                        peeche++;
                    else
                        break;
                }

                for(int j=i+1; j<s.length(); j++)
                {
                    if(s[j] == s[i+1])
                        aage++;
                    else
                        break;
                }

                if(peeche < aage)
                {
                    for(int j=0,k=i; j<peeche; j++,k--)
                        s[k] = '-';
                }
                else
                {
                    for(int j=0,k=i+1; j<aage; j++,k++)
                        s[k] = '-';
                }

                cout<<"peeche = "<<peeche<<" aage = "<<aage<<"\n";

                ans+= min(peeche,aage);
                break;
            }
        }

        string temp;

        for(int i=0;i<s.length();i++)
        {
            if(s[i] != '-')
                temp += s[i];
        }

        s = temp;
        cout<<"string now = "<<s<<"\n";
    }
    while(found == 1);
    cout<<ans<<"\n";
    return 0;
}


