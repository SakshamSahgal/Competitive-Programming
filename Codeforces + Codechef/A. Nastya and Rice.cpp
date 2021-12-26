#include<iostream>
#define usi unsigned short int
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t,n,a,b,c,d;
cin>>t;
bool checker =0;
while(t--)
    {
    checker = 0;
    cin>>n>>a>>b>>c>>d;
    for(usi i=(a-b);i<=(a+b);i++)
        {
        if( ((i*n)>=(c-d) && (i*n)<=(c+d)) || ((i*n)>=(c-d) && (i*n)<=(c+d)) )
            {
            checker = 1;
            break;
            }
        }
     if(checker == 0)
            cout<<"NO\n";
     else
        cout<<"YES\n";
    }
return 0;
}
