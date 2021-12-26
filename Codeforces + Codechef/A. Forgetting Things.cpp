#include<iostream>
using namespace std;
int main()
{
unsigned short int da,db;
cin>>da>>db;
if( (da+1) == db )
cout<<da<<"9 "<<db<<"0\n";
else if(da == db)
cout<<da<<"1 "<<db<<"2\n";
else if(da == 9 && db ==1)
cout<<da<<"9 "<<db<<"00\n";
else
    cout<<"-1\n";

return 0;
}
