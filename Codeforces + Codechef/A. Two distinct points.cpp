#include<iostream>
#define usi unsigned short int
#define ui unsigned int
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
    ui l1,r1,l2,r2;
    cin>>l1>>r1>>l2>>r2;
    if(l1 != l2)
        cout<<l1<<" "<<l2<<"\n";
    else if(l1 == l2 && r1!=r2)
        cout<<r1<<" "<<r2<<"\n";
    else if(l1 == l2 && r1 == r2)
        cout<<l1<<" "<<r1<<"\n";
    }
return 0;
}
