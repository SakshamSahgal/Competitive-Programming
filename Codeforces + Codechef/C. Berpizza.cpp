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

void printer( multimap<lli,lli> x )
{
    cout<<"\nNOW\n";
    cout<<"\n-------------------------\n";
    for(auto i:x)
        cout<<i.first<<" "<<i.second<<"\n";
    cout<<"\n-------------------------\n";
}


int main()
{
    GO_FAST

    multimap<lli,lli> s; // val index
    map<lli,lli> oppo; //index val
    set<lli> index_ava; //set of distinct index
    lli q;
    cin>>q;
    int index=1;
    for(lli i=1; i<=q; i++)
    {
        int c;
        cin>>c;

        if(c == 1)
        {
            lli x;
            cin>>x;
            s.insert({x,index});
            oppo[index] = x;
            index_ava.insert(index);
            index++;
        }
        else if(c == 2)
        {
            lli smallest_index = *index_ava.begin();
            lli val_of_smallest_index = oppo[smallest_index];
            cout<<smallest_index<<" ";
            //cout<<"smallest ava index = "<<smallest_index<<" with val = "<<val_of_smallest_index<<"\n";
            auto itr_s_smlst_index = s.lower_bound(val_of_smallest_index);
            auto itr_opp_with_smlst_index = oppo.find(smallest_index);

            s.erase(itr_s_smlst_index);
            index_ava.erase(index_ava.begin());
            oppo.erase(itr_opp_with_smlst_index);
        }
        else
        {
            lli maxx_element_val = ((*s.rbegin()).first);
            auto itr_s_with_max_ele_min_index = s.lower_bound(maxx_element_val);
            lli maxx_element_index = itr_s_with_max_ele_min_index->second;
            cout<<maxx_element_index<<" ";
            auto itr_oppo_with_max_ele_min_index = oppo.find(maxx_element_index);
            auto itr_indexava_with_max_ele_min_index = index_ava.find(maxx_element_index);
            s.erase(itr_s_with_max_ele_min_index);
            oppo.erase(itr_oppo_with_max_ele_min_index);
            index_ava.erase(itr_indexava_with_max_ele_min_index);
        }
        //printer(s);
    }
    return 0;
}
