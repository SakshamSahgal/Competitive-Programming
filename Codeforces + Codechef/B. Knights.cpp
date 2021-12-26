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
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        if(i%2 == 0)
        {
            for(int j=0; j<n; j++)
            {
                if(j%2 == 0)
                    cout<<"W";
                else
                    cout<<"B";
            }
        }
        else
        {
            for(int j=0; j<n; j++)
            {
                if(j%2 == 0)
                    cout<<"B";
                else
                    cout<<"W";
            }
        }
        cout<<"\n";
    }
    return 0;
}
