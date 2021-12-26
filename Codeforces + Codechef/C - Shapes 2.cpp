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
int a=0;
int c=0;
template<typename T>
void input_2d_vec(lli r,lli c, vector<vector<T>> &x,vector<vector<T>> &m2,vector<vector<T>> &m3,vector<vector<T>> &m4)
{
    for(int i=0; i<r; i++)
    {
        vector<T> x1;
        vector<T> x2;
        vector<T> x3;
        vector<T> x4;
        for(int j=0; j<c; j++)
        {
            T tt;
            cin>>tt;
            x1.push_back(tt);
            if(tt == '#')
                c++;

            x2.push_back('.');
            x3.push_back('.');
            x4.push_back('.');
        }
        x.push_back(x1);
        m2.push_back(x2);
        m3.push_back(x3);
        m4.push_back(x4);
    }
    cout<<"Nikla\n";
}

void rotate_all_dir(vector<vector<char>> &mat1,vector<vector<char>> &mat2,vector<vector<char>> &mat3,vector<vector<char>> &mat4)
{
    int n = mat1.size();
    for(int i=0; i<mat1.size(); i++)
    {
        for(int j=0; j<mat1[i].size(); j++)
        {
            mat2[j][n - (i+1)] = mat1[i][j];
            mat3[n - (i+1)][n - (j+1)] = mat1[i][j];
            mat4[n - (j+1)][n - (n - (i+1) + 1)] = mat1[i][j];
        }
    }
}

template<typename G>

void inp(lli r,lli c, vector<vector<G>> &x)
{
    for(int i=0; i<r; i++)
    {
        vector<G> row;
        for(int j=0; j<c; j++)
        {
            G tt;
            cin>>tt;
            if(tt == '#')
                a++;
            row.push_back(tt);
        }
        x.push_back(row);
    }
}

pair<lli,lli>  tpl(vector<vector<char>> &x)
{
    int n = x.size();

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(x[i][j] == '#')
            {
                lli ii = i;
                lli jj = j;
                pair<lli,lli> temp;
                temp.first = ii;
                temp.second = jj;
                return temp;
            }
        }
    }
}


bool shifter(vector<vector<char>> &S,vector<vector<char>> &ans)
{
    int n = S.size();
    pair<lli,lli> tps = tpl(S);
    pair<lli,lli> tpt = tpl(ans);

    int Si = tps.first;
    int Sj = tps.second;

    int Ti = tpt.first;
    int Tj = tpt.second;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            int ii = i + Ti - Si;
            int jj = j + Tj - Sj;
            if(ii >=0 && ii<n && jj>= 0 && jj<=n)
            {
                if (S[i][j] != ans[ii][jj])
                    return false;

            }
            else
                {
                    if(ans[ii][jj] == '#')
                        return false;
                }
        }
    }

    return true;

}

int main()
{
    GO_FAST
    lli n;
    cin>>n;
    vector<vector<char>>mat1;
    vector<vector<char>>mat2;
    vector<vector<char>>mat3;
    vector<vector<char>>mat4;
    vector<vector<char>>ans;

    input_2d_vec(n,n,mat1,mat2,mat3,mat4);
    //rotate_all_dir(mat1,mat2,mat3,mat4);
    //inp(n,n,ans);
    Vec_2d_printer(mat1);
    Vec_2d_printer(mat2);
    Vec_2d_printer(mat3);
    Vec_2d_printer(mat4);
    /*
    if(a != c)
        cout<<"NO\n";
    else
    {
        if(c == 1)
            cout<<"YES\n";
        else
        {
            if(shifter(mat1,ans) || shifter(mat2,ans) || shifter(mat3,ans) || shifter(mat4,ans) )
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    } */

    return 0;
}
