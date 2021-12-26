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

bool comparator(pair<lli,lli> a,pair<lli,lli> b)
{
    return(a.second<b.second);
}

void Graph_Printer(map<lli,vector<pair<lli,lli>>> x)
{
    cout<<"\n-------------------\n";
    for(auto i:x)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<"("<<j.first<<" "<<j.second<<") ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
}

struct rects
{
    pair<lli,lli> a;
    pair<lli,lli> b;
    pair<lli,lli> c;
    pair<lli,lli> d;
};

bool exist(vector<rects> &ans,pair<lli,lli> aa,pair<lli,lli> bb,pair<lli,lli> cc,pair<lli,lli> dd)
{

    for(auto i:ans)
    {

        lli aac=0;
        lli bbc=0;
        lli ccc=0;
        lli ddc=0;

        if(aa == i.a || aa == i.b || aa == i.c || aa == i.d)
            aac++;

        if(bb == i.a || bb == i.b || bb == i.c || bb == i.d)
            bbc++;

        if(cc == i.a || cc == i.b || cc == i.c || cc == i.d)
            ccc++;

        if(dd == i.a || dd == i.b || dd == i.c || dd == i.d)
            ddc++;

        if( (aac + bbc + ccc + ddc) == 4)
            return 1;
    }
    return 0;
}

int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    map<lli,vector<pair<lli,lli>>> vl;
    map<lli,vector<pair<lli,lli>>> hl;
    vector<pair<lli,lli>> points;
    map<pair<lli,lli>,lli> pp;

    for(int i=0; i<n; i++)
    {
        lli x,y;
        cin>>x>>y;
        pp[ {x,y}] = 1;
        points.push_back({x,y});
        vl[x].push_back({x,y});
        hl[y].push_back({x,y});
    }

    for(auto i:vl)
        sort(i.second.begin(),i.second.end(),comparator);

    for(auto i:hl)
        sort(i.second.begin(),i.second.end());

    //Graph_Printer(vl);
    //Graph_Printer(hl);

    vector<rects> ans;

    for(int i=0; i<n; i++)
    {
        //cout<<"trying = ("<<points[i].first<<" "<<points[i].second<<")\n";
        for( auto vy:vl[points[i].first] )
        {
            for(auto hx:hl[points[i].second])
            {
                pair<lli,lli> pi = {points[i].first,points[i].second};
                pair<lli,lli> vv = {vy.first,vy.second};
                pair<lli,lli> hh = {hx.first,hx.second};

                if(pi != vv && pi != hh)
                {
                    //cout<<"vl - ("<<vy.first<<" "<<vy.second<<") hl = ( "<<hx.first<<" "<<hx.second<<") \n";
                    pair<lli,lli> want = {hx.first,vy.second};

                    if(pp[want] == 1 && exist(ans,pi,vv,hh,want) == 0)
                        ans.push_back({pi,vv,hh,want});
                }
            }
        }

    }


    cout<<ans.size()<<"\n";
   // for(auto i:ans)
       // cout<<"("<<i.a.first<<" "<<i.a.second<<") ("<<"("<<i.b.first<<" "<<i.b.second<<") ("<<i.c.first<<" "<<i.c.second<<") ("<<i.d.first<<" "<<i.d.second<<")\n";

    return 0;
}
