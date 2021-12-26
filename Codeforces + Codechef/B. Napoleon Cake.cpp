#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
struct Cake
{
    int L;
    int U;
};
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
        int a[n];
        int l,u;
        vector<Cake> index;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] != 0)
            {
                if(index.size() == 0)
                {
                    l = max(0,i-a[i]+1);
                    u = i;
                    index.push_back({l,u});
                }
                else
                {
                    l = max(i-a[i]+1,0);
                    u = i;

                    if(l>= index[index.size()-1].U )
                        index.push_back({l,u});
                    else if(l <= index[index.size()-1].U && l >= index[index.size()-1].L )
                    {
                         index[index.size()-1].U = u;
                    }
                    else
                    {
                        index[index.size()-1].L = l;
                        index[index.size()-1].U = u;
                    }
                }
            }
        }
        int c[n] = {0};
        for(int i=0; i<index.size(); i++)
        {
           // cout<<index[i].L<<" "<<index[i].U<<"\n";
            for(int j=index[i].L;j<=index[i].U;j++)
                    c[j] = 1;
        }

        for(int i=0; i<n; i++)
            cout<<c[i]<<" ";
        cout<<"\n";
        t--;
    }

    return 0;
}
