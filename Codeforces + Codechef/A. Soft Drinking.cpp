#include<iostream>
using namespace std;
int mini(int a,int b,int c)
{

if(a<=b && a<=c)
    return a;
else if(b<=a&&b<=c)
    return b;
else if(c<=a&&c<=b)
    return c;
}



int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned short int n,k,l,c,d,p,nl,np;
cin>>n>>k>>l>>c>>d>>p>>nl>>np;
cout<<mini(((k*l)/nl),p/np,c*d)/n;
return 0;
}
