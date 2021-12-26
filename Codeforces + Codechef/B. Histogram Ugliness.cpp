#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void printer(int a[],int n)
{
    cout<<"\n-------------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n-------------------\n";
}

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
        int a[n];
        lli sum1=0;
        lli sum2=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(i==0)
                sum1+=a[i];
            if(i == n-1)
                sum1+=a[i];

            if(i>0)
                sum1+=abs(a[i]-a[i-1]);
        }

        //cout<<sum1<<"\n";
        lli moves = 0;

        if(n == 1)
        {
            cout<<a[0]<<"\n";
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                if(i == 0)
                {
                    if( (i+1) < n && a[i+1] < a[i] )
                    {
                        moves += (a[i] - a[i+1]);
                        a[i] = a[i+1];
                    }
                }
                else if( i == n-1)
                {
                    if(a[i] > a[i-1] && (i-1)>=0 )
                    {
                        moves += (a[i] - a[i-1]);
                        a[i] = a[i-1];
                    }
                }
                else
                {
                    if(a[i] > a[i-1] && a[i] > a[i+1] )
                    {
                        moves += a[i] - max(a[i-1],a[i+1]);
                        a[i] = max(a[i-1],a[i+1]);
                    }
                }
            }

            //printer(a,n);
            //cout<<"Moves = "<<moves<<"\n";

            for(int i=0; i<n; i++)
            {
                if(i==0)
                    sum2+=a[i];
                if(i == n-1)
                    sum2+=a[i];

                if(i>0)
                    sum2+=abs(a[i]-a[i-1]);
            }
            cout<<min(sum1,sum2+moves)<<"\n";
        }

        t--;
    }

    return 0;
}


