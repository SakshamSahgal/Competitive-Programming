#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.

vector<vector<lli>> calc(vector<vector<lli>> &mat)
{
    lli M = mat.size();
    lli N = mat[0].size();
    vector<vector<int>> sum(M, vector<int>(N));
    sum[0][0] = mat[0][0];
    for (lli j = 1; j < N; j++)
    {
        sum[0][j] = mat[0][j] + sum[0][j - 1];
    }
    for (lli i = 1; i < M; i++)
    {
        sum[i][0] = mat[i][0] + sum[i - 1][0];
    }
    for (lli i = 1; i < M; i++)
    {
        for (lli j = 1; j < N; j++)
            sum[i][j] = mat[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
    }
    return sum;
}

int fs(vector<vector<int>> const &mat, int p, int q, int r, int s)
{
    if (mat.size() == 0)
        return 0;
    vector<vector<int>> sum = preprocess(mat);
    int total = sum[r][s];
    if (q - 1 >= 0)
        total -= sum[r][q - 1];
    if (p - 1 >= 0)
        total -= sum[p - 1][s];
    if (p - 1 >= 0 && q - 1 >= 0)
        total += sum[p - 1][q - 1];
    return total;
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

        lli n,m;
        cin>>n>>m;
        vector<vector<lli>> v(1001,vector<lli>(1001,0));
        for(int i=0; i<n; i++)
        {
            lli h,w;
            cin>>h>>w;
            v[h][w] = h*w;
        }
        calc(v);
        while(m--)
        {
            lli hs,ws,hb,wb;
            cin>>hs>>ws>>hb>>wb;
            lli p = hs+1;
            lli r = hb-1;
            lli q = ws+1;
            lli s = wb-1;
            if(p < q && r < s)
                cout << fs(mat, p, q, r, s)<<"\n";
            else
                cout<<0<<"\n";
        }


        t--;
    }
    return 0;
}

