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
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        int a[n];
        bool not_sorted = 0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] != (i+1))
                not_sorted = 1;
        }
        if(not_sorted == 0)
            cout<<0<<"\n";
        else
        {

            if(a[0] == n && a[n-1] == 1)
                cout<<3<<"\n";
            else
            {

                    if(a[n-1] == 1)
                        cout<<2<<"\n";
                    else
                    {
                        if(a[n-1] == n)
                            cout<<1<<"\n";
                        else
                        {
                            if(a[0] == 1)
                                cout<<1<<"\n";
                            else
                                cout<<2<<"\n";
                        }
                    }

            }
        }
    t--;
    }
    return 0;
}
