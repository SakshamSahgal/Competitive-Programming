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
    char tile_visual[50][50];
    int tile_val[50][50];
    int values[50][50];
    int si,sj;
    cin>>si>>sj;
    for(int i=0; i<50; i++)
    {
        for(int j=0; j<50; j++)
            {
             cin>>tile_val[i][j];
            tile_visual[i][j] = '*';
            }

    }

    for(int i=0; i<49; i++)
    {
        for(int j=0; j<49; j++)
        {
            if(tile_val[i][j] == tile_val[i+1][j])
            {
                tile_visual[i][j] = '|';
                tile_visual[i+1][j] = '|';
            }
            else if(tile_val[i][j] == tile_val[i-1][j])
            {
                tile_visual[i][j] = '|';
                tile_visual[i-1][j] = '|';
            }
            else if(tile_val[i][j] == tile_val[i][j+1])
            {
                tile_visual[i][j] = '-';
                tile_visual[i][j+1] = '-';
            }
            else if(tile_val[i][j] == tile_val[i][j-1])
            {
                tile_visual[i][j] = '-';
                tile_visual[i][j-1] = '-';
            }
        }

    }

    cout<<"\n-----------------------------------tile visual-----------------------------------\n";

    for(int i=0; i<50; i++)
    {
        for(int j=0; j<50; j++)
            cout<<tile_visual[i][j];

        cout<<"\n";
    }

     cout<<"\n---------------------------------------------------------------------------------\n";


    for(int i=0; i<50; i++)
    {
        for(int j=0; j<50; j++)
            cin>>values[i][j];
    }

    return 0;
}

