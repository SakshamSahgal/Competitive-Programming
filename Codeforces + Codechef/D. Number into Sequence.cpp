#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;



void pair_printer(vector<pair<lli,lli>> v)
{
cout<<"\n------------pair------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n-------------------------------\n";
}


vector<pair<lli,lli>> prime_factorisation(lli n)
{
    vector<pair<lli,lli>> p;
    if(n == 1)
        return p;
    else
    {
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i == 0)
            {
                int c=0;
                while(n%i == 0)
                {
                    n=n/i;
                    c++;
                }
                p.push_back({i,c});
            }
        }

        if(n != 1)
            p.push_back({n,1});

        return p;
    }

}

bool sort_by_Freq(pair<lli,lli> a,pair<lli,lli> b)
{
    return (a.second>b.second);
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
        vector<pair<lli,lli>> p;
        p = prime_factorisation(n);
        sort(p.begin(),p.end(),sort_by_Freq);
        //pair_printer(p);
        auto ptr = p.begin();
        cout<<(ptr->second)<<"\n";
        for(int i = 0 ; i < ptr->second - 1;i++)
            cout<<ptr->first<<" ";
        cout<<(setprecision(20))<<(n / pow((ptr->first),ptr->second - 1))<<"\n";
        t--;
    }
    return 0;
}
