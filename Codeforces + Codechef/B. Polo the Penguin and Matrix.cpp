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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,m,d;
    cin>>n>>m>>d;
    int a[n*m];
    for(int i=0; i<n*m; i++)
        cin>>a[i];

    lli sum=0;

    sort(a,a+(n*m));
    if( (n*m)%2 == 1)
    {
        int median = a[(n*m)/2];
        for(int i=0; i<(n*m); i++)
        {
            lli x = abs(a[i]- median);
            sum += x;
            if(x%d != 0)
            {
                cout<<"-1\n";
                return 0;
            }
        }
        cout<<(sum/d)<<"\n";
    }
    else
    {
        bool one_failed = 0;
        bool second_failed = 0;
        lli sum1=0;
        int median1 = a[(n*m)/2];
        for(int i=0; i<n*m; i++)
        {
            lli x = abs(a[i]- median1);
            sum1 += x;
            if(x%d != 0)
            {
                one_failed = 1;
                break;
            }
        }

        //cout<<"one failed = "<<one_failed<<"\n";

        lli sum2=0;
        int median2 = a[(n*m)/2 - 1];

        for(int i=0; i<(n*m); i++)
        {
            lli x = abs(a[i]- median2);
            sum2 += x;
            if(x%d != 0)
            {
                second_failed = 1;
                break;
            }
        }

        //cout<<"second failed = "<<second_failed<<"\n";

        if(one_failed == 1 && second_failed == 1)
            cout<<"-1\n";
        else
        {
            if(one_failed == 1)
                cout<<sum2/d<<"\n";
            else if(second_failed == 1)
                cout<<sum1/d<<"\n";
            else
                cout<<min((sum2/d),(sum1/d))<<"\n";
        }

    }
    return 0;
}

