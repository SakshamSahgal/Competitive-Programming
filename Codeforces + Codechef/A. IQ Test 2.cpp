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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
char x[4][4];
for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
    cin>>x[i][j];
int noh=0,nod=0;
for(int i=0;i<=2;i++)
    {
        //cout<<"\n--------------\n";
        for(int j=0;j<=2;j++)
        {
            noh=0;
            nod=0;
            if(x[i][j] == '#')
                noh++;
            else
                nod++;

            if(x[i][j+1] == '#')
                noh++;
            else
                nod++;

            if(x[i+1][j] == '#')
                noh++;
            else
                nod++;

            if(x[i+1][j+1] == '#')
                noh++;
            else
                nod++;
             //cout<<x[i][j]<<x[i][j+1]<<"\n"<<x[i+1][j]<<x[i+1][j+1]<<"\n---\n";
            //cout<<noh<<" "<<nod<<"\n";
            if(noh == 4 || nod == 4 || noh == 1 || nod == 1)
            {
                  cout<<"YES\n";
                  goto h;
            }

        }

        //cout<<"\n--------------\n";
    }
    cout<<"NO\n";
    h:

return 0;
}
