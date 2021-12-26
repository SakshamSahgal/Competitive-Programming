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
    unsigned int spent=0;
    unsigned int s;
    cin>>s;
    unsigned int q=s/10;
    unsigned int r=s%10;
    if(s<10)
        cout<<s<<"\n";
    else
        {
            x:
            q = s/10;
            r = s%10;
            spent+=q*10;
            s = s - (q*10) + q;
            if(s<10)
            cout<<spent+s<<"\n";
            else
                goto x;
        }

    }


return 0;

}
