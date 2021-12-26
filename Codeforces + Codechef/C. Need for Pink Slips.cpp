#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

struct new_cmp
{
    double c;
    double m;
    double p;
};


struct new_cmp calculate_new_cmp(struct new_cmp x,char selected,double v)
{
    int noz = 0;
    if(x.c == 0)
        noz++;
    if(x.m == 0)
        noz++;
    if(x.p == 0)
        noz++;

    if(selected == 'c')
    {
        if(x.c != 0)
        {
            if(x.c <= v)
            {
                if(noz == 0)
                {
                    x.m += x.c/2.0;
                    x.p += x.c/2.0;
                    x.c = 0;
                }
                else if(noz == 1)
                {
                    if(x.m == 0)
                    {
                        x.p += x.c;
                        x.c = 0;
                    }
                    else
                    {
                        x.m += x.c;
                        x.c=0;
                    }
                }
                else
                {
                    x.c  = -1;
                    x.m  = -1;
                    x.p  = -1;
                    return x;
                }
            }
            else
            {
                x.c -=v;
                if(noz == 0)
                {
                    x.m += v/2.0;
                    x.p += v/2.0;
                }
                else if(noz == 1)
                {
                    if(x.m == 0)
                        x.p += v;
                    else
                        x.p += v;
                }
                else
                {
                    x.c  = -1;
                    x.m  = -1;
                    x.p  = -1;
                    return x;
                }
            }
        }
        else
        {
            x.c  = -1;
            x.m  = -1;
            x.p  = -1;
            return x;
        }
    }
    else if(selected == 'm')
    {
        if(x.m != 0)
        {
            if(x.m <= v)
            {
                if(noz == 0)
                {
                    x.c += x.m/2.0;
                    x.p += x.m/2.0;
                    x.m = 0;
                }
                else if(noz == 1)
                {
                    if(x.c == 0)
                    {
                        x.p += x.m;
                        x.m = 0;
                    }
                    else
                    {
                        x.c += x.m;
                        x.m = 0;
                    }
                }
                else
                {
                    x.c  = -1;
                    x.m  = -1;
                    x.p  = -1;
                    return x;
                }
            }
            else
            {
                x.m -= v;
                if(noz == 0)
                {
                    x.c += v/2.0;
                    x.p += v/2.0;
                }
                else if(noz == 1)
                {
                    if(x.c == 0)
                        x.p += v;
                    else
                        x.c += v;
                }
                else
                {
                    x.c  = -1;
                    x.m  = -1;
                    x.p  = -1;
                    return x;
                }
            }
        }
        else
        {
            x.c  = -1;
            x.m  = -1;
            x.p  = -1;
            return x;
        }
    }
    else
    {
        x.c  = 1;
        x.m  = 1;
        x.p  = 1;
        return x;
    }


    return x;

};

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

    struct new_cmp temp;
    temp.c = 0.2;
    temp.m = 0.2;
    temp.p = 0.6;

    temp = calculate_new_cmp(temp,'c',0.2);
    cout<<" - > "<<temp.c<<" "<<temp.m<<" "<<temp.p<<"\n";
    return 0;
}

