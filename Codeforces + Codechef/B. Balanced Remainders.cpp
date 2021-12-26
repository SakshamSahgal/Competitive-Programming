#include<iostream>
#include<algorithm>
#include<cmath>
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
		int n;
		cin>>n;
		usi a[n];
		int c0=0,c1=0,c2=0;
		int m=0;
		for(usi i=0;i<n;i++)
			{
				cin>>a[i];

			if(a[i]%3 == 0)
				c0++;
			else if(a[i]%3 == 1)
			c1++;
			else
			c2++;
			}
		//cout<<c0<<" "<<c1<<" "<<c2<<"\n";

		if(c0 == c1 && c1 == c2 && c2 == (n/3))
			m=0;
		else
		{
		    if( (c0>(n/3) && c1 <=(n/3) && c2 <=(n/3)) || (c1>(n/3) && c0 <=(n/3) && c2 <=(n/3)) || (c2>(n/3) && c1 <=(n/3) && c0 <=(n/3)) )
                {
						if(c2 >= c1 && c2 >= c0)
							m = abs(c0-(n/3)) + abs(c1-(n/3))*2;

						else if(c1>=c0 && c1>=c2)
							m =  abs(c0-(n/3))*2 + abs(c2-(n/3));

						else
							m = abs(c1-(n/3)) + abs(c2-(n/3))*2;
                }
			else
			{
					if( (c0 > (n/3) && c1 > (n/3) && c2 <= (n/3)) )
						m = 	abs(c0-(n/3))*2 + abs(c1-(n/3));

					else if (c1 > (n/3) && c2 > (n/3) && c0 <= (n/3))
						m = abs(c1-(n/3))*2 + abs(c2-(n/3));

					else
							m = abs(c0-(n/3)) + abs(c2-(n/3))*2;

			}

		}

	cout<<m<<"\n";

	t--;
	}



return 0;
}
