#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
void printer(usi n,usi a[])
{
cout<<"\n";
for(usi i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<"\n";
}
bool compare(usi n,usi a[],usi b[])
{
for(usi i=0;i<n;i++)
    {
    if(a[i] != b[i])
        return 0;
    }
return 1;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    usi m,n;
    cin>>n>>m;
    usi a[n],p[m];
    usi b[n];
    for(usi i=0;i<n;i++)
        {
        cin>>a[i];
        b[i] = a[i];
        }
    sort(b,b+n);
    for(usi i=0;i<m;i++)
        cin>>p[i];

    for(usi i=0;i<m;i++)
        {

            for(usi i=0;i<m;i++)
                {
                   if(p[i]<=(n-1))
                    {
                        if( a[p[i]-1] > a[p[i]] )
                            {
                             usi temp = a[p[i]-1];
                             a[p[i]-1] = a[p[i]];
                             a[p[i]] = temp;
                            }
                    }
                }
            //printer(n,a);
            if(compare(n,a,b) == 1)
                {
                cout<<"YES\n";
                goto x;
                }

        }

    cout<<"NO\n";
    x:
    t--;
    }



return 0;
}
