#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void printer(lli a[],lli b[],lli sa[],lli sb[],lli rsa[],lli rsb[],lli n)
{
    cout<<"\n-------------------------\n";
    cout<<"a->\n";
    for(int i=0; i<=(n+1); i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    cout<<"b->\n";
    for(int i=0; i<=(n+1); i++)
        cout<<b[i]<<" ";
    cout<<"\n";
    cout<<"sa->\n";
    for(int i=0; i<=(n+1); i++)
        cout<<sa[i]<<" ";
    cout<<"\n";
    cout<<"sb->\n";
    for(int i=0; i<=(n+1); i++)
        cout<<sb[i]<<" ";
    cout<<"\n";
    cout<<"rsa->\n";
    for(int i=0; i<=(n+1); i++)
        cout<<rsa[i]<<" ";
    cout<<"\n";
    cout<<"rsb->\n";
    for(int i=0; i<=(n+1); i++)
        cout<<rsb[i]<<" ";
    cout<<"\n-------------------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    lli n;
    cin>>n;
    lli a[n+2];
    lli b[n+2];
    lli sa[n+2];
    lli sb[n+2];
    lli rsa[n+2];
    lli rsb[n+2];

    a[0]=0;
    b[0]=0;
    a[n+1]=0;
    b[n+1]=0;

    for(int i=1; i<=n; i++)
        cin>>a[i]>>b[i];

    lli sum_a=0;
    lli sum_b=0;
    lli r_sum_a=0;
    lli r_sum_b=0;
    for(int i=0,j=n+1; i<=(n+1); i++,j--)
    {
        sum_a+=a[i];
        sum_b+=b[i];
        r_sum_a += a[j];
        r_sum_b += b[j];
        sa[i] = sum_a;
        sb[i] = sum_b;
        rsa[j] = r_sum_a;
        rsb[j] = r_sum_b;
    }

    for(int i=0; i<(n+1); i++)
    {
        if ( min( abs(sa[i] - rsb[i+1]), abs(sb[i] - rsa[i+1]) ) <= 500 )
        {
            if(  abs(sa[i] - rsb[i+1]) < abs(sb[i] - rsa[i+1]) )
            {
                for(int j=0; j<i; j++)
                    cout<<"A";

                for(int j=i; j<n; j++)
                    cout<<"G";
            }
            else
            {
                for(int j=0; j<i; j++)
                    cout<<"G";

                for(int j=i; j<n; j++)
                    cout<<"A";
            }
            break;
        }

    }

    //printer(a,b,sa,sb,rsa,rsb,n);
    return 0;
}

