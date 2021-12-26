#include<iostream>
#include<algorithm>
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
    for(int i=0;i<s.size();i++)
        {

            if(i%2 == 0)
            {
                //alice
                if(s[i] == 'a')
                        s[i] ='b';
                else
                    s[i] = 'a';
            }
            else
                {
                    if(s[i] == 'z')
                        s[i] = 'y';
                    else
                        s[i] = 'z';
                }
        }

    cout<<s<<"\n";
    t--;
    }

return 0;
}

