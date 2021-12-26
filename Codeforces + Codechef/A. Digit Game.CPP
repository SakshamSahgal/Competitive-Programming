#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        lli opo=0;
        lli ope=0;
        lli epo=0;
        lli epe=0;

        for(int i=0; i<n; i++)
        {
            if( (i+1)%2 == 0) //pos is even
            {
                if( (s[i] - 48)%2 == 0 )
                    epe++;
                else
                    epo++;
            }
            else
            {
                if( (s[i] - 48)%2 == 0 )
                    ope++;
                else
                    opo++;
            }
        }

o:
        if(ope + opo + epe + epo > 1)
        {
            if(ope > 0 )
                ope--;
            else if(opo > 0)
                opo--;
            else
            {
                if(ope> 0 || epe > 0)
                    cout<<2<<"\n";
                else
                    cout<<1<<"\n";

                goto k;
            }
            if(ope + opo + epe + epo > 1)
            {
                if(epo > 0)
                    epo--;
                else if(epe > 0)
                    epe--;
                else
                {
                    if(ope> 0 || epe > 0)
                        cout<<2<<"\n";
                    else
                        cout<<1<<"\n";

                    goto k;
                }
            }
            else
            {
                if(ope> 0 || epe > 0)
                    cout<<2<<"\n";
                else
                    cout<<1<<"\n";
                goto k;
            }

        }
        else
        {
            if(ope> 0 || epe > 0)
                cout<<2<<"\n";
            else
                cout<<1<<"\n";
            goto k;
        }

        goto o;
k:
        t--;
    }
    return 0;
}
