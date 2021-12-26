#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

lli fast_Power(lli a,lli b,lli n)
{
    lli res = 1;
    while(b>0)
    {
        if((b&1) != 0) //b is odd
            res = ((res%n)*(a%n))%n;

        a = ((a%n)*(a%n))%n;
        b = b>>1; //b = b/2
    }
    return res;
}


void array_printer(lli n, lli x[])
{
    cout<<"\n----------\n";
    for(int i=1; i<=n; i++)
        cout<<x[i]<<" ";
    cout<<"\n----------\n";
}


void array_printer_char(lli n, char x[])
{
    cout<<"\n----------\n";
    for(int i=1; i<=n; i++)
        cout<<x[i]<<" ";
    cout<<"\n----------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    lli n,k;
    cin>>n>>k;
    lli a[n+1];
    char cc[n+1];
    for(int i=1; i<=n; i++)
    {
        a[i] = k;
        cc[i] = '-';
    }


    lli prefix_sum_L[n+1];
    lli prefix_sum_R[n+1];


    for(lli i=1; i<=k; i++)
    {
        char x;
        lli y;
        cin>>x>>y;
        if(x == 'L')
            cc[y] = 'L';
        else
            cc[y] = 'R';
    }
    if(k == n)
        cout<<1<<"\n";
    else
    {
        lli sumL=0;
        lli sumR=0;
        for(int i=1,j=n; i<=n; i++,j--)
        {
            if(cc[j] == 'L')
                sumL++;
            if(cc[i] == 'R')
                sumR++;

            prefix_sum_R[i] = sumR;
            prefix_sum_L[j] = sumL;
        }


        //array_printer_char(n,cc);
        //array_printer(n,prefix_sum_L);
        //array_printer(n,prefix_sum_R);

        for(int i=1; i<=n; i++)
        {
            if(cc[i] == '-')
            {
                a[i]-=(prefix_sum_L[i] + prefix_sum_R[i]);
            }
            else
            {
                a[i] = 1;
            }
        }
       // array_printer(n,a);
        lli multiplier = 1;
        for(int i=1; i<=n; i++)
        {
            multiplier *= (a[i]%998244353);
            multiplier = multiplier%998244353;
        }
        cout<<multiplier%998244353<<"\n";
    }


    return 0;
}

