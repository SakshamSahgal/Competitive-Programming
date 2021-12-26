#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
       // int n,m;
     //   cin>>n>>m;
        int counter=0;
        for(int n=1; n<=10; n++)
        {
            for(int m=1; m<=20; m++)
            {
                if(m == 1)
                   cout<<""<<n<<","<<m<<","<<((n-1)*(n))/2<<"\n";
                else
                {
                    for(int a=1; a<=n; a++)
                    {
                        for(int b=a+1; b<=n; b++)
                        {
                            if( ((m%a)%b) == ((m%b)%a) )
                            {
                                //  cout<<"("<<a<<","<<b<<")"<<" ("<<((m%a)%b)<<" = "<<((m%b)%a)<<") \n";
                                counter++;
                            }

                        }
                    }
                    cout<<""<<n<<","<<m<<","<<counter<<"\n";
                }
            }

        }

        t--;
    }

    return 0;
}

