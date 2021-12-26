#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int h,w,x,y;
cin>>h>>w>>x>>y;
char grid[h][w];
for(int i=0;i<h;i++)
    {
    string s;
    cin>>s;
    for(int j=0;j<w;j++)
            grid[i][j] = s[j];
    }
/*
cout<<"\n";
for(int i=0;i<h;i++)
    {
        for(int j=0;j<w;j++)
        cout<<grid[i][j];
    cout<<"\n";
    } */
int c=0;
for(int i=x-2;i>=0;i--) //upar
    {
        if(grid[i][y-1] == '.')
            c++;
        else
            break;
    }
//cout<<c<<" \n";
for(int i=x;i<h;i++) //neeche
    {
        if(grid[i][y-1] == '.')
            c++;
        else
            break;
    }
//cout<<c<<" \n";
for(int j=y;j<w;j++) //right
    {
        if(grid[x-1][j] == '.')
            c++;
        else
            break;
    }
//cout<<c<<" \n";
for(int j=y-2;j>=0;j--) //left
    {
        if(grid[x-1][j] == '.')
            c++;
        else
            break;
    }
cout<<c+1<<" \n";
return 0;
}

