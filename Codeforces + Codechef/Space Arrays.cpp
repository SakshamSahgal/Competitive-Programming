#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
void printer(int n,int a[],vector <int> b)
{
    cout<<"\n-------------------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\nfreq = \n";
    for(int i=0; i<(n+1); i++)
        cout<<b[i]<<" ";
    cout<<"\n-------------------------\n";
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
        int n;
        cin>>n;
        int a[n];
        vector <int> b((n+1),0);
        long long int moves=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            b[a[i]]++;
        }
        //printer(n,a,b);
        sort(a,a+n);
        for(int i=(n-1); i>=0; i--)
        {

            if(a[i] != n)
            {
                for(int j=(a[i]+1); j<=n; j++)
                {
                    if(  ( (n-j+1) - b[j] )  > 0 )
                    {
                        moves++;
                        b[j-1]--;
                        b[j]++;
                        a[i]++;
                        // printer(n,a,b);
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        // cout<<"Moves = "<<moves<<"\n";
        if(moves%2 == 0)
            cout<<"Second\n";
        else
            cout<<"First\n";
        t--;
    }

    return 0;
}

