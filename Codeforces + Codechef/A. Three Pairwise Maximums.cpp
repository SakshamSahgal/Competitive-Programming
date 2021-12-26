#include<iostream>
#define usi unsigned short int
using namespace std;
int maximum(unsigned int x,unsigned int y)
{
if(x>y)
    return x;
else
    return y;
}
int Three_pairwise_sum(unsigned int a,unsigned int b,unsigned int c,unsigned int x,unsigned int y,unsigned int z)
{
if(x == maximum(a,b) && y == maximum(b,c) && z ==  maximum(a,c))
return 1;
else
    return 0;
}

int main()
{
usi t;
cin>>t;
while(t--)
    {
    unsigned int a,b,c;
    unsigned int x,y,z;
    cin>>x>>y>>z;
    if(x == y && y == z && z == x)
        {
        cout<<"YES\n";
        cout<<x<<" "<<y<<" "<<z<<"\n";
        goto y;
        }
    else if(Three_pairwise_sum(z,x,z,x,y,z) == 1)
        {
            cout<<"YES\n";
            cout<<z<<" "<<x<<" "<<z<<"\n";
            goto y;
        }
     else if(Three_pairwise_sum(z,x,y,x,y,z) == 1)
        {
            cout<<"YES\n";
            cout<<z<<" "<<x<<" "<<y<<"\n";
            goto y;
        }
    else if(Three_pairwise_sum(z,y,z,x,y,z) == 1)
        {
            cout<<"YES\n";
            cout<<z<<" "<<y<<" "<<z<<"\n";
            goto y;
        }
    else if(Three_pairwise_sum(z,y,y,x,y,z) == 1)
        {
            cout<<"YES\n";
            cout<<z<<" "<<y<<" "<<y<<"\n";
            goto y;
        }
     else if(Three_pairwise_sum(x,x,z,x,y,z) == 1)
        {
            cout<<"YES\n";
            cout<<x<<" "<<x<<" "<<z<<"\n";
            goto y;
        }
    else if(Three_pairwise_sum(x,x,y,x,y,z) == 1)
        {
            cout<<"YES\n";
            cout<<x<<" "<<x<<" "<<y<<"\n";
            goto y;
        }
    else if(Three_pairwise_sum(x,y,z,x,y,z) == 1)
        {
            cout<<"YES\n";
            cout<<x<<" "<<y<<" "<<z<<"\n";
            goto y;
        }
    else if(Three_pairwise_sum(x,y,y,x,y,z) == 1)
        {
            cout<<"YES\n";
            cout<<x<<" "<<y<<" "<<y<<"\n";
            goto y;
        }
    else
    {
        cout<<"NO\n";
        goto y;
    }
    y:
    x=x;
    }
return 0;
}
