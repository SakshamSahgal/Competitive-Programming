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

vector<int> no_to_vector(lli n)
{
    vector<int> v;
    while(n!=0)
    {
        v.push_back(n%10);
        n/=10;
    }
    reverse(v.begin(),v.end());
    return v;
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
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


lli counter = 0;
void Calc_Dp(vector<vector<int>> x,lli cur)
{
    lli nod = x[0].size();

    if(cur == -1)
    {
        Vec_2d_printer(x);
        counter++;
        return;
    }
    map<pair<int,int>,int> done;
    for(int i=0; i<=9; i++)
    {
        for(int j=0; j<=9; j++)
        {
            lli ans = (i + j + x[0][cur]);
            if( ans%10 == x[3][cur] )
            {
                if(ans > 9)
                {
                    if(cur - 2 >= 0)
                    {
                        x[0][cur-2] = 1;
                        x[1][cur] = i;
                        x[2][cur] = j;
                        if(done[ {i,j}] != 1 && done[ {j,i}] != 1)
                        {
                            done[ {i,j}] = 1;
                            Calc_Dp(x,cur-1);
                        }
                    }
                }
                else
                {
                    x[1][cur] = i;
                    x[2][cur] = j;
                    if(done[ {i,j}] != 1 && done[ {j,i}] != 1)
                    {
                        done[ {i,j}] = 1;
                        Calc_Dp(x,cur-1);
                    }
                }
            }
        }
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
        counter=0;
        vector<int> v = no_to_vector(n);
        vector<vector<int>> x(4,vector<int>(v.size()));
        x[3] =  v;
        Calc_Dp(x,v.size()-1);
        cout<<<<"\n";
        t--;
    }
    return 0;
}

