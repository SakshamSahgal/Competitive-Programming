#include<iostream>
#include<cmath>
using namespace std;

int is_prime(int n)
    {
    if(n == 1) // 1 is not a prime number
        {
        return 0;
        }
    else
    {
        for(int i=2; i<=(n/2);i++)
        {
            //cout<<"n = "<<n<<"\t"<<"i = "<<i<<"\t"<<"n%i == "<<n%i<<"\t"<<"pow = "<<pow(n,0.5)<<"\n";
                if((n%i) == 0)
                    {
                    return 0;
                    break;
                    }
        }
            return 1;
    }
}


int main()
{
//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
   // cout.tie(NULL);
unsigned short int t;
cin>>t;
while(t--)
    {
    int x=1;
    int y=1;
    unsigned short int n;
    cin>>n;
    long int a[n][n];

        for(int i=0;i<(n-1);i++)
            {
            for(int j=0;j<(n-1);j++)
                {
                a[i][j] = 1;
                }
            }

        for(x=1; ;)
            {
                    if((is_prime(x) != 1) && (is_prime(((n-1) + x)) == 1))
                            {
                            break;
                            }
                    else
                        {
                        x++;
                        }
            }
     //cout<<"x = "<<x<<"\n";

       for(int b=0;b<(n-1);b++)
            {
            a[b][(n-1)] = x;
            a[(n-1)][b] = x;
            }



    for(y=1; ;)
        {
                if( (is_prime(y) != 1) && (is_prime((x*(n-1))+y) == 1))
                    {
                        break;
                    }
                else
                    {
                    y++;
                    }
        }
    //cout<<"\n y = "<<y<<"\n";

        a[(n-1)][(n-1)] = y;
        //printer
       // cout<<"n = "<<n<<"\n";
        //cout<<"\n-------------------\n";
        for(int i=0;i<n;i++)
            {
            for(int j=0;j<n;j++)
                {
                cout<<a[i][j]<<" ";
                }
                cout<<"\n";
            }
       // cout<<"\n-------------------\n";
        //cout<<"\n";
      // cout<<"\n"<<is_prime(841)<<"\n";
       //cout<<"\n"<<841%29<<"\n";
    }
return 0;
}
