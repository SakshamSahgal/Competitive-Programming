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
    bool all_a=1;
    for(int i = 0;i<s.size();i++)
        {
            if(s[i] != 'a')
                all_a = 0;
        }


    if(all_a == 1)
        cout<<"NO";
    else
        {
            cout<<"YES\n";
            int i = s.size()-1;
            int j = 0;

            k:
            if(s[i] == 'a')
            {
                i--;
                j++;
                goto k;
            }
            else
                {
                    for(int z=0;z<j;z++)
                        cout<<s[z];

                    cout<<'a';

                    for(int z=j;z<s.size();z++)
                        cout<<s[z];
                }
        }

    cout<<"\n";
    t--;
    }

return 0;
}

