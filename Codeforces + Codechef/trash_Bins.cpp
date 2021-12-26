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
    for(int k=1; k<=t; k++)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;
        lli prefix[n];
        lli postfix[n];
        lli last=-1;
        lli alast=-1;
        for(int i=0,j=n-1; i<n; i++,j--)
        {
            if(s[i] == '1')
                last = i;

            if(s[j] == '1')
                alast = j;

            prefix[i] = last;
            postfix[j] = alast;
        }

        /*
        for(int i=0; i<n; i++)
            cout<<prefix[i]<<" ";
        cout<<"\n";
        for(int i=0; i<n; i++)
            cout<<postfix[i]<<" ";
        cout<<"\n"; */

        lli sum=0;
        for(int i=0; i<n; i++)
        {
            if(s[i] == '0')
            {
                if(prefix[i] != -1 && postfix[i] != -1)
                    sum += min(abs(i-prefix[i]),abs(i-postfix[i]));
                else
                {
                    if(prefix[i] != -1 && postfix[i] == -1)
                        sum += abs(i-prefix[i]);
                    else
                        sum += abs(i-postfix[i]);
                }

            }

        }
        cout<<"Case #"<<k<<": "<<sum<<"\n";
    }

    return 0;
}
