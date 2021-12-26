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
        int n,m,k;
        cin>>k>>n>>m;
        int noz=0;
        vector<int> a;
        vector<int> b;
        int x;
        int maxx = INT_MIN;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            a.push_back(x);
            if(x == 0)
                noz++;
            if(x > maxx)
                maxx = x;
        }

        for(int i=0; i<m; i++)
        {
            cin>>x;
            b.push_back(x);
            if(x == 0)
                noz++;
            if(x > maxx)
                maxx = x;
        }

        if( (k+noz) < maxx )
            cout<<"-1";
        else
        {
            vector<int> c;
l:
            if(a.size() != 0 && b.size() != 0)
            {
                if(a[0]<b[0])
                {
                    c.push_back(a[0]);
                    a.erase(a.begin());
                }
                else
                {
                    c.push_back(b[0]);
                    b.erase(b.begin());
                }
            }
            else
            {
                if(a.size() == 0 && b.size() != 0)
                {
                    for(int i=0; i<b.size(); i++)
                    {
                        c.push_back(b[i]);
                    }
                    goto k;
                }
                else if(a.size() != 0 && b.size() == 0)
                {
                    for(int i=0; i<a.size(); i++)
                    {
                        c.push_back(a[i]);
                    }
                    goto k;
                }
                else
                    goto k;
            }

            goto l;

k:
            noz = 0;

            for(int i=0; i<c.size(); i++)
            {
                if(c[i] == 0)
                    noz++;
                else if((k+noz) < c[i])
                {
                    cout<<"-1";
                    goto h;
                }

            }

            for(int i=0; i<c.size(); i++)
                cout<<c[i]<<" ";

        }
h:
        cout<<"\n";
        t--;
    }

    return 0;
}

