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
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        int p[n];
        int index[n+1];

        for(int i=0; i<n; i++)
        {
            cin>>p[i];
            index[p[i]] = i;
        }
        int max_pos = index[1];
        int min_pos = index[1];
        for(int i=1; i<n; i++)
        {

            max_pos = max(index[i],max_pos);
            min_pos = min(index[i],min_pos);

            if( (max_pos - min_pos + 1 ) ==  i )
                cout<<1;
            else
                cout<<0;

        }

        cout<<1<<"\n";
         t--;
    }


return 0;
}

