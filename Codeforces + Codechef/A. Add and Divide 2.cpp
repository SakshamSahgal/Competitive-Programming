#include<iostream>
#include<algorithm>
#include<cmath>
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
    usi t;
    cin>>t;
    while(t)
    {
        lli a,b;
        lli tempa,tempb;
        cin>>a>>b;
        lli c=0;
        tempa = a;
        tempb = b;
        int mini=INT_MAX;
        for(int i=0; i<=sqrt(a); i++)
        {
            tempa = a;
            tempb = b;
            c=0;
            c+=i;
            tempb+=i;

           //cout<<"i = "<<i<<" "<<"b = "<<tempb<<": ";
            if(tempb == 1)
            {
                goto x;
            }
            while(tempa!=0)
            {
                tempa/=tempb;
                //cout<<temp<<"\n";
                c++;

            }
            if(c<mini)
                mini = c;
x:
    tempa=tempa;
            //cout<<"counter = "<<c<<"\n";
        }

        cout<<mini<<"\n";
        t--;
    }

    return 0;
}
