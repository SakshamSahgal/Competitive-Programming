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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        vector<int> C;
        vector<int> S;
        vector<int> N;

        for(int i=0; i<s.size(); i++)
        {
            if(s[i] >= 65 && s[i]<=90)
                C.push_back(i);
            else if(s[i] >= 97 && s[i] <= 122)
                S.push_back(i);
            else
                N.push_back(i);
        }

        if(C.size() == 0 || N.size() == 0 || S.size() == 0)
        {
            if(C.size() == 0 && N.size() == 0)
            {
                s[S[0]] = 'A';
                s[S[1]] = '1';
            }
            else if(C.size() == 0 && S.size() == 0)
            {
                s[N[0]] = 'A';
                s[N[1]] = 'a';
            }
            else if(N.size() == 0 && S.size() == 0)
            {
                s[C[0]] = '1';
                s[C[1]] = 'a';
            }
            else
            {
                if(C.size() == 0)
                {
                    if(N.size() > S.size())
                        s[N[0]] = 'A';
                    else
                        s[S[0]] = 'A';

                }
                else if(S.size() == 0)
                {
                    if(N.size() > C.size())
                        s[N[0]] = 'a';
                    else
                        s[C[0]] = 'a';
                }
                else
                {
                    if(S.size() > C.size())
                        s[S[0]] = '1';
                    else
                        s[C[0]] = '1';
                }
            }
            cout<<s<<"\n";
        }
        else
            cout<<s<<"\n";

        t--;
    }

    return 0;
}
