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
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        lli d=0;

        for(int i=1; i<n; i++)
        {
            if(s[i] == s[i-1])
                d+=2;
            else
                d+=1;
        }
        // cout<<d<<"\n";
        int q;
        for(int i=0; i<k; i++)
        {
            cin>>q;
            q--;

            if(n == 1)
            {
                cout<<0<<"\n";
            }
            else
            {
                if(q != 0 && q!= (n-1))
                {
                    if( (s[q-1] == '0' && s[q] == '0' && s[q+1] == '0') || (s[q-1] == '1' && s[q] == '1' && s[q+1] == '1') )
                        d-=2;
                    else if( (s[q-1] == '1' && s[q] == '0' && s[q+1] == '1') || (s[q-1] == '0' && s[q] == '1' && s[q+1] == '0') )
                        d+=2;
                }
                else
                {
                    if(q == 0)
                    {
                        if( (s[q] == '0' && s[q+1] == '1') || (s[q] == '1' && s[q+1] == '0') )
                            d+=1;
                        else
                            d-=1;
                    }
                    else
                    {
                        if( (s[q] == '0' && s[q-1] == '1') || (s[q] == '1' && s[q-1] == '0') )
                            d+=1;
                        else
                            d-=1;
                    }
                }
                if(s[q] == '0')
                    s[q] = '1';
                else
                    s[q] = '0';
                cout<<d<<"\n";
            }

        }
        t--;
    }

    return 0;
}

