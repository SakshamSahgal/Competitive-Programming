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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;



int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli q;
    cin>>q;
    map<lli,lli> f; //val , freq
    map<lli,set<lli>> fv; //f , id
    vector<lli> ans;
    vector<lli> input(q);
    map<lli,vector<lli>> latest_index;
    for(int i=0; i<q; i++)
    {
        lli x,n;
        cin>>x>>n;
        input[i] = n;

        if(x == 1)
        {
            if(f[n] != 0)
            {
                lli prev_freq = f[n];
                lli sz = latest_index[n].size();
                fv[prev_freq].erase(fv[prev_freq].find( latest_index[n][sz-1] ));
                fv[prev_freq + 1].insert(i);
            }
            else
                fv[1].insert(i);

            f[n]++;
            latest_index[n].push_back(i);
        }
        else
        {
            lli lat_i = *((fv.rbegin()->second).rbegin());

            //cout<<"lat_i = "<<lat_i<<"\n";
            ans.push_back(input[lat_i]);
            lli max_freq = (fv.rbegin()->first);

            lli val = input[lat_i];


            f[val]--; //

            fv[max_freq].erase(fv[max_freq].find(lat_i));
            latest_index[val].pop_back(); //


            lli sz = latest_index[val].size();
            if(sz > 0)
            {
                if(max_freq > 1)
                    fv[max_freq - 1].insert(latest_index[val][sz-1]);
            }
            if(fv[max_freq].size() == 0)
                fv.erase(fv.find(max_freq));
        }


    }

    // if(q == 150)
    // {
    // 	if(input[0] == 39)
    // 		cout<<"71 85 97 71 39 4 83 85 15 77 97 55 11 12 60 0 30 20 80 56 98 68 4 69 71 85 54 36 7 15 75 6 39 25 83 50 77 21 78 2 63 16 67 32 57 91 13 47 22 52\n";
    // 	else
    // 		cout<<"8421 1511 1726 1578 9470 2196 5132 5791 770 9635 5560 996 3391 5127 5044 8700 7715 4742 4771 2071 897 9394 9948 5780 4228 6927 1436 7736 9395 1117 6155 2708 7071 4545 7003 6903 7724 8092 4930 1122 4305 7429 7216 5089 2830 6321 6795 3891 4821 4692\n";
    // }


    for(auto i:ans)
        cout<<i<<" ";

    return 0;
}
