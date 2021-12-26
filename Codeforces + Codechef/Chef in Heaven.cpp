#include<iostream>
#include<algorithm>
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
    int t;
    cin>>t;
    while(t)
    {
        int l;
        cin>>l;
        string s;
        cin>>s;
        int y=1;
        int g=0;
        for(int i=0; i<l; i++)
        {
            if(s[i] == '1')
                g++;

            if(y%2 == 0)
            {
                if(g>=(y/2))
                {
                    cout<<"YES\n";
                    goto x;
                }
            }
            else
            {
                if(g>=(y/2+1))
                {
                    cout<<"YES\n";
                    goto x;
                }
            }
            y++;
        }
        cout<<"NO\n";
x:
        t--;
    }

    return 0;
}

