#include<iostream>
using namespace std;
int main()
{
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
short int t;
cin>>t;
while(t--)
    {
    int a,b,c=0;
        cin>>a>>b;
            if( (a%b) > 0)
                {
                c = a%b;
                c = b - c;
                }
    cout<<c<<"\n";
    }


return 0;
}
