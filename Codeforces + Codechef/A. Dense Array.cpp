#include<iostream>
#include<algorithm>
#include<cmath>
#include<climits>
#include <bits/stdc++.h>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
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
    usi n;
    cin>>n;
    usi a[n];
    for(usi i=0;i<n;i++)
        cin>>a[i];
    int mincount = INT_MAX;
    int c=0;
    double x,y,z;
    for(usi i=0;i<(n-1);i++)
        {
            if( 2*(min(a[i],a[i+1])) < (max(a[i],a[i+1])) )
                {

                mincount = INT_MAX;
                x = (min(a[i],a[i+1]));
                y = (max(a[i],a[i+1]));

                    for(usi j= x+1;j<=(2*x);j++)
                        {
                            z = (log(y/j)/log(2));
							//cout<<z<<" ";

							if( abs( z - (int)(z) ) == 0 ) //int
                                {
                                    //cout<<" int ";
                                    if(mincount > (int)z )
                                        {
                                        mincount = z;
                                        }
                                }
                            else //float
                                {
                                    // cout<<" float ";
                                     //cout<<((int)z+1)<<"\n";
                                    if(mincount> ((int)z+1) )
                                        {
                                        mincount = ((int)z+1);
                                        }
                                }
                        }
               // cout<<"minicount = "<<mincount;
                c+=mincount;
                //cout<<"\n";
                }
        }
    cout<<c<<"\n";
    t--;
    }



return 0;
}
