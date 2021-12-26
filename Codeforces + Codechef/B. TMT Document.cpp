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
    usi t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        int sum_t=0;
        int sum_m=0;
        int sum_tb=0;
        int T[n];
        int M[n];
        int TB[n];
        for(int i=0; i<n; i++)
        {
            if(s[i] == 'T')
                sum_t++;

            if(s[i] == 'M')
                sum_m++;

            if(s[n-1-i] == 'T')
                sum_tb++;

            T[i] = sum_t;
            M[i] = sum_m;
            TB[n-1-i] = sum_tb;
        }

        if(sum_t != ((2*n)/3) || sum_m != (n/3) || s[0] != 'T' || s[n-1] != 'T')
            cout<<"NO\n";
        else
        {

            cout<<"\n";
            for(int i=0; i<n; i++)
                cout<<T[i]<<" ";
            cout<<"\n";
            for(int i=0; i<n; i++)
                cout<<M[i]<<" ";
            cout<<"\n";
            for(int i=0; i<n; i++)
                cout<<TB[i]<<" ";
            cout<<"\n";

            for(int i=1; i<(n-1); i++)
            {
               if(s[i] == 'M')
                {
                    if(M[i]>T[i-1] || M[i]<TB[i+1] )
                    {
                        cout<<"NO\n";
                        goto x;
                    }
                }
            }
            cout<<"YES\n";

        }

x:
        t--;
    }
    return 0;
}

