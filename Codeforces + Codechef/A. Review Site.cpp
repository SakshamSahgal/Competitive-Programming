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
        usi n;
        cin>>n;
        int a[n];
        int s1=0,s2=0;
        for(usi i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] == 1)
                s1++;
            else if(a[i] == 2)
                s2--;
            else
            {
                if(s1>=s2)
                    s1++;
                else
                    s2--;
            }

        }
        cout<<s1<<"\n";
        t--;
    }
    return 0;
}

