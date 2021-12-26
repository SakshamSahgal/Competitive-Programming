#include<iostream>
#define ui unsigned int
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    long long int a,b,x,y,n;
    cin>>a>>b>>x>>y>>n;
     long long int p1=0;
     long long int p2=0;
    if( (a-n)>=x )
        {
            p1 = (a-n)*b;
        }
    if((b-n)>=y )
        {
            p2 = a*(b-n);
        }
    if(a>=b)
        {
            if((b-y)>=n)
                b-=n;
            else
                {
                n-=(b-y);
                b-=(b-y);
                if((a-n)>=x)
                    a -= n;
                else
                    a-=(a-x);
                }
        }
    else
        {
            if((a-x)>=n)
                a-=n;
            else
            {
                n -=(a-x);
               a -= (a-x);
               if((b-n)>=y)
                b -= n;
               else
                b-=(b-y);
            }

        }
    cout<<"p1 == "<<p1<<" p2 == "<<p2<<" a*b = "<<a<<","<<b<<"\n";

    if(p1 <= 0 && p2 <= 0 )
            cout<<(a*b)<<"\n";
    else if(p1 <= 0)
        {
            if(p2<=(a*b))
                cout<<p2<<"\n";
            else
                cout<<(a*b)<<"\n";
        }
    else if(p2<=0)
        {
            if(p1<=(a*b))
                cout<<p1<<"\n";
            else
                cout<<a*b<<"\n";
        }
    else
        {
            if(p1<=p2 && p1<=(a*b) )
                cout<<p1<<"\n";
            else if(p2<=p1 && p2<=(a*b))
                cout<<p2<<"\n";
            else
                cout<<a*b<<"\n";
        }
    }
return 0;
}
