
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

vector<lli> consequtive_freq_string(string s)
{
    vector<lli> z;
    int i=0;
    while(i < s.length())
    {
        int j=i+1;
        int c=1;
        while(j < s.length() && s[j] == s[i])
        {
            j++;
            c++;
        }
        z.push_back(c);
        i = j;
    }
    return z;
}

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
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;

        lli cost=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '0')
                cost++;
        }

        if(cost == s.length())
            cout<<0<<"\n";
        else
        {

            vector<lli> v =  consequtive_freq_string(s);
            vector<lli> y;


            if(s[0] == '0')
            {
                for(int i=0; i<v.size(); i++)
                {
                    if(i%2 == 0)
                        y.push_back(0);
                    else
                        y.push_back(1);
                }
            }
            else
            {
                for(int i=0; i<v.size(); i++)
                {
                    if(i%2 == 0)
                        y.push_back(1);
                    else
                        y.push_back(0);
                }
            }


            //vector_printer(v);
            //vector_printer(y);

            vector<lli> z(v.size());
            vector<lli> zb(v.size());
            vector<lli> o(v.size());
            vector<lli> ob(v.size());
            lli sum=0;
            for(int i=0; i<z.size(); i++)
            {
                if(y[i] == 0)
                    sum+=v[i];
                z[i] = sum;
            }

            sum=0;
            for(int i=0; i<z.size(); i++)
            {
                if(y[i] == 1)
                    sum+=v[i];
                o[i] = sum;
            }
            sum=0;
            for(int i=z.size()-1; i>=0; i--)
            {
                if(y[i] == 0)
                    sum+=v[i];
                zb[i] = sum;
            }
            sum=0;
            for(int i=z.size()-1; i>=0; i--)
            {
                if(y[i] == 1)
                    sum+=v[i];
                ob[i] = sum;
            }
            lli ans=INT_MAX;
            for(int i=0; i<z.size(); i++)
            {

                if(y[i] == 1)
                {
                    lli aaa = cost;
                    if(i > 0)
                    {
                        aaa += o[i-1];
                        aaa -= z[i-1];
                    }
                    if(i < z.size() - 1 )
                    {
                        aaa += o[i+1];
                        aaa -= z[i+1];
                    }

                    ans = min(ans,aaa);
                }
            }

            cout<<ans<<"\n";
        }

        t--;
    }
    return 0;
}
