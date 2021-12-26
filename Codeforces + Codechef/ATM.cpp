#include<iostream>
using namespace std;
int main()
{
float x;
float y;
cin>>x>>y;
if((y-x-0.5)>=0 && (int)x%5 == 0)
    cout<<y-x-0.5;
else
    cout<<y;
return 0;
}
