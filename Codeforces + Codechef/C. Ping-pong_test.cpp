#include<iostream>
#include<algorithm>
#include<vector>
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
    int x,y;
    cin>>x>>y;
    int c=0;
    int a=0;
    int b=0;
    char last_win = '-';
    char last_move = '-';
g:
    if(x!=0 || y!=0)
    {
        cout<<x<<" "<<y<<"\n";
        if(c==0)
        {
            cout<<"A chala\n";
            last_move = 'A';
            x--;
            c++;
            goto g;
        }
        else
        {
            if(c%2 == 1) //B ki bari
            {
                if(y<=x && last_win != 'B')
                {
                    cout<<"B lets A win\n";
                    last_win = 'A';
                    a++;
                    c++;
                    goto g;
                }
                else
                {
                    cout<<"B chala\n";
                    last_move = 'B';
                    last_win = '-';
                    y--;
                    c++;
                    goto g;
                }
            }
            else //A ki bari
            {
                if(x<=y && last_win != 'A')
                {
                    cout<<"A lets B win\n";
                    last_win = 'B';
                    b++;
                    c++;
                    goto g;
                }
                else
                {
                    cout<<"A chala\n";
                    last_move = 'A';
                    last_win = '-';
                    x--;
                    c++;
                    goto g;
                }

            }
        }
    }
    if(last_move == 'A')
        a++;
    else
        b++;
    cout<<a<<" "<<b<<"\n";
    return 0;
}
