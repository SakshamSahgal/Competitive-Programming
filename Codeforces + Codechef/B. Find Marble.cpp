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
    int n,s,t;
    cin>>n>>s>>t;
    int a[n+1];
    for(int i=1;i<=n;i++)
        cin>>a[i];

    if(s == t)
        cout<<0<<"\n";
    else
    {
        lli moves=0;
        int i = s;

        while(i!=t)
        {
            //cout<<"going from = "<<i<<" to "<<a[i]<<"\n";
            i = a[i];
            moves++;
            if(i == s)
            {
                cout<<"-1\n";
                goto h;
            }
        }

        cout<<moves<<"\n";
    }


    h:
    return 0;
}
