#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        int a[n+1] = {0};
        int k=1;
        bool chala=0;

        for(int i=2; i<=n; i+=2)
            a[i] = k;

        for(int i=3; i<=n; i+=2)
        {
            if((i*2)<=n)
            {
                a[i] = k;
                for(int j=i*i; j<=(i*(n/i)); j+=i)
                {
                    a[j] = k;
                }
            }
            else
            {
                if(a[i] == 0)
                {
                    k++;
                    a[i] = k;
                }
            }
        }

        /*
        for(int i=2; i<=n; i++)
        {
            cout<<"i = "<<i<<" set no = "<<a[i]<<"\n";
        } */
        cout<<k<<"\n";
        t--;
    }

    return 0;
}

