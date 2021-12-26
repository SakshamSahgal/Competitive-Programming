#include<iostream>
#define usi unsigned short int
#define ui unsigned int
#include<cmath>
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
    ui no_of_1 = 0;
    ui no_of_2 = 0;
    for(usi i=0;i<n;i++)
        {
         cin>>a[i];
            if(a[i] == 1)
                no_of_1++;
            else
                no_of_2++;
        }
    if(no_of_1 == 0 || no_of_2 == 0)
        {
        if(n%2 == 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        }
    else if( no_of_1%2 == 0 && (no_of_2*2)%2 == 0 )
        {
        cout<<"YES\n";
        }
    else
        cout<<"NO\n";
    }



return 0;
}
