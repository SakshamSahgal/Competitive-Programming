#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

bool all_Equal(vector<lli> v)
{
    for(int i=0; i<v.size(); i++)
    {
        if(v[i] != v[0])
            return 0;
    }
    return 1;
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> a;

        for(int i=0; i<n; i++)
        {
            lli x;
            cin>>x;
            a.push_back(x);
        }

        while( a.size() > 2 )
        {
            vector<lli> v;
            if(a.size()%2 == 1)
            {
                for(int i=0; i<a.size(); i+= 2)
                {

                    if(i + 1 < a.size())
                    {
                        cout<<"taking "<<a[i]<<"^"<<a[i+1]<<" = "<<(a[i]^a[i+1])<<"\n";
                        v.push_back(a[i]^a[i+1]);
                    }
                }
                lli last = *(a.rbegin());
                v.push_back(last);
                a = v;
            }
            else
            {
                for(int i=0; i<a.size(); i+= 2)
                {
                    if(i + 1 < a.size())
                    {
                        cout<<"taking "<<a[i]<<"^"<<a[i+1]<<" = "<<(a[i]^a[i+1])<<"\n";
                        v.push_back(a[i]^a[i+1]);
                    }
                }

                a = v;
            }
            vector_printer(a);

            if(all_Equal(a) == 1)
            {
                cout<<"YES\n";
                goto h;
            }

        }

        cout<<"NO\n";
        h:
        t--;
    }
    return 0;
}


