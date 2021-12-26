#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
lli nod(lli n)
{

    lli digit=0;

    while(n!=0)
    {
        n=n/10;
        digit++;
    }
    return digit;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        if(n<10)
            cout<<n<<"\n";
        else
        {
            lli sum = 9*(nod(n)-1);
            lli temp;
            lli noddd = nod(n);
            for(int i=1;i<=9;i++)
                {
                    temp = i*((pow(10,noddd) -1)/(10-1));
                   // cout<<temp<<"\n";
                    if( temp<=n)
                        sum++;
                    else
                        break;
                }

        cout<<sum<<"\n";
        }

        t--;
    }

    return 0;
}

