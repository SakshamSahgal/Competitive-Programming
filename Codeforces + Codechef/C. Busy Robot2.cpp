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
lli duration(int st,int ed)
{
    return abs((ed - st));
}

void printer(map<pair<lli,lli>,pair<lli,lli>> x)
{
    for(auto i:x)
        cout<<"("<<i.first.first<<" "<<i.first.second<<") "<<i.second.first<<" to "<<i.second.second<<"\n";
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

struct ytime
{
lli st;
lli ed;
lli s_pos;
lli ed_pos;
};

lli timeer(lli st, lli ed,lli st_time,lli your_time)
{

    if(st == ed)
        return st;
    else
    {
        if(st > ed)
        return (st - (your_time - st_time));
        else
        return (st + (your_time - st_time));
    }
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli stt=0;
        lli lst_dur=0;
        map<pair<lli,lli>, pair<lli,lli>> dur;
        vector<pair<lli,lli>> vv;
        vector<lli> st;
        vector<lli> ed;
        vector<pair<lli,lli>> range;
        for(int i=0; i<n; i++)
        {
            lli tt,x;
            cin>>tt>>x;
            vv.push_back({tt,x});
            if(i == 0)
            {
                dur[ {0,tt} ] = {0,0};
                st.push_back(0);
                ed.push_back(tt);
                range.push_back({0,0});
                lst_dur = tt + duration(stt,x);

                if(x >= stt)
                {
                    dur[ {tt+1,lst_dur}] = {stt+1,x};
                    st.push_back(tt+1);
                    ed.push_back(lst_dur);
                    range.push_back({stt+1,x});
                }
                else
                {
                    dur[ {tt+1,lst_dur}] = {stt-1,x};
                    st.push_back(tt+1);
                    ed.push_back(lst_dur);
                    range.push_back({stt-1,x});
                }
                stt = x;
            }
            else
            {
                if(lst_dur <= tt)
                {
                    if(lst_dur < tt)
                    {
                        dur[ {lst_dur + 1,tt} ] = {stt,stt};
                        st.push_back(lst_dur+1);
                        ed.push_back(tt);
                        range.push_back({stt,stt});
                    }


                    lst_dur = tt + duration(stt,x);

                    if(i < n-1)
                    {
                        if(x >= stt)
                        {
                            dur[ {tt+1,lst_dur}] = {stt+1,x};
                            st.push_back(tt+1);
                            ed.push_back(lst_dur);
                            range.push_back({stt+1,x});
                        }
                        else
                        {
                            dur[ {tt+1,lst_dur}] = {stt-1,x};
                            st.push_back(tt+1);
                            ed.push_back(lst_dur);
                            range.push_back({stt-1,x});
                        }
                    }
                    else
                    {
                        if(x >= stt)
                        {
                            dur[ {tt+1,lst_dur}] = {stt+1,x};
                            st.push_back(tt+1);
                            ed.push_back(lst_dur);
                            range.push_back({stt+1,x});
                        }
                        else
                        {
                            dur[ {tt+1,lst_dur}] = {stt-1,x};
                            st.push_back(tt+1);
                            ed.push_back(lst_dur);
                            range.push_back({stt-1,x});
                        }
                    }
                    stt = x;
                }
            }
        }


        if( dur.rbegin()->first.second != INT_MAX)
        {
            lli t1 = dur.rbegin()->first.second + 1;
            lli x = dur.rbegin()->second.second;
            dur[ { t1, INT_MAX } ] = {x,x};
            st.push_back(t1);
            ed.push_back(INT_MAX);
            range.push_back({x,x});
        }

        for(int i=0; i<n; i++)
        {
            lli lri;
            lli uri;
            if(i < n-1)
            {
                auto ptr = lower_bound( st.begin(),st.end(), vv[i].first );
                lri = ptr - st.begin();

                if( *ptr > vv[i].first )
                    lri--;

                auto ptr2 = lower_bound( ed.begin(),ed.end(), vv[i+1].first );
                uri = ptr2 - ed.begin();
            }
            else
            {
                auto ptr = lower_bound( st.begin(),st.end(), vv[i].first );
                lri = ptr - st.begin();

                if( *ptr > vv[i].first )
                    lri--;

                auto ptr2 = lower_bound( ed.begin(),ed.end(), INT_MAX );
                uri = ptr2 - ed.begin();
            }

            cout<<"lri = "<<lri<<" uri = "<<uri<<"\n";
            lli mini = INT_MAX;
            lli maxx = INT_MIN;
            for(int i=lri; i<=uri; i++)
            {
                if(i == lri)
                {
                   // minii = min(timeer( range[i].first ,range[i].second , )
                }
            }
            // cout<<"minii = "<<minii<<" maxxx = "<<maxxx<<"\n";
        }

        printer(dur);

        t--;
    }
    return 0;
}
