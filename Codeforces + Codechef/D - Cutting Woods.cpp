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



int main()
{
    GO_FAST
    set<lli> cut;
    lli l,q;
    cin>>l>>q;
    cut.insert(0);
    cut.insert(l);

    for(lli i=0; i<q; i++)
    {
        lli c,x;
        cin>>c>>x;
        if(c == 1)
            cut.insert(x);
        else
        {
            auto peeche = cut.upper_bound(x);
            auto aage = cut.lower_bound(x);
            if(peeche != cut.begin())
                peeche--;

            if(aage == cut.end())
                aage--;

        //cout<<"Peeche = "<<*peeche<<"aage = "<<*aage<<"\n";
        cout<<*aage - *peeche<<"\n";
        }




    }
    return 0;
}
