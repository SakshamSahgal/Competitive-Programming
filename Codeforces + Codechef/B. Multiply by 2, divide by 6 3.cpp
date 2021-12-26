#include<iostream>
#include<algorithm>
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
        lli n;
        cin>>n;
        if(n==1)
            {
              cout<<0<<"\n";
                goto z;
            }

        else
        {
            lli c=0;
x:

            if(n == 1)
                {
                 cout<<c<<"\n";
                goto z;
                }


            if(n<6)
            {
                if(n%3 == 0)
                {
                    n*=2;
                    c++;
                    goto x;
                }
                else
                {
                    cout<<"-1\n";
                    goto z;
                }

            }
            else
            {
                if(n%6 == 0)
                {
                    n/=6;
                    c++;
                    goto x;
                }
                else
                {
                    if(n%3 == 0)
                    {
                        n*=2;
                        c++;
                        goto x;
                    }
                    else
                    {
                        cout<<"-1\n";
                       goto z;
                    }

                }
            }


        }
    z:
  t--;
    }

    return 0;
}
