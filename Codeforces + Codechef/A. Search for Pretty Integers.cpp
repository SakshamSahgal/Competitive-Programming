#include<iostream>
#include<algorithm>
#define usi unsigned short int
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi n,m;
cin>>n>>m;
usi a[n],b[m];
for(usi i=0;i<n;i++)
    cin>>a[i];

for(usi i=0;i<m;i++)
    cin>>b[i];

bool a_me_mila = 0;
bool b_me_mila = 0;
//single digits
sort(a,a+n);
sort(b,b+m);
for(usi i=1;i<=9;i++)
    {
        a_me_mila = 0;
        b_me_mila = 0;
        //a ke lie
        for(usi j=0;j<n;j++)
            {
                if(a[j] == i)
                a_me_mila = 1;
            }
        // b ke lie
        for(usi j=0;j<m;j++)
            {
                if(b[j] == i)
                    b_me_mila = 1;

            }
        if(a_me_mila == 1 && b_me_mila == 1)
            {
            cout<<i<<"\n";
            return 0;
            }
    }

//cout<<a[0]<<" "<<b[0]<<"\n";
if(a[0]<=b[0])
    {
    cout<<a[0]<<b[0]<<"\n";
    return 0;
    }
else
    {
    cout<<b[0]<<a[0]<<"\n";
    return 0;
    }
return 0;
}
