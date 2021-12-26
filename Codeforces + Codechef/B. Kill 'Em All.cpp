#include<iostream>
#include<cmath>
#include<climits>
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
    int q;
    cin>>q;
    while(q)
    {
        int n,r;
        cin>>n>>r;
        int a[n];
        int maxi = INT_MIN;
        int second_max = INT_MIN;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] > maxi)
                maxi = a[i];
        }
        if(n>=2)
        {
            for(int i=0; i<n; i++)
                if(a[i] != maxi && a[i] > second_max)
                    second_max = a[i];
        }

        cout<<"maximum = "<<maxi<<"Second mAXIMUM = "<<second_max<<"\n";
        if(n == 1)
            cout<<1<<"\n";
        else
        {
            if(second_max%r != 0)
            {
                int y = second_max/r;
                if(y == 0)
                    cout<<1<<"\n";
                else
                   {
                       if(y>n)
                        cout<<n<<"\n";
                       else
                        cout<<y<<"\n";
                   }
            }
            else
                {
                    int y = second_max/r;
                    if(y>n)
                        cout<<n<<"\n";
                    else
                        cout<<y<<"\n";

                }
        }

        q--;
    }

    return 0;
}

