#include<iostream>
using namespace std;

class word
{
public:
    int n,m;
    string *mat;
    string s;
    bool **vis;
    int *posx;
    int *posy;
    int f=0;
    bool is_possible(int i,int j)
    {
        if(i < 0 || j < 0 || i >= n || j >= m)
            return 0;
        else
            return 1;
    }

     void calc(int i,int j,int c)
    {
        cout<<mat[i][j]<<" ";

        if(s[c] == mat[i][j])
        {
            vis[i][j] = 1;
            c++;
        }

        if(c == s.length())
        {
            cout<<"Found\n";
            return;
        }

        if(is_possible(i+1,j) && !vis[i+1][j] && s[c] == mat[i+1][j]) //DOWN
            calc(i+1,j,c);
        else if(is_possible(i,j+1) && !vis[i][j+1] && s[c] == mat[i][j+1]) //RIGHT
            calc(i,j+1,c);
        else if(is_possible(i-1,j) && !vis[i-1][j] && s[c] == mat[i-1][j]) //UP
            calc(i-1,j,c);
        else if(is_possible(i,j-1) && !vis[i][j-1] && s[c] == mat[i][j-1]) //LEFT
            calc(i,j-1,c);

        vis[i][j] = 0;
    }


    search_it()
    {
        for(int i=0; i<f; i++)
        {
            //cout<<"trying from = "<<posx[i]<<" "<<posy[i]<<"\n";
            calc(posx[i],posy[i],0);
        }


    }



    word()
    {
        cin>>n>>m;
        mat = new string[n];
        vis = new bool*[n];
        posx = new int[n*m];
        posy = new int[n*m];

        for(int i=0; i<n; i++)
            vis[i] = new bool [m];


        for(int i=0; i<n; i++)
        {
            string temp;
            cin>>temp;
            mat[i] = temp;
        }

        cout<<"\n";
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cout<<mat[i][j];
            cout<<"\n";
        }
        cout<<"\n";

        cin>>s;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(mat[i][j] == s[0])
                {
                    //cout<<"{"<<i<<" , "<<j<<"\n";
                    int id = f;
                    posx[id] = i;
                    posy[id] = j;
                    f++;
                }
            }
        }

        search_it();
    }



};

int main()
{
    word w;
    return 0;
}
