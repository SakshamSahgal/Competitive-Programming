#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
usi t;
cin>>t;
while(t--)
    {
    usi x;
    cin>>x;
    if(x<=9)
        {
        cout<<x<<"\n";
        }
    else if(x>45)
        {
        cout<<"-1";
        }
    else
        {
        usi s = 0,d=0;
        for(usi i=9;;i--,d++)
            {
                 s += i;
                if(s>x)
                    {
                    d++;
                    s-=i;
                     break;
                    }

            }
        cout<<d<<" "<<s<<"\n";
        arr[d];

        for(usi i=0,j=(10-d);i<(11-d);i++)
            {
            if(x == (sum_of_digits(s)+j))
                {

                cout<<"\ns= "<<s<<"\n";
                break;
                }
            }
        cout<<"-1\n";
        }
    }
return 0;
}
