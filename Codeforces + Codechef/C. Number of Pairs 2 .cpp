#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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
        lli n,l,r;
        cin>>n>>l>>r;
        lli a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        sort(a,a+n);

        //cout<<"\n----------------\n";
        //for(int i=0; i<n; i++)
        //    cout<<a[i]<<" ";
       // cout<<"\n----------------\n";

        bool in=0;
        lli u = n-1;
        lli c=0;
        lli new_u=n-1;
        for(int i=0;i<n; i++)
        {
           // cout<<"Checking for = "<<a[i]<<"\n";
            in = 0;

            for(int j=i+1; j<=u; j++)
            {
               // cout<<"i = "<<i<<" j = "<<j<<"\n";
                if( (a[i]+a[j])>=l && (a[i]+a[j])<=r )
                {
                    in = 1;
                   // cout<<"found = "<<a[i]<<" "<<a[j]<<"\n";
                    c++;
                    new_u = j;
                }
                else if( in == 1 && (!((a[i]+a[j])>=l && (a[i]+a[j])<=r)) )
                    break;
            }
            u = new_u;
        }

        cout<<c<<"\n";
        t--;
    }
    return 0;
}

