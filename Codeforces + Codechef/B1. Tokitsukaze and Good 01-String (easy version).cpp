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

vector<lli> consequtive_freq(string s){
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
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;
        vector<lli> cf = consequtive_freq(s);
        vector<lli> odd;
        for(int i=0;i<cf.size();i++)
        {
            if(cf[i]%2)
                odd.push_back(i);
        }
        lli ans=0;
        for(int i=0;i<odd.size();i+=2)
            ans += odd[i+1] - odd[i];
        cout<<ans<<"\n";

        t--;
    }
    return 0;
}
