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
        int x;
        cin>>x;
        if( ( ( x - 111*(x%11) )%11 ) == 0 && ( x - 111*(x%11) ) >= 0)
            cout<<"YES\n";
        else
            cout<<"NO\n";



        t--;
    }

    return 0;
}

