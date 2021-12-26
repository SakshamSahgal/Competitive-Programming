#include<iostream>
#include<algorithm>
#define usi unsigned short int
using namespace std;
bool is_palindrome(usi a[],usi stp,usi edp)
{

usi b[edp-stp+1];
for(usi i=stp,j=0;i<=edp;i++,j++)
        b[j] = a[i];
/*
cout<<"\n---------------\n";
for(usi i=0;i<(edp-stp+1);i++)
        cout<<b[i]<<" ";
cout<<"\n---------------\n";
*/
    for(usi i=0;i<(edp-stp+1)/2;i++)
        {
            if(b[i] != b[(edp-stp-i)])
                return 0;
        }
return 1;
}
int main()
{
usi t;
cin>>t;
while(t--)
    {
    usi n;
    cin>>n;
    usi a[n];

    for(usi i=0;i<n;i++)
        cin>>a[i];

    for(usi i=0;i<=(n-3);i++)
        {
        for(usi j=(i+2);j<n;j++)
            {
            if(a[i] == a[j])
                {
                if(is_palindrome(a,i,j) == 1)
                    {
                cout<<"YES\n";
                goto y;
                    }
                }
            }
        }
    cout<<"NO\n";
    y:
    n=n;

    }
return 0;
}
