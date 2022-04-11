#include<iostream>
using namespace std;


class word
{
public:
    int n,m;
    int **vis;
    string *mat;
    string s;


    bool is_poss(int i,int j)
    {
        if(i < 0 || j < 0 || i >= n || j >= m)
            return 0;
        else
            return 1;
    }

    void calc(int i,int j,int c)
    {

        vis[i][j] = 1;
        //cout<<mat[i][j]<<" ";
        if(c == s.length()-1)
        {
            cout<<"Found\n";
            return;
        }

        if(is_poss(i,j+1) && !vis[i][j+1] && mat[i][j+1] == s[c+1])
            calc(i,j+1,c+1);
        else if(is_poss(i+1,j) && !vis[i+1][j] && mat[i+1][j] == s[c+1])
            calc(i+1,j,c+1);
        else if(is_poss(i,j-1) && !vis[i][j-1] && mat[i][j-1] == s[c+1])
            calc(i,j-1,c+1);
        else if(is_poss(i-1,j) && !vis[i-1][j] && mat[i-1][j] == s[c+1])
            calc(i-1,j,c+1);
        else
            vis[i][j] = 0;
    }

    word()
    {
        cin>>n>>m;
        mat = new string[n];
        vis = new int*[n];

        for(int i=0; i<n; i++)
            vis[i] = new int[m];

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                vis[i][j] = 0;

        for(int i=0; i<n; i++)
        {
            string temp;
            cin>>temp;
            mat[i] = temp;
        }

        cin>>s;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == s[0])
                {
                    //cout<<"{"<<i<<" , "<<j<<"}\n";
                    calc(i,j,0);
                }
            }
        }
    }


};

int main()
{

    word w;
    w;
    return 0;
}
