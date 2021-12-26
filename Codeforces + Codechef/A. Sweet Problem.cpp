#include<iostream>
#include<algorithm>
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
    ulli a[3],s = 0;
    for(ulli i=0;i<3;i++)
        cin>>a[i];
    y:
    sort(a,a+3);
    if(a[0] == a[1] == a[2] && a[0] != 1)
        {
         s+=a[0]+1;
        goto x;
        }

    if( (a[2]-a[1]) >= a[0] )
        s+=(a[1]+a[0]);
    else
        {
        if(a[0] == a[1])
            {
            s+=2*a[0];
            goto x;
            }
        else
            {
            s+= (a[2]-a[0]);
            }
        a[2] -= s;
        a[1] -= s;
        goto y;
        }
    x:
    cout<<s<<"\n";
    t--;
    }



return 0;
}
