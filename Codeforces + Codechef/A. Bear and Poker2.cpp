#include<iostream>
#include<algorithm>
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
    bool all_equal=1;
    bool possible=0;
    for(ulli i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]!= a[0])
            all_equal = 0;
    }

    if(all_equal == 1)
        cout<<"Yes\n";
    else
    {
        ulli z;
        ulli lcm = LCM(a,n);
        for(ulli i=0; i<n; i++)
        {
            possible = 0;
            z = (lcm/a[i]);
           // cout<<"i = "<<i<<" : ";
            if(z == 1)
            {
                possible = 1;
                goto l;
            }
            else
            {
f:
                if(z%6 == 0)
                {
                    z/=6;
                    if(z == 1)
                    {
                        possible = 1;
                        goto l;
                    }
                    goto f;
                }

                else if(z%3 == 0)
                {
                    z/=3;
                    if(z == 1)
                    {
                        possible = 1;
                        goto l;
                    }
                    goto f;
                }

                else if(z%2 == 0)
                {
                    z/=2;
                    if(z == 1)
                    {
                        possible = 1;
                        goto l;
                    }
                    goto f;

                }
                else
                {
                    possible = 0;
                    goto l;
                }
l:
                if(possible == 0)
                {
                    cout<<"No\n";
                    goto k;
                }


            }


        }
        cout<<"Yes\n";
    }

k:
    return 0;
}

