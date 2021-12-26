#include<iostream>
using namespace std;
int main()
{
short int t;
int l=0;
int r = 0;
int a=2;
cin>>t;
while(t--)
    {
    int checker = 0;
    cin>>l>>r;
    for(int x=l;x<=r;x++)
        {
        if((x%a) >= (a/2.0))
            {

            }
        else
            {
            checker = 1;
            break;
            }
        }
    if(checker == 1)
        {
        cout<<"NO\n";
        }
    else
        {
        cout<<"YES\n";
        }
    }

return 0;
}
