#include<iostream>
#include<algorithm>
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
    lli a,b,c;
    cin>>a>>b>>c;
    	a %= b;

	for (int i = 1; i <= b; i++)
	{

		a = a * 10;


		if (a / b == c)
			{
			cout<<i;
			return 0;
			}



		a %= b;
	}
	cout<<-1;

    return 0;
}

