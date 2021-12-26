#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n;
cin>>n;
int a[n];
for(usi i=0;i<n;i++)
    cin>>a[i];
int c = 0;
int maxi=0;
for(int st=0;st<=(n-1);st++)
        {
            for(int ed = (n-1);ed>=st;ed--)
                {
                    c=0;
                    for(int i=st;i<=ed;i++)
                        if(a[i] == 0)
                            c++;

                    for(int i=0;i<st;i++)
                        if(a[i] == 1)
                            c++;

                    for(int i=ed+1;i<n;i++)
                        if(a[i] == 1)
                            c++;

                 if(c>maxi)
                    maxi = c;
                 if(c == n)
                    goto x;
                }
        }



x:
cout<<maxi<<"\n";
return 0;
}
