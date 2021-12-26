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
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        vector<lli> a(n);
        vector<lli> index;
        lli sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum += a[i];
            if(a[i] > 0)
                index.push_back(i);
        }

        // vector_printer(a);
        // vector_printer(index);

        lli ans=0;
        if(index.size() == 0)
        {
        cout<<ans<<"\n";
        }
        else{

          for(int i=0; i<n; i++)
        {
            lli aage_index;
            lli peeche_index;
            auto aage = lower_bound(index.begin(),index.end(),i);
            auto peeche = upper_bound(index.begin(),index.end(),i);
            if(aage == index.end())
                aage_index = *index.begin();
            else
                aage_index = *aage;
            if( peeche == index.begin())
                peeche_index = *index.rbegin();
            else
                peeche_index = *(--peeche);

            lli peeche_dist;
            lli aage_dist;

            if(peeche_index > i)
                peeche_dist = n + i - peeche_index;
            else
                peeche_dist = i - peeche_index;

            if(aage_index < i)
                aage_dist = n - i + aage_index;
            else
                aage_dist = aage_index - i;

            if(  2*(k - min(peeche_dist,aage_dist)) > 0 )
                ans += 2*(k - min(peeche_dist,aage_dist));
            //cout<<"for i = "<<i<<" peeche = "<<peeche_index<<" "<<"aage = "<<aage_index<<" p dist = "<<peeche_dist<<" aage dist = "<<aage_dist<<"\n";
        }

        cout<<sum + ans<<"\n";

        }


        t--;
    }
    return 0;
}
