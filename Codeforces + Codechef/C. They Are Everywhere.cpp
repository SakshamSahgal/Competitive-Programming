#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<unordered_set>
#include<unordered_map>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

lli char_to_index(char x)
{
    if(x >= 'a' && x <= 'z')
        return (x - 'a');
    else
        return (x - 'A' + 26);
}

bool range(lli l,lli r,vector<vector<lli>> &f,unordered_set<char> &dist)
{
    for(auto i:dist)
    {
        lli freq;
        if(l == 0)
            freq = f[char_to_index(i)][r];
        else
            freq = f[char_to_index(i)][r] - f[char_to_index(i)][l-1];

        if(freq <= 0)
            return 0;
    }
    return 1;
}

bool is_possible(lli len,lli n,vector<vector<lli>> &f,unordered_set<char> &dist)
{
    for(int l=0;l<n;l++)
    {
        lli r = l + len - 1;
        if(r < n)
        {
            if(range(l,r,f,dist))
                return 1;
        }
        else
            break;
    }
    return 0;
}


char index_to_char(lli x)
{
    if(x>=0 && x<=25)
        return ( 'a' + x );
    else
        return ( 'A' + x - 26);
}

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}
int main()
{
    lli n;
    cin>>n;
    string s;
    cin>>s;

    vector<vector<lli>> f(52);
    map<char,lli> freq;
    unordered_set<char> dist;

    for(int i=0;i<n;i++)
        dist.insert(s[i]);


    for(int i=0; i<n; i++)
    {
        freq[s[i]]++;
        for(int j=0;j<52;j++)
             f[j].push_back(freq[index_to_char(j)]);
    }

    //Vec_2d_printer(f);

    lli low=dist.size();
    lli high=n;
    lli ans=n;

    while(low <= high)
    {
        lli mid = (low+high)/2;
        //cout<<"trying mid = "<<mid<<"\n";
        if( is_possible(mid,n,f,dist) )
        {
           // cout<<"possible\n";
            ans = mid;
            high = mid-1;
        }
        else
            low = mid+1;//cout<<"not possible\n";
    }
    cout<<ans<<"\n";
    return 0;
}

