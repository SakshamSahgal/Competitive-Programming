#include<iostream>
using namespace std;
int main()
{
long int n,countit = 0;
cin>>n;
while(n != 1)
    {
        if(n>6)
            {
                if(n%6 ==0)
                {
                n = n/6;
                cout<<"\n" <<"divisible by 6 \t"<<n;
                }
        else
                {
                n = n*2;
                cout<<"\n"<<"multiplied by 2 \t"<<n;
                }
            }
        else
            {
            n = n*2;
            }

    countit++;
    if(countit >= n)
        {
        cout<<"-1";
        return 0;
        }
    }
cout<<countit;
return 0;
}
