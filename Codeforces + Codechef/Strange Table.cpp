#include<iostream>
#include<algorithm>
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
usi t;
cin>>t;
while(t)
    {
    lli n,m,x;
    cin>>n>>m>>x;
    lli col,row=1;

            if(x%n == 0)
            col = x/n;
            else
            col = (x/n) + 1;

    row = x - (col-1)*n;
    //cout<<"row = "<<row<<" "<<"col = "<<col<<"\n";
    cout<< (row-1)*m + col<<"\n";
    t--;
    }
return 0;
}
