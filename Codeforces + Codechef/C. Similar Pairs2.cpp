#include<iostream>
#include<algorithm>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    usi n;
    cin>>n;
    usi a[n];
    usi noe=0,noo=0;
    for(usi i=0;i<n;i++)
        {
        cin>>a[i];
        if(a[i]%2 == 0)
            noe++;
        else
            noo++;
        }
    if(noe%2 == 0 && noo%2==0)
        cout<<"YES\n";
    else
        {
        usi p=0;
        sort(a,a+n);
        for(usi i=0;i<(n-1);i++)
            {
                if(a[i]+1 == a[i+1])
                    {
                     p++;
                    cout<<"YES\n";
                    goto x;
                    }

            }
        cout<<"NO\n";

        }
    x:
    n=n;
    }

return 0;
}
