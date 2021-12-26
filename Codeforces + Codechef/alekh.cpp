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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);

    int n;
    cin>>n;
    h:
    if(n!= 1)
    {
        if(n%2 == 0)
        {
            n=n/2;
        }
        else
            n= (n*3) + 1;
        cout<<n<<" ";
            goto h;
    }


    return 0;
}

