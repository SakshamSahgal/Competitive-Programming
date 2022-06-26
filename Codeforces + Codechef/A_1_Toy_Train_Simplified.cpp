#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;


vector<pair<lli,lli>> hash_tb(201); //from to
lli cur_ind;
lli cur_size;

lli index_to_dist(lli hash_index)
{
    lli from = cur_ind;
    lli to = hash_tb[hash_index].second;
    if(from < to)
        return to-from;
    else
        return (cur_size + to - from);
}



bool my_comp(lli a,lli b)
{
    return (index_to_dist(a) < index_to_dist(b));
}

void display_graph(vector<vector<lli>>v)
{
    line_printer(20);
    for(int i=0; i<v.size(); i++)
    {
        cout<<i<<" -> ";
        for(int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
    line_printer(20);
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,m;
    cin>>n>>m;
    cur_size = n;
    vector<vector<lli>> v(n);
    set<lli> rem;

    for(int i=0; i<m; i++)
    {
        lli a,b;
        cin>>a>>b;
        a--;
        b--;
        hash_tb[i] = {a,b};
        v[a].push_back(i);
        rem.insert(i);
    }

    for(int i=0; i<n; i++)
    {
        cur_ind = i;
        sort(v[i].begin(),v[i].end(),my_comp);
    }

    // display_graph(v);


    for (int st = 0; st < n; st++)
    {
        lli moves = 0;
        int i = st;
        set<pair<lli,lli>> bag; //to , hash index
        set<lli> temp_rem = rem;
        vector<vector<lli>> temp_v = v;
        //cout<<"i = "<<i<<"\n";
        while (temp_rem.size())
        {
            if(temp_v[i].size())
            {
                lli pick = temp_v[i][(temp_v[i].size() - 1)];
                //cout<<"picking -> { "<<hash_tb[pick].second<<" , "<<pick<<" } \n";
                temp_v[i].pop_back();
                bag.insert({hash_tb[pick].second, pick});
            }

            while (1)
            {
                //cout<<"i = "<<i<<" \n";
                pair<lli, lli> z = {i, -inf};
                auto ptr = bag.lower_bound(z);
               // if(ptr != bag.end())
               // {
                    if ( (ptr->first) != i )
                        break;
                    else if (( ptr->second < 0 || ptr->second >= m ) )
                        break;
                    else
                    {
                        //cout<<"throwing -> {"<<ptr->first<<" , "<<ptr->second<<"}\n";
                        lli hash_index = ptr->second;
                        temp_rem.erase(temp_rem.find(hash_index));
                        bag.erase(ptr);
                    }
               // }

            }
            //line_printer(10);
            moves++;
            i++;
            if (i == n)
                i = 0;
        }
        cout<<moves-1<<" ";
    }

    return 0;
}
