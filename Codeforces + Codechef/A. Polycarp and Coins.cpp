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
        lli n;
        cin>>n;
        /*
        int mini=INT_MAX;
        int at_c2=0;

        for(int c2 = 0 ; c2<=n/2; c2++)
        {
           cout<<(n- (2*c2))<<" "<<c2<<" diff = "<<abs(n - 3*c2)<<"\n";
        }
        //cout<<at_c1<<" "<<(n-at_c1)/2<<" "<<mini<<"\n";
        */
        lli c2 = n/3 + (n%3)/2;
        lli c1 = n - 2*c2;
        cout<<c1<<" "<<c2<<"\n";


        t--;
    }

    return 0;
}

