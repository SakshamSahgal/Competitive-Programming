#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int check(int n)
{
    if(n == 1)
        return 0;
    if(n == 2)
        return 1;
    else
    {
        int k = n-2;
        int a = n;
        int b = n-1;
        int sum;
h:
        sum = a&b;
        //cout<<a<<"&"<<b<<"="<<(a&b)<<"\n";

        if(sum == 0)
            return b;
        else
        {
            a = sum;
            b = k;
            k--;
            goto h;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    for(int n=1;n<=100;n++)
        {
            lli x = floor(log(n)/log(2));
            cout<<"i = "<<n<<" "<<(lli)pow(2,x) - 1<<"\n";
        }


    /*
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli x = floor(log(n)/log(2));
        cout<<(lli)pow(2,x) - 1<<"\n";
        t--;
    } */


    return 0;
}

