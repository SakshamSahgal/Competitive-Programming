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

bool is_possible(lli n,lli x)
{
    if(n%2 == 0)
    {
        if( (n/2 - 1) >= x )
            return 1;
        else
            return 0;
    }
    else
    {
        if( (n/2) >= x )
            return 1;
        else
            return 0;
    }
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> a(n);
        vector<lli> b;
        map<lli,lli> x;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];

            if(a[i] > n)
                b.push_back(a[i]);
            else
            {
                if( x[a[i]] == 0 )
                    x[a[i]] = 1;
                else
                    b.push_back(a[i]);
            }
        }

        sort(b.begin(),b.end());
        //vector_printer(b);
        lli c=0;

        if( b.size() != (n - x.size()) )
        {
            cout<<"-1\n";
            goto l;
        }


        for(int i=n,j=b.size()-1; i>=1; i--)
        {
            if(x[i] == 0)
            {
                if(j >= 0)
                {
                    if( !is_possible(b[j],i) )
                    {
                        cout<<"-1\n";
                        goto l;
                    }
                    else
                    {
                        j--;
                        c++;
                    }
                }
                else
                {
                    cout<<"-1\n";
                    goto l;
                }
            }
        }

        cout<<c<<"\n";
l:
        t--;
    }
    return 0;
}
