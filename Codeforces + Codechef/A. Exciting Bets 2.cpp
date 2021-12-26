#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

lli Eular_GCD(lli a,lli b)
{
    lli temp;
    if(a!=0 && b!=0)
    {
x:
        if(a == 0)
            return b;
        else if(b == 0)
            return a;
        else
        {
            temp = a;
            a = b;
            b = temp%b;
            goto x;
        }
    }
    else
        return (lli)max(a,b);
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        lli a;
        lli b;
        cin>>a>>b;
        if(a==b)
            cout<<0<<" "<<0<<"\n";
        else{
            lli y = (max(a,b) - min(a,b));
            cout<<y<<" ";
            if(y == Eular_GCD(a,b))
                cout<<"0\n";
            else
            {
                lli distance1;
                lli distance2;
                if(a<y)
                    distance1 = y-a;
                else
                    distance1 = min(abs((y*((a/y) + 1) - a)),abs((y*(a/y)-a)));

                if(b<y)
                    distance2 = y-b;
                else
                    distance2 = min(abs((y*((b/y) + 1) - b)),abs((y*(b/y)-b)));

                //cout<<"distance  = "<<distance1<<" "<<distance2<<"\n";
                cout<<min(min(a,b),min(distance1,distance2))<<"\n";
            }
        }
        t--;
    }

    return 0;
}
