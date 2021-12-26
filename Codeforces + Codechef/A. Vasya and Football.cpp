#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void array_printer(int n,int a[])
{
    cout<<"\n---------------\n";
    for(int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<"\n---------------\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string home,away;
    cin>>home>>away;
    int n;
    cin>>n;
    int h[100]= {0};
    int a[100]= {0};

    for(int i=1; i<=n; i++)
    {
        int t,player_no;
        char card,team;
        cin>>t>>team>>player_no>>card;
        if(team == 'h')
        {
            if(h[player_no] != -1)
            {
                if(card == 'y')
                {
                    h[player_no]+=1;

                    if(h[player_no] == 2)
                    {
                        cout<<home<<" "<<player_no<<" "<<t<<"\n";
                        h[player_no] = -1;
                    }
                }
                else
                {
                    cout<<home<<" "<<player_no<<" "<<t<<"\n";
                    h[player_no] = -1;
                }
            }
        }

        else
        {
            if(a[player_no] != -1)
            {
                if(card == 'y')
                {
                    a[player_no]+=1;

                    if(a[player_no] == 2)
                    {
                        cout<<away<<" "<<player_no<<" "<<t<<"\n";
                        a[player_no] = -1;
                    }
                }
                else
                {
                    cout<<away<<" "<<player_no<<" "<<t<<"\n";
                    a[player_no] = -1;
                }
            }
        }

        //array_printer(99,h);
    }



    return 0;
}
