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
    usi k,n;
    cin>>n>>k;
    usi a[n];
    usi b[k];
    for(int i=0; i<n; i++)
        cin>>a[i];

    bool found=0;
    int c=0;
    for(usi i=0; i<n; i++)
    {
        found = 0;
        if(i>0)
        {
            for(int j=i-1; j>=0; j--)
            {
                if( a[i] == a[j] )
                {
                    found = 1;
                    goto x;
                }
            }

        }

        x:
        if(found == 0)
        {
            b[c] = i+1;
            c++;
        }

        if(c>=k)
            {
            break;
            }
    }

    if(c<k)
        cout<<"NO\n";
    else
        {
            cout<<"YES\n";
            for(usi i=0;i<k;i++)
               cout<<b[i]<<" ";
        }
    return 0;
}

