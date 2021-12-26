#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int a,b,c;
    cin>>a>>b>>c;
    if(c%2 == 0)
    {
        if(abs(a) > abs(b))
            cout<<">";
        else if(abs(a) < abs(b))
            cout<<"<";
        else
            cout<<"=";
    }
    else
    {
        if(a!=0 && b!=0)
        {
            if(a<0 && b>0)
                cout<<"<";
            else if(a>0 && b<0)
                cout<<">";
            else if(a<0 && b<0)
            {
                if(abs(a) > abs(b))
                    cout<<"<";
                else if(abs(a) < abs(b))
                    cout<<">";
                else
                    cout<<"=";
            }
            else
            {
                if(abs(a) > abs(b))
                    cout<<">";
                else if(abs(a) < abs(b))
                    cout<<"<";
                else
                    cout<<"=";
            }
        }
        else
            {
                if(a == 0 && b == 0)
                   cout<<"=";
                else if(a == 0 && b>0)
                    cout<<"<";
                else if(a == 0 && b<0)
                    cout<<">";
                else if(b == 0 && a>0)
                    cout<<">";
                else if(b == 0 && a<0)
                    cout<<"<";
            }
    }

    return 0;
}


