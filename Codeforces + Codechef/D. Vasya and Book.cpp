#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,x,y,d;
        cin>>n>>x>>y>>d;


        if( abs(y-x)%d == 0)
        {
            cout<<abs(y-x)/d<<"\n";
           // cout<<"Direct\n";
        }
        else
        {
            lli d1=-1;
            lli d2=-1;
            if( abs((y-1))%d == 0 )
            {
                if((x-1)%d == 0)
                    d1 = (x-1)/d + abs((y-1))/d;
                else
                    d1 = (x-1)/d + abs((y-1))/d + 1;
            }
            if( abs((n-y))%d == 0)
            {
                if( (x-n)%d == 0)
                    d2 = abs((x-n)/d) + abs((n-y))/d;
                else
                {
                    //cout<<"idhar aaiya \n";
                    d2 = abs((x-n))/d + abs((n-y))/d + 1;
                }

            }

            //cout<<d1<<" "<<d2<<"\n";

            if(d1 == -1 && d2 == -1)
                cout<<-1<<"\n";
            else if(d1 != -1 && d2 == -1)
            {
                cout<<d1<<"\n";
               // cout<<"Peeche jake aage\n";
            }

            else if(d1 == -1 && d2 != -1)
            {
                cout<<d2<<"\n";
               // cout<<"aage jake Peeche\n";
            }
            else
                cout<<min(d1,d2)<<"\n";
        }

        t--;
    }
    return 0;
}
