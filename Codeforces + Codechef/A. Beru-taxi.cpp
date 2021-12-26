#include<bits/stdc++.h>
using namespace std;
int main()
{
int a,b;
cin>>a>>b;
unsigned int n;
cin>>n;
double time = 500;
while(n--)
    {
    int x,y,v;
    cin>>x>>y>>v;
    float dis = pow((pow((a-x),2)+pow((b-y),2)),0.5);
     if(time >(dis/v))
        time = dis/v;
    }
cout<<fixed<<setprecision(7)<<time<<"\n";


return 0;
}
