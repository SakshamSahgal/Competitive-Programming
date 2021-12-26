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


int main()
{
    //GO_FAST
    lli t;
    cin>>t;
    while(t--)
    {
        vector<string> s(9);
        for(int i=0;i<9;i++)
            cin>>s[i];

        if(s[0][0] == '1')
            s[0][0] = '2';
        else
            s[0][0] = '1';

        if(s[1][3] == '1')
            s[1][3] = '2';
        else
            s[1][3] = '1';

        if(s[2][6] == '1')
            s[2][6] = '2';
        else
            s[2][6] = '1';

        if(s[3][1] == '1')
            s[3][1] = '2';
        else
            s[3][1] = '1';


        if(s[4][4] == '1')
            s[4][4] = '2';
        else
            s[4][4] = '1';

        if(s[5][7] == '1')
            s[5][7] = '2';
        else
            s[5][7] = '1';

        if(s[6][2] == '1')
            s[6][2] = '2';
        else
            s[6][2] = '1';

        if(s[7][5] == '1')
            s[7][5] = '2';
        else
            s[7][5]= '1';

        if(s[8][8] == '1')
            s[8][8] = '2';
        else
            s[8][8]= '1';

        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
                cout<<s[i][j];
            cout<<"\n";
        }
    }

    return 0;
}
