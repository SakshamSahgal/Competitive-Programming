#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int Eular_GCD(int a,int b)
{
    int temp;
    if(a!=0 && b!=0)
    {
            x:
            if(a == 0)
                return b;
            else if(b == 0)
                return a;
            else
            {
                temp = a;
                a = b;
                b = temp%b;
                goto x;
            }
    }
    else
        return max(a,b);
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    cout<<Eular_GCD(2,1)<<"\n";
    cout<<Eular_GCD(2,2)<<"\n";
    cout<<Eular_GCD(1,2)<<"\n";
    cout<<Eular_GCD(0,1)<<"\n";
    cout<<Eular_GCD(1,0)<<"\n";
    cout<<Eular_GCD(2,0)<<"\n";
     cout<<Eular_GCD(100000000,7)<<"\n";
    return 0;
}

