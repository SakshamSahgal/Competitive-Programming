#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
const int mx = 10000000;
int a[mx+1] = {0};

void seive()
{
    a[1] = 0;
    int c=0;
    for(lli i=2; i<=mx; i++)
    {
        if(i*i>mx)
        {
            break;
        }

        if(a[i] != 1)
        {
            // c++;
            //  a[i] = c;
            for(lli j = i*i; j<=mx; j+=i)
                if(a[j] == 0)
                    a[j] = 1;

        }

    }

    for(int i=2; i<=mx; i++)
    {
        if(a[i] == 0)
            c++;

        a[i] = c;
    }

   // for(int i=1; i<=mx; i++)
       // cout<<i<<" "<<a[i]<<"\n";

    //cout<<i<<" "<<a[i]<<"\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    seive();
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        if(n == 2)
            cout<<1<<"\n";
        else if(n == 3)
            cout<<2<<"\n";
        else
            cout<<a[n] - a[n/2] + 1<<"\n";
        t--;
    }
    return 0;
}

