#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    int a,b;
    cin>>a>>b;
    int x=b;
    int y = b+1;
    int u = 0;
    g:
    int movesx = 0+u;
    int movesy = 1+u;

    int temp1 = a;
    int temp2 = a;

    while(temp1 != 0)
        {
            if(x == 1)
                {
                x++;
                y++;
                u++;
                movesx++;
                movesy++;
                }
            else
                {
                 temp1 /= x;
                 movesx++;
                }
        }
    while(temp2 != 0)
        {
            temp2 /=y;
            movesy++;
        }
    cout<<movesx<<" "<<movesy<<"\n";
    if(movesx<=movesy)
        {
            cout<<movesx;
        }
    else
        {
            x++;
            y++;
            u++;
            goto g;
        }
    t--;
    }



return 0;
}
