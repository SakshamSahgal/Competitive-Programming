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
        int n;
        cin>>n;
        vector<lli> a;
        vector<lli> b;

        for(int i=0;i<n;i++)
        {
            lli x;
            cin>>x;
            a.push_back(x);
        }

        b = a;


        while(a.size() > 2)
        {
            auto ptr = a.begin();
            lli x = *ptr;
            ptr++;
            lli y = *ptr;
            a.erase(a.begin());
            a.erase(a.begin());
            a.insert(a.begin(),(x^y));
            //vector_printer(a);
            if(all_Equal(a) == 1)
            {
                cout<<"YES\n";
                goto h;
            }
        }


        while(b.size() > 2)
        {

        }

        cout<<"NO\n";

        h:
        t--;
    }
    return 0;
}


