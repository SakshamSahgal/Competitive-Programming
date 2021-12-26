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
    usi t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        lli a[n];
        lli maxi = INT_MAX;
        lli mini = INT_MAX;
        bool all_inc=1;
        bool all_Dec=1;
        int max_i=0;
        int min_i=0;
        bool all_Equal=1;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i]>maxi)
            {
                maxi = a[i];
                maxi = i;
            }

            if(a[i] < mini)
            {
                mini = a[i];
                min_i = i;
            }
        }

        for(i=0; i<(n-1); i++)
        {
            if(a[i+1]>a[i])
                all_Dec = 0;
            else
                all_inc = 0;
            if(a[i] != a[i+1])
                all_Equal = 0;
        }

        if(n == 1 || all_Dec == 1 || all_inc == 1)
            cout<<"YES\n";
        else
        {
            if(a)
            if(max_i<min_i)
            {



            }




        }



        t--;
    }

    return 0;
}
