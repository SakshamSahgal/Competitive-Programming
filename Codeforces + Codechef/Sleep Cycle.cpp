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
    lli t;
    cin>>t;
    while(t)
    {
        lli h,l;
        cin>>l>>h;
        vector<lli> z;
        bool first_time=0;
        string s;
        cin>>s;
        for(int i=0; i<l; i++)
        {
            if(s[i] == '0')
            {
                if(first_time == 0)
                {
                    first_time = 1;
                    z.push_back(1);
                }
                else
                    z[z.size()-1]++;
            }
            else
                first_time = 0;
        }

        bool done=0;

        for(int i=0; i<z.size(); i++)
        {
            //cout<<z[i]<<" ";
            if( h <= z[i] )
            {
                cout<<"YES\n";
                done=1;
                break;
            }
            else
                h = 2*(h - z[i]);
        }

        if(done == 0)
            cout<<"NO\n";
        z.clear();
        t--;
    }

    return 0;
}

