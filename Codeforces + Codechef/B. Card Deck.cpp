#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void array_printer(int a[],int n)
{
cout<<"\n----------------\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n----------------\n";
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
        int prefix[n];
        int maxx = INT_MIN;
        int max_index;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];

            if(a[i] > maxx)
            {
                maxx = a[i];
                max_index = i;
            }

            prefix[i] = max_index;
        }

        //array_printer(prefix,n);

        for(int i=n-1;i>=0;i--)
            {
                for(int j=prefix[i]; j<n;j++)
                    {
                        if(a[j] != -1)
                        {
                            cout<<a[j]<<" ";
                            a[j] = -1;
                        }
                        else
                            break;
                    }
            }
        cout<<"\n";
        t--;
    }
    return 0;
}


