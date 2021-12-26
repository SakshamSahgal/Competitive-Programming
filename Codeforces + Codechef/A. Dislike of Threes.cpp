#include<iostream>
#include<string>
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
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    lli a[1001];
    for(lli i=1,j=1;i<=1000;j++)
        {
            if(j%3 != 0 && j%10 != 3)
                {
                    a[i] = j;
                    i++;
                }
        }

    while(t)
    {
        int k;
        cin>>k;
        cout<<a[k]<<"\n";
        t--;
    }
    return 0;
}


