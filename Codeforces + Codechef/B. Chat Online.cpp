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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int p,q,l,r;
    cin>>p>>q>>l>>r;
    vector<pair<int,int>> ab;
    vector<pair<int,int>> cd;
    int x,y;
    for(int i=0; i<p; i++)
    {
        cin>>x>>y;
        ab.push_back(make_pair(x,y));
    }

    for(int i=0; i<q; i++)
    {
        cin>>x>>y;
        cd.push_back(make_pair(x,y));
    }
    /*
    cout<<"\n--------ab-------\n";

    for(int i=0; i<p; i++)
        cout<<ab[i].first<<" "<<ab[i].second<<"\n";

    cout<<"\n--------cd-------\n";
    for(int i=0; i<q; i++)
        cout<<cd[i].first<<" "<<cd[i].second<<"\n";

    cout<<"\n-----------------\n"; */

    int c=0;
    int tt[1001] = {0};
    for(int i=0; i<q; i++)
    {

        for(int j=0; j<p; j++)
        {
            for(int t=l; t<=r; t++)
            {
                if(tt[t] == 0)
                {
                    if( ( (cd[i].first+t) >=  ab[j].first && (cd[i].first+t) <=  ab[j].second ) ||  ( (cd[i].second+t) >=  ab[j].first && (cd[i].second+t) <=  ab[j].second ) ||  ((cd[i].first+t)<=ab[j].first && (cd[i].second+t)>=ab[j].second )    )
                    {
                        c++;
                        tt[t] = 1;
                        //cout<<"matched at i = "<<i<<"j = "<<j<<" t = "<<t<<"\n";
                    }
                }

            }

        }
    }
    cout<<c<<"\n";
    return 0;
}

