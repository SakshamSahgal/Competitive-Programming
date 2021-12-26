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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
lli l,r;
cin>>l>>r;
cout<<"YES\n";
for(int i=0,j=l;i<(r-l+1)/2;i++,j+=2)
    cout<<j<<" "<<j+1<<"\n";


return 0;
}

