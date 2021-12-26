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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t)
    {
    int n;
    cin>>n;
    int noe=0;
    int noo=0;
    int x;
    for(int i=0;i<(2*n);i++)
    {
        cin>>x;
        if(x%2 == 0)
            noe++;
        else
            noo++;
    }

    if(noe != noo)
        cout<<"No\n";
    else
        cout<<"Yes\n";

    t--;
    }

return 0;
}
