#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int gcd(int a,int b)
{
return b==0? a:gcd(b,a%b);
}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    int l,b;
    cin>>l>>b;
    int counter=0;
    if(l==b)
        counter=1;
    else
        {
            int g = gcd(l,b);
            counter = l*g + rb+g;
        }
    cout<<counter<<"\n";
    t--;
    }


return 0;
}
