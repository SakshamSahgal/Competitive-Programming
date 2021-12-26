#include<iostream>
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
    int n,k;
    cin>>n>>k;
    if(n%k == 0)
         cout<<n<<"\n";
    else
        {
            if( (n%k) <= (k/2) )
                cout<<(n/k)*k+ (n%k)<<"\n";
            else
                cout<<(n/k)*k+(k/2)<<"\n";
        }

    }
return 0;
}
