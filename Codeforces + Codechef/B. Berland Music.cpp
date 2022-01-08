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
        vector<lli> lik;
        set<lli> disl;
        vector<lli> odisl;
        vector<lli> p(n);
        map<lli,lli> x;
        map<lli,lli> y;
        string s;
        for(int i=0; i<n; i++)
            cin>>p[i];

        cin>>s;


        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '0')
            {
                disl.insert(p[i]);
                odisl.push_back(p[i]);
            }
            else
                lik.push_back(p[i]);
        }

        if(odisl.size() == 0 || lik.size() == 0)
        {
            for(int i=0; i<n; i++)
                cout<<p[i]<<" ";
        }
        else
        {
            sort(lik.begin(),lik.end(),greater<int>());
            sort(odisl.begin(),odisl.end());

            //vector_printer(lik);

            for(int i=0; i<lik.size(); i++)
            {
                //cout<<"Comapring "<<lik[i]<<" "<<(*disl.rbegin())<<"\n";
                if(lik[i] <  (*disl.rbegin()))
                {
                    lli temp = (*disl.rbegin());
                    disl.erase(disl.find(temp));
                    disl.insert(lik[i]);
                    x[lik[i]] = temp;
                    lik[i] = temp;
                }
                else
                   x[lik[i]] = lik[i];

            }

            auto ptr = disl.begin();
            for(int i=0; i<odisl.size(); i++)
            {
                y[odisl[i]] = *ptr;
                ptr++;
            }

            for(int i=0; i<n; i++)
            {
                if(s[i] == '0')
                    cout<<y[p[i]]<<" ";
                else
                    cout<<x[p[i]]<<" ";
            }
        }
        cout<<"\n";
        t--;
    }
    return 0;
}
