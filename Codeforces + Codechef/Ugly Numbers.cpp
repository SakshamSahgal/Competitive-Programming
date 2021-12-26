#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
int counter=0;
int n;
cin>>n;
int a,b,c;
for(int i=1;i<=100000;i++)
    {
        a = ceil((log(i)/log(2)));
        b = ceil((log(i)/log(3)));
        c = ceil((log(i)/log(5)));
        //cout<<a<<" "<<b<<" "<<c<<"\n";

        for(int j=0;j<=a;j++)
            {
                for(int k=0;k<=b;k++)
                    {
                        for(int l=0;l<=c;l++)
                        {
                            if( (pow(2,j)*pow(3,k)*pow(5,l)) == i )
                            {
                                counter++;
                                 cout<<i<<" counter = "<<counter<<"\n";

                            }

                        }
                    }

            }


    }
cout<<counter<<"\n";
return 0;
}

