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

    int t;
    cin>>t;
    while(t--)
    {

        int n,w,wr;
       cin>>n>>w>>wr;

        map<int,int>mp;
        int Ar[n];
        for(int i=0;i<n;i++)
        {
            cin>>Ar[i];
            mp[Ar[i]]++;
        }
        if(wr>=w)
           cout <<"YES"<<"\n";

        else
        {
            w=w-wr;
            for( int i=0;i<n;i++)
            {
                if(mp[Ar[i]]>=2)
                {

                    int count=mp[Ar[i]];
                    if(count % 2==0)
                    {
                         w-=count*Ar[i];
                    }
                    else
                        {
                        w-=(count - 1)* Ar[i];
                        }
                    mp[Ar[i]] = 0;
                }
                if(w <= 0){
                    break;
                }
            }
            if(w <= 0)
            {
                cout << "YES" << "\n";
            }
            else
            {
            cout << "NO" << "\n";
            }
        }
    }

}
