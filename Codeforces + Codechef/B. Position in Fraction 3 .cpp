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
    lli a,b,c;
    cin>>a>>b>>c;
    if(a<b)
    {
        bool first_time = 1;
        lli k=0;
        //cout<<".";
x:
        a*=10;
        z:
        if(a<b)
        {
            //cout<<0;
            k++;
            if(c == 0)
            {
                cout<<k;
                return 0;
            }
            a*=10;
            if(first_time == 1)
            goto z;
            else
            goto x;

        }
        //cout<<(a/b);
        first_time = 0;
        k++;

        if((a/b) == c)
        {
            cout<<k;
            return 0;
        }

        a=a%b;
        if(a == 0)
        {
            //cout<<0;
            k++;
            if((a/b) == c)
            {
                cout<<k;
                return 0;
           }
            else
             {
                cout<<"-1\n";
                return 0;
             }

        }
        else
            {
           if(k>100000)
           {
            cout<<"-1\n";
            return 0;
            }
            else
            goto x;
            }

    }
    else if(a == b)
    {
        //cout<<".0";
        if(c == 0)
            cout<<1;
        else
            cout<<"-1\n";
    }
    else
    {
       // cout<<".";
        lli k=0;
        a = a%b;

y:
        a*=10;
        if(a<b)
        {
            //cout<<0;
            k++;
            if(c == 0)
            {
                cout<<k;
                return 0;
            }
            a*=10;
            goto y;
        }
        //cout<<(a/b);
        k++;
        if((a/b) == c)
            {
                cout<<k;
                return 0;
            }
        a=a%b;
        if(a == 0)
        {
            cout<<0;
            k++;
            if((a/b) == c)
            {
                cout<<k;
                return 0;
            }
            else
                {
                cout<<"-1\n";
                return 0;
                }

        }
        else
            {
            if(k>100000)
                {
                cout<<"-1\n";
                return 0;
                }
             goto y;
            }

    }
    return 0;
}

