#include<iostream>
#include<algorithm>
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
        int n;
        lli s;
        cin>>n>>s;
        lli sum=0;
        int gifts=0;;
        lli a[n];
        lli tot_sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            tot_sum+=a[i];
        }
        if(tot_sum <= s)
            cout<<0<<"\n";
        else
        {
            int maxi = 0;
            int index=0;
            for(int i=0; i<n; i++)
            {
                sum=0;
                gifts=0;
                for(int j=0; j<n; j++)
                {
                    if(i!=j)
                    {
                        if(sum+a[j] <= s)
                        {
                            sum +=a[j];
                            gifts++;
                        }
                        else
                            break;
                    }
                }
                //cout<<"sum = "<<sum<<" "<<"gifts = "<<gifts<<"\n";
                if(gifts>maxi)
                {
                    maxi = gifts;
                    index = i;
                }

            }
            cout<<index+1<<"\n";

        }

        t--;
    }

    return 0;
}

