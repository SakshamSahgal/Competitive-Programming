#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
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
    int t;
    cin>>t;
    while(t)
    {
        int n,m;
        cin>>n>>m;
        int temp;
        lli sum=0;
        map<int,int> a;
        for(int i=1; i<=n; i++)
        {
            cin>>temp;
            sum+=temp;
            a[temp] = i;
        }

        if(n == 2)
            cout<<"-1\n";
        else
        {
            if(m<n)
                cout<<"-1\n";
            else if(m == n)
            {
                cout<<(2*sum)<<"\n";
                for(int i=1; i<=n; i++)
                {
                    if(i!=n)
                        cout<<i<<" "<<i+1<<"\n";
                    else
                        cout<<i<<" "<<1<<"\n";
                }
            }
            else
            {
                auto ptr = a.begin();
                cout<<(m-n)*( ptr->first + (++ptr)->first) + (2*sum)<<"\n";
                for(int i=1; i<=n; i++)
                {
                    if(i!=n)
                        cout<<i<<" "<<i+1<<"\n";
                    else
                        cout<<i<<" "<<1<<"\n";
                }

                ptr--;
                auto next1 = ptr;
                auto next2 = ++ptr;
                for(int i=1; i<=(m-n); i++)
                {
                    cout<<next1->second<<" "<<next2->second<<"\n";
                }

            }
        }



        t--;
    }

    return 0;
}
