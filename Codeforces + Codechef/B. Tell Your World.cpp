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

void display(map<pair<lli,lli>,vector<pair<lli,lli>>> &x)
{
    for(auto i:x)
    {
        cout<<"{ "<<i.first.first<<"/"<<i.first.second<<" } -> ";
        for(auto j:i.second)
            cout<<" {"<<j.first<<"/"<<j.second<<"} ";
        cout<<"\n";
    }
}

bool is_possible(lli *y,lli n,lli mn,lli md,lli cn1,lli cd1,lli cn2,lli cd2)
{
    lli cc1=0;
    lli cc2=0;
    for(int i=0; i<n; i++)
    {
        lli x = i+1;
        lli lhs1 = y[i]*md*cd1;
        lli rhs1 = mn*cd1*x + md*cn1;

        lli lhs2 = y[i]*md*cd2;
        lli rhs2 = mn*cd2*x + md*cn2;

        if( (lhs1 == rhs1) || (lhs2 == rhs2) )
        {
            if(lhs1 == rhs1)
                cc1++;
            else
                cc2++;
        }
        else
            return 0;
    }
    if(cc1 == 0 || cc2 == 0)
        return 0;
    else
        return 1;
}
int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    lli y[n];

    for(int i=0; i<n; i++)
        cin>>y[i];

    map<pair<lli,lli>,vector<pair<lli,lli>>> all;//m_num,m_deno , c_num,c_deon
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            lli num = (y[j]-y[i]);
            lli deno = (j - i);
            lli m_num = num/__gcd(abs(num),abs(deno));
            lli m_deno = deno/__gcd(abs(num),abs(deno));
            num = y[i]*m_deno - m_num*(i+1);
            deno = m_deno;
            lli c_num = num/__gcd(num,deno);
            lli c_deno = deno/__gcd(num,deno);
            cout<<" with "<<y[i]<<" & "<<y[j]<<" m = "<<m_num<<"/"<<m_deno<<" c = "<<c_num<<"/"<<c_deno<<"\n";
            all[ {m_num,m_deno}].push_back({c_num,c_deno});
        }
    }

    display(all);
    if(all.size() == 1)
        cout<<"-1\n";
    else
    {
        for(auto i:all)
        {
            if(i.second.size() > 1)
            {
                for(lli j=0; j<i.second.size(); j++)
                {
                    for(lli k=j+1; k<i.second.size(); k++)
                    {
                        lli mn = i.first.first;
                        lli md = i.first.second;
                        lli cn1 = i.second[j].first;
                        lli cd1 = i.second[j].second;
                        lli cn2 = i.second[k].first;
                        lli cd2 = i.second[k].second;
                        if(is_possible(y,n,mn,md,cn1,cd1,cn2,cd2))
                        {
                            cout<<"Possible with "<<" m = "<<mn<<"/"<<md<<" c = "<<cn1<<"/"<<cd1<<" , "<<cn2<<"/"<<cd2<<" , ";
                        }
                    }
                }
            }

        }
    }
    return 0;
}

