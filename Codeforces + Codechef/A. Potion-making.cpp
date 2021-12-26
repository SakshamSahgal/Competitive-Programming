#include<iostream>
#include<algorithm>
#include<vector>
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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t)
{
    int k;
    cin>>k;
    if(k == 100)
        cout<<1<<"\n";
    else
     cout<<(k/(Eular_GCD(k,100-k))) + (100-k)/(Eular_GCD(k,100-k))<<"\n";
    t--;
}

return 0;
}
