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
        int x,y;
        cin>>x>>y;
        cout<<x-1<<" "<<y<<"\n";
        /*
        if(x == y)
        {
            if(x%2 == 0)
                cout<<x/2<<" "<<y/2<<"\n";
            else
                cout<<x/2<<" "<<(x/2 + 1)<<"\n";
        }
        else
        {
            if(x<y)
                 cout<<x/2<<" "<<y-(x/2)<<"\n";
            else
            {

                if(y == 1)
                    cout<<x-1<<" "<<1<<"\n";
                else
                {
                    if(y%2 == 1)
                        cout<<x-(y/2)-1<<" "<<(y/2)+1<<"\n";
                    else
                        cout<<x - (y/2) <<" "<<y/2<<"\n";
                }
            }
        } */
        t--;
    }

    return 0;
}
