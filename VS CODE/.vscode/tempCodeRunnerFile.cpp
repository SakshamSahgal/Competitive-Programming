#include<iostream>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned short int t;
cin>>t;
while(t--)
    {
    unsigned long long int b,c,d;
    unsigned long long int time=0;
    int a;
    cin>>a>>b>>c>>d;
    if(b>=a)
        cout<<b<<"\n";
    else if(d>=c)
        cout<<"-1\n";
    else
        {
            a = a - b;
            time+=b;
            if(a%(c-d) == 0)
                {
                //a = 0;
                time+=c*(a/(c-d));
                }
            else
                time += (a/(c-d)+1)*c;
            cout<<time<<"\n";

        }
    }
return 0;
}
