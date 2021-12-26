#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    usi n,q;
    cin>>n>>q;
    char s[n];
    for(usi i=0;i<n;i++)
        cin>>s[i];

    while(q--)
        {
            int l,r;
            cin>>l>>r;
            if(r<=(n-1))
                {
                 for(int i=r;i<n;i++)
                    {
                     if(s[i] == s[r-1])
                        {
                            cout<<"YES\n";
                            goto x;
                        }
                    }
                }

            if((l-2)>=0)
                {
                    for(int i=l-2;i>=0;i--)
                    {
                    if(s[i] == s[l-1])
                        {
                            cout<<"YES\n";
                            goto x;
                        }
                    }
                }
            cout<<"NO\n";
            x:
            l=l;
        }

    }


return 0;
}
