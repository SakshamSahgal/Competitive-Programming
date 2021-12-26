#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

lli findlcm(int arr[], int n)
{
	lli ans = arr[0];
	// ans contains LCM of arr[0], ..arr[i]
	// after i'th iteration,
	for (int i = 1; i < n; i++)
		ans = (((arr[i] * ans)) /
				(gcd(arr[i], ans)));
	return ans;
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int r,s;
cin>>r>>s;
int First[r];
int Second[s];
for(usi i=0;i<r;i++)
    cin>>First[i];
for(usi i=0;i<s;i++)
    cin>>Second[i];

lli x = findlcm(First,r);
lli y = x;
bool go = 1;

int counter=0;
while(go == 1)
    {
    for(int i=0;i<s;i++)
        {
            if(Second[i]%x != 0)
                {
                    go = 0;
                    goto z;
                }
        }
    //cout<<x<<"\n";
    counter++;
    x+=y;
    }
z:
cout<<counter<<"\n";
return 0;
}
