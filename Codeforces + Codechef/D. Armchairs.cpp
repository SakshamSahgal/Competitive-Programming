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
    int n;
    cin>>n;
    int a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    int ro=-1;
    int lo=-1;
    lli sum=0;
    for(int i=0; i<n; i++)
    {
        ro=-1;
        lo=-1;
        if(a[i] == 1)
        {
            cout<<"\n-------------------------\n";
            cout<<"i = "<<i<<"\n";
            //right 0
            for(int j=i+1; j<n; j++)
            {
                if(a[j] == 0)
                {
                    ro=j;
                   cout<<"right 0 found at = "<<j<<"\n";
                    break;
                }
            }

            //left 0
            for(int j=i-1; j>=0; j--)
            {
                if(a[j] == 0)
                {
                    lo=j;
                 cout<<"left 0 found at = "<<j<<"\n";
                    break;
                }
            }

            if(lo!= -1 && ro!=-1)
            {
                if( (ro-i) <= (i-lo) )
                {
                    a[ro] = -1;
                    cout<<"selected = "<<ro<<"\n";
                    sum+= (ro-i);
                }
                else
                {
                    a[lo] = -1;
                    cout<<"selected = "<<lo<<"\n";
                    sum+= (i-lo);
                }

            }
            else
            {
                if(lo!=-1)
                {
                    a[lo] = -1;
                    cout<<"selected = "<<lo<<"\n";
                    sum+= (i-lo);
                }
                else
                {
                    a[ro] = -1;
                    cout<<"selected = "<<ro<<"\n";
                    sum+= (ro-i);
                }
            }
         cout<<"\n-------------------------\n";
        }

    }
    cout<<sum<<"\n";
    return 0;
}
