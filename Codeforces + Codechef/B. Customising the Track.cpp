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
        lli n;
        cin>>n;
        lli a[n];
        lli sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
        }

        //cout<<sum<<"\n";
        if(sum%n == 0)
            cout<<"0\n";
        else
        {
            if(sum > n)
            {
                lli x = sum/n;
                lli y  = sum - x*(n-1);
                lli d = y-x;
                    cout<<(lli)(n-d)*d<<"\n";
            }
            else
                cout<<(lli)sum*(n-sum)<<"\n";
        }

        t--;
    }
    return 0;
}

