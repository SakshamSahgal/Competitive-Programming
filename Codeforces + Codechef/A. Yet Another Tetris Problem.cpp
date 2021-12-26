#include<iostream>
#include<algorithm>
#define usi unsigned short int
using namespace std;
bool all_equal(int a[],usi n)
{
for(usi i=0;i<(n-1);i++)
    {
    if(a[i] != a[i+1])
        return 0;
    }
return 1;
}

void remove_one(int a[],usi n)
{
for(usi i=0;i<n;i++)
        a[i]--;
}

bool any_zero(int a[],usi n)
{

for(usi i=0;i<n;i++)
    if(a[i] == 0)
        return 1;

return 0;
}

void printer(int a[],usi n)
{
cout<<"\n-------------------\n";
for(usi i=0;i<n;i++)
cout<<a[i]<<" ";
cout<<"\n-------------------\n";
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    usi n;
    cin>>n;
    int a[n];
    for(usi i=0;i<n;i++)
        cin>>a[i];
    z:
    printer(a,n);
    if(all_equal(a,n) == 1)
        {
        cout<<"YES\n";
        }
    else
        {
        sort(a,a+n);
        a[0]+=2;
        if(any_zero(a,n) == 1)
            {
            cout<<"NO\n";
            }
        else
            {
            remove_one(a,n);
            goto z;
            }


        }

    }

return 0;
}
