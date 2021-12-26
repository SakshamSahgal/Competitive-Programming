#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi q;
cin>>q;
while(q--)
{
unsigned int l,r;
cin>>l>>r;
if(l%2 == 0 && r%2 == 0)
        cout<<(l+r)/2<<"\n";
else if(l%2 == 1 && r%2 == 1)
        cout<<"-"<<(l+r)/2<<"\n";
else if(l%2 == 1 && r%2 == 0)
    cout<<(r-l+1)/2<<"\n";
else if(l%2 == 0 && r%2 == 1)
    cout<<"-"<<(r-l+1)/2<<"\n";
}


return 0;
}
