#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
ulli Eular_GCD(ulli a,ulli b)
{
    ulli temp;
    if(a!=0 && b!=0)
    {
x:
        if(a == 0)
            return b;
        else if(b == 0)
            return a;
        else
        {
            temp = a;
            a = b;
            b = temp%b;
            goto x;
        }
    }
    else
        return max(a,b);
}

ulli LCM(ulli arr[],ulli n)
{
    ulli Ans=arr[0];

    for(int i=1; i<n; i++)
        Ans  = (Ans*arr[i])/(Eular_GCD(Ans,arr[i]));

    return Ans;
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    ulli n;
    cin>>n;
    ulli a[n];
    ulli max_limit;
    bool all_equal=1;
    double y;
    for(lli i=0; i<n; i++)
    {
        cin>>a[i];

        if(a[i]!= a[0])
            all_equal = 0;
    }

    if(all_equal == 1)
        cout<<"Yes\n";
    else
    {
        ulli lcm = LCM(a,n);
        //cout<<"lcm = "<<lcm<<"\n";
        bool possible=0;
        for(ulli i=0; i<n; i++)
        {
            possible = 0;
            //cout<<"i = "<<i<<": ";
            max_limit = (int)(log( (lcm/(a[i]*1.0)) )/log(2));
            //cout<<"Max limit = "<<max_limit<<"\n";
            for(ulli x=0; x<=max_limit; x++)
            {
                y = ( log( ( lcm / (a[i]*pow(2,x)*1.0) ) ) / log(3) );
                if( y == floor(y))
                {
                    //cout<<"Found at x = "<<x<<" y = "<<y<<" "<<a[i]<<"*"<<pow(2,x)<<"*"<<pow(3,y)<<" ans = "<<a[i]*pow(2,x)*pow(3,y)<<"\n";
                    possible = 1;
                    break;
                }

            }

            if(possible == 0)
                {
                cout<<"No\n";
                goto g;
                }

        }

    cout<<"Yes\n";
    }

    g:
    return 0;
}

