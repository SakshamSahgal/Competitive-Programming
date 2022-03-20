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
lli inf = 9e18;

void Map_printer(map<lli,pair<lli,lli>> x)
{
    cout<<"\n----------------------\n";
    for(auto i:x)
        cout<<i.first<<" ("<<i.second.first<<" "<<i.second.second<<")"<<"\n";
    cout<<"\n----------------------\n";
}

void rem_pairs_for_free(map<lli,pair<lli,lli>> &m)
{
    for(auto &&i:m) //equal walo ko kaata with 0 cost
    {
        if(i.second.first != 0 && i.second.second != 0)
        {
            if(i.second.second >= i.second.first)
            {
                i.second.second = i.second.second - i.second.first;
                i.second.first = 0;
            }
            else
            {
                i.second.first = i.second.first - i.second.second;
                i.second.second = 0;
            }
        }
    }
}

void change_color_with_one_cost(map<lli,pair<lli,lli>> &m,lli sa,lli sb)
{
    if(sa > sb)
    {
        for(auto &&i:m)
        {
            i.second.second = 0;
            if(i.second.first%2 && sb >0)
            {
                i.second.first-=1;
                sb--;
            }
        }

        if(sb > 0)
        {
            for(auto &&i:m)
            {
                if(i.second.first >= sb)
                {
                    i.second.first -= sb;
                    sb = 0;
                    break;
                }
                else
                {
                    sb -= i.second.first;
                    i.second.first = 0;
                }
            }
        }
    }
    else
    {
        for(auto &&i:m)
        {
            i.second.first = 0;
            if(i.second.second%2 && sa >0)
            {
                i.second.second-=1;
                sa--;
            }
        }

        if(sa > 0)
        {
            for(auto &&i:m)
            {
                if(i.second.second >= sa)
                {
                    i.second.second -= sa;
                    sa = 0;
                    break;
                }
                else
                {
                    sa -= i.second.second;
                    i.second.second = 0;
                }
            }
        }
    }

}

void convert_remaining_pairs_with_one_cost(map<lli,pair<lli,lli>> &m,lli &ans)
{

    for(auto &&i:m)
    {
        if(i.second.first != 0)
        {
            ans += i.second.first/2;
            i.second.first -= (i.second.first/2)*2;
        }
        else if(i.second.second !=0)
        {
            ans += i.second.second/2;
            i.second.second -= (i.second.second/2)*2;
        }
    }

}
int main()
{
    GO_FAST
    int t;
    cin>>t;

    while(t)
    {
        lli n,l,r;
        cin>>n>>l>>r;
        lli c[n];
        map<lli,pair<lli,lli>> m;
        for(int i=0; i<n; i++)
        {
            cin>>c[i];
            if(i < l)
                m[c[i]].first++;
            else
                m[c[i]].second++;
        }

        //cout<<"original\n";
        //Map_printer(m); //original

        rem_pairs_for_free(m);
        //cout<<"equal walo ko kaata with 0 cost\n";
        //Map_printer(m);

        lli ans=0;

        lli sa=0,sb=0;

        for(auto i:m)
        {
            sa += i.second.first;
            sb += i.second.second;
        }

        if(sa == sb)
            ans += sa;
        else
        {
            ans += min(sa,sb);
            change_color_with_one_cost(m,sa,sb);
            //cout<<"change color with 1 cost optimally so that only pairs remains \n";
            //Map_printer(m);

            convert_remaining_pairs_with_one_cost(m,ans);
            //cout<<"change colors of rem pairs with 1 cost\n";
            //Map_printer(m);

            lli a=0,b=0;
            for(auto i:m) //changing color + pair with 2 cost
            {
                if( i.second.first == 0 && i.second.second == 1 )
                    a++;
                else if( i.second.first == 1 && i.second.second == 0 )
                    b++;
            }

            ans +=  min(a,b) + (max(a,b) - min(a,b));

        }

        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
