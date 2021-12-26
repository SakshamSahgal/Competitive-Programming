#include<iostream>
using namespace std;

/*int HCF(int a,int b)
{

    if(a == 1 || b == 1)
        {
            return 1;
        }
    else
    {
        for(int i=2;;i++)
        {
        if((a%i == 0) && (b%i == 0))
            {
            return i;
            }
        }
    }

}*/
/*int LCM(int a,int b)
    {
        if(a == b)
            {
            return a;
            }

        else if(a>b)
            {
                if(a%b == 0)
                    return a;
                else
                    {
                    for(int i=2;;i++)
                        {
                        if( (a*i)%b == 0 )
                            {
                            return (a*i);
                            }
                        }
                    }
            }
            else
            {
                if(b%a == 0)
                    return b;
                else
                    {
                    for(int i=2;;i++)
                        {
                        if( (b*i)%a == 0 )
                            {
                            return (b*i);
                            }
                        }
                    }


            }

    }
*/
int main()
{
short int t;
cin>>t;
long int a,b,x;
while(t--)
    {
    cin>>x;
   // a = 1;
   // b = 1;
   /* for(int i = 1; ;i++)
        {
            if( ( LCM(a,b) + 1 ) == x )
                {
                    cout<<(x-1)<<" "<<"1"<<"\n";
                    break;
                }
            else
                {
                a++;
                }
        }
*/
        cout<<"1 "<<(x-1)<<"\n";
    }
//cout<<"\n"<<LCM(1,1)<<"\n";
//cout<<"\n"<<HCF(1,1)<<"\n";
return 0;
}
