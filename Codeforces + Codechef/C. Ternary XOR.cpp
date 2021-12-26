#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
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
	char x[n];
	bool activated=0;
	string a,b;
	a += '1';
	b +='1';
	for(int i=0;i<n;i++)
	{
	cin>>x[i];
		if(i>0)
			{
			if( activated == 0 && x[i] == '1')
				{
					activated = 1;
					a += '0';
					b += '1';
				}

			else
				{
					if(activated == 0)
						{
							if(x[i] == '0')
							{
								a += '0';
								b += '0';
							}
						else if(x[i] == '2')
							{
								a += '1';
								b += '1';
							}
						}
					else //activated
						{
						if(x[i] =='0')
							{
								a += '0';
								b += '0';
							}
						else if(x[i] == '1')
							{
								a += '1';
								b += '0';
							}
						else
							{
								a += '2';
								b += '0';
							}
						}
				}


			}
	//cout<<"a[i] = "<<a[i]<<"\n"<<"b[i] = "<<b[i]<<"\n";
	}
	cout<<b<<"\n"<<a<<"\n";
	t--;
	}

return 0;
}

