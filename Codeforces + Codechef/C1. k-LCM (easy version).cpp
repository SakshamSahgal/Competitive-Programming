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
x:
    if(a!=0 && b!=0)
    {
        temp = a;
        a = b;
        b = temp%b;
        goto x;
    }
    else
        return max(a,b);
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n,k;
        cin>>n>>k;
        if(n%2 == 1)
        {
            cout<<1<<" "<<(n-1)/2<<" "<<(n-1)/2<<"\n";
        }
        else
        {
            if(n%3 == 0)
                cout<<n/3<<" "<<n/3<<" "<<n/3<<"\n";
            else
            {
                if((n-6)%4 == 0)
                    cout<<2<<" "<<(n-2)/2<<" "<<(n-2)/2<<"\n";
                else
                    cout<<n/2<<" "<<n/4<<" "<<n/4<<"\n";
            }
        }

        t--;
    }

    return 0;
}

