#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int f(int i)
{
    if(i%2 == 1)
        return 2;
    else
    {
        for(int j=3; j<=i; j++)
        {
            if(i%j != 0)
                return j;
        }
        return i+1;
    }
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

    lli sum=0;

    for(int i=1; i<=100; i++)
    {
        sum=0;
        for(int j=1;j<=i;j++)
            sum+=f(j);
        //cout<<i<<"\n";
        //cout<<sum<<"\n";
        cout<<"("<<i<<","<<sum<<")\n";
    }

    return 0;
}
