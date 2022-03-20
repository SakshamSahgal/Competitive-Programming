#include<iostream>
#include<math.h>
using namespace std;


long double dist(long double x,long double y)
{
    return (sqrtl(x*x + y*y) );
}

int counter(int d,int n,int p[][2])
{
    int c=0;

    for(int i=0;i<n;i++)
    {
        //cout<<p[i][0]<<" "<<p[i][1]<<"\n";
        if(dist(p[i][0],p[i][1]) <= d)
            c++;
    }
    return c;
}
int main()
{
    //GO_FAST
    int n,k;
    cin>>n>>k;
    int p[n][2];

    for(int i=0;i<n;i++)
        cin>>p[i][0]>>p[i][1];

    int l=0;
    int h=100000;
    int ans=0;

    while(l<=h)
    {
        int mid = (l+h)/2;

        int nop = counter(mid,n,p);
        cout<<"nop = "<<nop<<" for mid = "<<mid<<"\n";
        if( nop < k)
        {
            ans = mid;
            l = mid+1;
        }
        else if(nop == k)
        {
            ans = mid;
            break;
        }
        else
            h = mid-1;
    }
    cout<<"ans = "<<ans<<"\n";
    return 0;
}

