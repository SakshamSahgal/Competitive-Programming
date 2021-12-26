#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t)
    {
    lli c;
    cin>>c;
    lli d  = ceil(log(c)/log(2));
    if(pow(2,d) <= c)
        d++;


    int nod=1;
    int i=c;
    while(i>=2)
        {
        i=i/2;
        nod++;
        }

    //cout<<"d = "<<d<<"\n";
    x:
    //cout<<"nod  = "<<nod<<"\n";

    lli b = pow(2,(nod-1)) - 1;
    lli a = c^b;
    //cout<<"a , b , 2^d "<<a<<" "<<b<<" "<<setprecision(20)<<pow(2,d)<<"\n";
    if(b<pow(2,d) && a<pow(2,d))
        cout<<fixed<<setprecision(20)<<(a*b)<<"\n";
    else
        {
        nod--;
        goto x;
        }
    t--;
    }

return 0;
}

