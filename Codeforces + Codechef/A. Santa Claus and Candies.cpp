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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n;
cin>>n;
double d = sqrt((1+(8*n)));
double k = (d - 1)/2;
int diff = ((ceil(k)*(ceil(k)+1))/2) - n;
//cout<<"diff = "<<diff<<"\n";
if(diff == 0)
cout<<ceil(k)<<"\n";
else
cout<<ceil(k) - 1<<"\n";
        for(int i=1;i<=ceil(k);i++)
        {
            if(i != diff)
                cout<<i<<" ";
        }



return 0;
}
