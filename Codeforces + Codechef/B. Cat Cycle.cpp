#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
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
	long long int n,k;
	cin>>n>>k;
	long long int b = (n/2);
	if(n%2 == 0)
		{
		    if(k>n)
				{
					if(k%n == 0)
					cout<<n<<"\n";
					else
					cout<<k%n<<"\n";
				}
			else
            cout<<k<<"\n";
		}
	else
		{
			if(k%b != 0)
                {
                if((k%n + k/b) > n)
                    {
                        if((k%n + k/b)%n == 0)
                            cout<<n<<"\n";
                        else
                           cout<<(k%n + k/b)%n<<"\n";
                    }
                else
                        cout<<(k%n + k/b)<<"\n";
                }

			else
                {
                    if((k%n + k/b - 1)>n)
                        {
                            if(((k%n + k/b - 1)%n) == 0)
                            cout<<n<<"\n";
                            else
                            cout<<((k%n + k/b - 1)%n)<<"\n";
                        }

                    else
                    cout<<(k%n + k/b - 1)<<"\n";

                }

		}
	t--;
	}
return 0;
}
