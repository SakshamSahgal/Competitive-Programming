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

//remember to use endl instead of \n for interactive problems.


void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

bool check_p(vector<lli> &p,string &s)
{
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == '-' && p[i] < p[i+1])
            return 0;
        else if(s[i] == '+' && p[i] > p[i+1])
            return 0;
    }
    return 1;
}

void level(lli n)
{
    vector<lli> v;

    for(int i=0; i<=n; i++)
        v.push_back(i+1);
    //vector_printer(v);

    sort(v.begin(),v.end());


    for(lli i=0; i<powl(2,n); i++)
    {
        string s;
        for(int j=0; j<n; j++)
        {
            lli set_b = (i>>j)%2;
            if(set_b)
                s += '+';
            else
                s += '-';
        }
        reverse(s.begin(),s.end());

        lli c=0;
        do
        {
            //cout<<"checking - \n";
            //vector_printer(v);
            if(check_p(v,s))
                c++;

        }
        while(next_permutation(v.begin(),v.end()));
        //cout<<c<<"\n";
        //cout<<"{"<<s<<" , "<<c<<"} ";
    }
    //cout<<"\n";
}


void solve(string s)
{
    vector<lli> v;

    for(int i=1; i<=s.length()+1; i++)
        v.push_back(i);

    vector_printer(v);
    lli c=0;
    do
    {
        if(check_p(v,s))
            c++;
    }
    while(next_permutation(v.begin(),v.end()));
    cout<<c<<"\n";
    //cout<<"{"<<s<<" , "<<c<<"} ";

//cout<<"\n";
}

int main()
{
    GO_FAST

    solve("+-++");
//    for(int i=1; i<=6; i++)
//        level(i);
//    cout<<"done\n";
    //vector<lli> v = {1,2,3,4,5};
//    lli c=0;
//    sort(v.begin(),v.end());
//    do
//    {
//        cout<<"checking - \n";
//        vector_printer(v);
//        if(check_p(v,"-++-"))
//            c++;
//
//    }
//    while(next_permutation(v.begin(),v.end()));
//    cout<<c<<"\n";
    return 0;
}
