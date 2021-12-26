#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
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
    ui n;
    cin>>n;
    int a[n];
        for(ui i=0;i<n;i++)
            scanf("%u",&a[i]);
    for(ui i=0;i<(n-1);i++)
        {
            if( abs((a[i+1]-a[i])) >=2 )
            {
              cout<<"YES\n";
              cout<<i+1<<" "<<i+2<<"\n";
                goto x;
            }
        }
    cout<<"NO\n";
    x:
    t--;
    }



return 0;
}
