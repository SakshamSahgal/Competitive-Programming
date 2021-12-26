#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
/*
int factors_printer(int n)
{
    int no_of_factors=1;
    if(n!=1)
    {
        for(int i=1; i<=(n/2); i++)
        {
            if(n%i ==0)
            {
                no_of_factors++;
                //cout<<i<<" ";
            }

        }

    }
    //cout<<n<<" ";
    return no_of_factors;
} */
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    usi t;
    cin>>t;
    int x;
    while(t)
    {
        for(int i=1; i<=2000; i++)
        {
            cout<<i*i<<"\n";
            cout << flush;
            cin>>x;
            if(x == 0)
                continue;
            else if(x == 1)
                goto h;
            else if(x == -1)
             return 0;

        }

        h:
        t--;
    }

    return 0;
}

