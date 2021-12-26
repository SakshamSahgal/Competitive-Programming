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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        int x1,y1,z1,x2,y2,z2;
        cin>>x1>>y1>>z1>>x2>>y2>>z2;
        lli sum=0;
        if(z1>0)
        {
            if(y2>=z1)
                {
                    sum+=z1*(2);
                    y2-=z1;
                    z1=0;
                }
            else
                {
                    sum+= y2*2;
                    z1-=y2;
                    y2=0;
                    if(z2>=z1)
                    {
                        z2-=z1;
                        z1=0;
                    }
                    else
                        {
                            z1-=z2;
                            z2=0;
                            z1-=x2;
                            z1=0;
                        }
                }
        }

        if(y1 > 0)
            {
                if(y2>=y1)
                    {
                        y2-=y1;
                        y1=0;
                    }
                else
                    {
                        y1-=y2;
                        y2=0;
                        if(x2>=y1)
                        {
                            x2-=y1;
                            y1=0;
                        }
                        else
                            {
                                y1-=x2;
                                x2=0;
                                z2-=y1;
                                sum-=y1*2;
                                y1=0;
                            }
                    }

            }

        cout<<sum<<"\n";
        t--;
    }



    return 0;
}
