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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

pair<lli,pair<lli,lli>> best_ans(vector<lli> &x,lli st,lli ed,lli n)
{
    lli nom2=0;
    lli no2=0;
    lli nom1=0;
    lli first_neg=-1;
    lli last_neg=-1;
    for(int i=0; i<x.size(); i++)
    {
        if(x[i] < 0 && first_neg == -1)
            first_neg = i;

        if(x[i] < 0)
            last_neg = i;

        if(x[i] == -1)
            nom1++;
        else if(x[i] == -2)
            nom2++;
        else if(x[i] == 2)
            no2++;
    }

    if( (nom1 + nom2)%2 == 0)
    {
        pair<lli,pair<lli,lli>> ans;
        ans.first = (no2 + nom2);
        ans.second.first = st;
        ans.second.second = n - ed - 1;
        return ans;
    }
    else
    {
        lli pa1=0;
        lli pa2=0;

        for(int i=first_neg + 1; i<x.size(); i++)
            if(abs(x[i]) == 2)
                pa1++;

        for(int i=0; i<last_neg; i++)
            if(abs(x[i]) == 2)
                pa2++;

        if(pa1 > pa2)
        {
            pair<lli,pair<lli,lli>> ans;
            ans.first = pa1;
            ans.second.first = st + first_neg + 1;
            ans.second.second = n - ed - 1;
            return ans;
        }
        else
        {
            pair<lli,pair<lli,lli>> ans;
            ans.first = pa2;
            ans.second.first = st;
            ans.second.second = n - ed - 1 + x.size() - last_neg;
            return ans;
        }
    }
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        vector<lli> z;
        z.push_back(-1);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] == 0)
                z.push_back(i);
        }
        z.push_back(n);
        vector<pair<lli,pair<lli,lli>>> v;
        for(int i=0; i<z.size()-1; i++)
        {
            vector<lli> temp;

            for(lli j=z[i]+1; j<=z[i+1]-1; j++)
                temp.push_back(a[j]);
            //vector_printer(temp);
            if(temp.size() != 0)
            {
                lli st = z[i]+1;
                lli ed = z[i+1]-1;
                pair<lli,pair<lli,lli>> pw = best_ans(temp,st,ed,n);
                v.push_back(pw);
                //cout<<" for this = 2^"<<pw.first<<" removing = {"<<pw.second.first<<" , "<<pw.second.second<<"} \n";
            }
        }
        if(v.size() != 0)
        {
            sort(v.begin(),v.end());
            cout<<v[v.size()-1].second.first<<" "<<v[v.size()-1].second.second<<"\n";
        }
        else
            cout<<n<<" "<<0<<"\n";

        t--;
    }
    return 0;
}

