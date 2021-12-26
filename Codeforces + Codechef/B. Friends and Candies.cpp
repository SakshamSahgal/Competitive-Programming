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
        int a[n];
        lli sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }

        double avg = (sum*1.0)/n;

        if( ( avg - (int)avg ) == 0 )
        {
            int k=0;
            for(int i=0;i<n;i++)
                {
                    if(a[i] > avg)
                        k++;
                }
            cout<<k<<"\n";
        }
        else
            cout<<"-1\n";
    t--;
    }

    return 0;
}

