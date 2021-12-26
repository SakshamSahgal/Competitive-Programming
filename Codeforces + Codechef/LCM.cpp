#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
ulli Eular_GCD(ulli a,ulli b)
{
    ulli temp;
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

ulli LCM(ulli arr[],ulli n)
{
    ulli Ans=arr[0];

    for(int i=1; i<n; i++)
        Ans  = (Ans*arr[i])/(Eular_GCD(Ans,arr[i]));

return Ans;
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    ulli arr[4] = {5,1,2,3};
    ulli lcm = LCM(arr,4);
    cout<<lcm<<"\n";
    return 0;
}



