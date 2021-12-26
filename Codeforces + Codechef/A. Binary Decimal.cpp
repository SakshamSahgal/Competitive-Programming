#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int max_binary(int n)
{
    int mult=1;
    int num=0;
    while(n!=0)
    {
        int d = n%10;
        if(d >= 1)
            num+= 1*mult;

        mult*=10;
        n/=10;
    }
    return num;
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
        int n;
        cin>>n;
        int c=0;
        while(n!= 0)
        {
            //cout<<max_binary(n)<<"\n";
            n = n - max_binary(n);
            c++;
        }
        cout<<c<<"\n";
        t--;
    }

    return 0;
}
