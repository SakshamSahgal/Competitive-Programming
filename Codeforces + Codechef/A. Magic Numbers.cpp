#include<iostream>
#include<algorithm>
#define usi unsigned short int
using namespace std;

int main()
{
string a;
cin>>a;
if(a[0] != '1')
    {
    cout<<"NO\n";
    return 0;
    }
else
    {
    for(usi i=0;i<a.length();i++)
        {
        if(a[i] == '1' && a[i+1] == '4' && a[i+2] == '4')
            {
            //cout<<"144 mila\n";
            i+=2;
            }
        else if(a[i] == '1' && a[i+1] == '4')
            {
            //cout<<"14 mila\n";
            i+=1;
            }
        else if(a[i] =='1')
            {
            //cout<<"1 mila\n";
            }
        else
            {
            cout<<"NO\n";
            return 0;
            }
        }

    cout<<"YES\n";
    }
return 0;
}
