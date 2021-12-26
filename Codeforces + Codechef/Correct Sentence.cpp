#include<iostream>
#include<algorithm>
#include<vector>
#include <string>
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
        int k;
        cin>>k;
        string str;
        getline(cin, str);
        str = &str[0]+1;
        vector<string> s;
        string c;
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]!=' ')
            {
                c+=str[i];
            }
            else
            {
                s.push_back(c);
                c.clear();
            }

            if(i == str.size()-1)
            {
                s.push_back(c);
                c.clear();
            }
        }
      //cout<<"words = "<<s.size()<<"\n";
        bool check1=0;
        bool check2=0;
        for(int i=0; i<s.size(); i++)
        {
            check1=0;
            check2=0;

            if(s[i][0] >=97 && s[i][0] <=109)
                check1 = 1;
            else if(s[i][0] >=78 && s[i][0] <=90)
                check2 = 1;
            else
            {
                cout<<"NO\n";
                goto j;
            }

            for(int j=0; j<s[i].size(); j++)
            {
                if(check1 == 1)
                {
                    if(!(s[i][j] >=97 && s[i][j] <=109))
                    {
                        cout<<"NO\n";
                        goto j;
                    }
                }
               else
                {
                    if(!(s[i][j] >=78 && s[i][j] <=90))
                    {
                        cout<<"NO\n";
                        goto j;
                    }
                }
            }
        }
        cout<<"YES\n";
j:
        t--;
    }

    return 0;
}
