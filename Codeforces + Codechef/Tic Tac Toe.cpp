#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
char board[3][3];



bool win(char c)
{
    int counterc=0;
    int counterr=0;

//checking in coloumn
    for(int i=0; i<3; i++)
    {
        counterc = 0;
        counterr = 0;
        for(int j=0; j<3; j++)
        {
            if(board[j][i] == c)
                counterc++;
            if(board[i][j] == c)
                counterr++;
        }
        if(counterc == 3 || counterr == 3)
            return 1;
    }
    if( ( (board[0][0] == c && board[1][1] == c && board[2][2] == c ) && !(board[2][0] == c && board[1][1] == c && board[0][2] == c )) || ( !(board[0][0] == c && board[1][1] == c && board[2][2] == c ) && (board[2][0] == c && board[1][1] == c && board[0][2] == c )) )
        return 1;
    else
        return 0;
}
bool Draw(int nob)
{
    if( nob == 0 && win('X') == 0 && win('O') == 0)
        return 1;
    else
        return 0;
}
bool possible(int nox,int noo)
{
    if(nox>5 || noo>4 || noo > nox || (nox - noo) > 1)
    {
        //cout<<"NO because = "<<"(nox>5 || noo>4 || abs(nox-noo) > 1)\n";
          return 0;
    }

    else
    {
        if(win('X') == 1 && win('O') == 1)
        {
           // cout<<"NO because all win\n";
            return 0;
        }
        else
        {
            if(win('X') == 1)
            {
                if( nox - noo == 1)
                    return 1;
                else
                    return 0;
            }
            if(win('O') == 1)
            {
                if(nox == noo)
                    return 1;
                else
                    return 0;
            }
            return 1;
        }
    }
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int nox=0;
        int noo=0;
        int nob=0;
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                cin>>board[i][j];
                if(board[i][j] == 'X')
                    nox++;
                if(board[i][j] == 'O')
                    noo++;
                if(board[i][j] == '_')
                    nob++;
            }
        }
     //  cout<<"Possible = "<<possible(nox,noo)<<"\n";
        if(possible(nox,noo) == 0)
            cout<<3<<"\n";
        else
        {
            if(Draw(nob) == 1 || win('X') == 1 || win('O') == 1)
                cout<<1<<"\n";
            else
                cout<<2<<"\n";
        }
        t--;
    }

    return 0;
}
