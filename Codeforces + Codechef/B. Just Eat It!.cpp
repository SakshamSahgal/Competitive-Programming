#include<iostream>
#include<algorithm>
#include<climits>
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
    usi t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli p[n];
        lli sum=0;
        for(lli i=0; i<n; i++)
        {
            cin>>a[i];
            sum+=a[i];
            p[i] = sum;
        }
        /*
        cout<<"\n------------\n";
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";
        cout<<"\nsum = "<<sum<<"\n";
        for(int i=0; i<n; i++)
            cout<<p[i]<<" ";
        cout<<"\n------------\n"; */
        lli prefix_max = INT_MIN;
        int max_i=0;
        int min_i=0;
        lli prefix_min = INT_MAX;
        for(int i=0; i<n; i++)
        {
            if(p[i] > prefix_max)
            {
                prefix_max = p[i];
                max_i = i;
            }
        }
        for(int i=0; i<max_i; i++)
        {
            if(p[i]<prefix_min)
            {
                prefix_min = p[i];
                min_i = i;
            }
        }


        if(max_i == 0)
            prefix_min=0;


       // cout<<"\n Prefix max = "<<prefix_max<<"max i = "<<max_i<<" prefix min = "<<prefix_min<<"Min i = "<<min_i<<"\n";
        if(max_i != (n-1))
        {
            if(prefix_min<0)
            {
                if( (prefix_max-prefix_min)>= sum)
                    cout<<"NO\n";
                else
                    cout<<"YES\n";
            }
            else
            {
                if( (prefix_max) >= sum )
                    cout<<"NO\n";
                else
                    cout<<"YES\n";
            }
        }
        else
        {
            if( (prefix_max-prefix_min) >= sum )
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }

        t--;
    }

    return 0;
}

