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
    int n;
    lli d;
    cin>>n>>d;
    lli x[n];
    lli j;
    for(lli i=0; i<n; i++)
        scanf("%lli",&x[i]);
    lli sum = 0;
    for(lli i=0; i<(n-2); i++)
    {
        if(i == 0)
        {
            for(j=(n-1); j>=(i+2); j--)
            {
               // cout<<"checking i = "<<x[i]<<" j = "<<x[j]<<" diff = "<<(x[j] - x[i])<<"\n";
                if( (x[j] - x[i]) <= d )
                {
                    //cout<<"i = "<<x[i]<<" j = "<<x[j]<<"\n";
                    sum += ((j-i-1)*(j-i))/2;
                    break;
                }
                if(j == (i+2))
                    break;
            }
        }
        else
        {
            if(j<(i+2))
            {

                if( (j+1)>(n-1))
                    goto x;
                else
                {
                   // cout<<"aaiya\n";
                    j++;
                    //cout<<"now j = "<<j<<"\n";
                }

            }

            for(; j<n; j++)
            {

               // cout<<"///checking i = "<<x[i]<<" j = "<<x[j]<<" diff = "<<(x[j] - x[i])<<"\n";
                if(x[j] - x[i] > d)
                {
                    if(j>(i+2))
                    {
                        j--;
                        break;
                    }
                    else
                        break;
                }
                if(j == (n-1))
                    break;
            }

            if(j<0)
                j=0;

            if(j>=n)
                j=(n-1);
            if( (x[j] - x[i]) <= d )
            {
               // cout<<"i = "<<x[i]<<" j = "<<x[j]<<"\n";
                sum += ((j-i-1)*(j-i))/2;
            }

        }

    }
x:
    cout<<sum<<"\n";
    return 0;
}
