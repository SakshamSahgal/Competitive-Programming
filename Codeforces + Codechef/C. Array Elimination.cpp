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
int Eular_GCD(int a,int b)
{
    int temp;
x:
    if(a!=0 && b!=0)
    {
        temp = a;
        a = b;
        b = temp%b;
        goto x;
    }
    else
        return max(a,b);
}

void set_printer(set<lli> x)
{
    // cout<<"\n---------------------------\n";
    for(auto i =x.begin(); i!=x.end(); i++)
        cout<<*i<<" ";
    //cout<<"\n---------------------------\n";
}

set<lli> factor_it(lli n)
{
    set<lli> factors;
    for(lli i=1; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            factors.insert(i);
            factors.insert(n/i);
        }
    }
    return factors;
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        set<lli> ans;
        ans.insert(1);
        map<lli,lli> f;
        bool all_z=1;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] != 0)
                all_z = 0;
            f[a[i]]++;
        }

        if(all_z == 1)
        {
            for(int i=1; i<=n; i++)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
        {
            auto ptr = f.begin();

            if(ptr->first == 0)
                ptr++;

            lli g = ptr->second;

            for(auto i:f)
            {
                if(i.second != 0)
                    g = Eular_GCD(g,i.second);
            }



            //cout<<g<<"\n";

            ans = factor_it(g);
            set_printer(ans);
            cout<<"\n";
        }


        t--;
    }
    return 0;
}
