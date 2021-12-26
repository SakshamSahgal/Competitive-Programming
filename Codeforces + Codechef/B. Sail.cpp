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

int t,sx,sy,ex,ey;
cin>>t>>sx>>sy>>ex>>ey;
char c;
int ans = -1;
for(int i=1;i<=t;i++)
{
    cin>>c;
    if(sx > ex && c == 'W')
        sx--;
    else if(sx < ex && c == 'E')
        sx++;
    else if(sy > ey && c == 'S')
        sy--;
    else if(sy < ey && c == 'N')
        sy++;

    //cout<<"Coordinates = ("<<sx<<" "<<sy<<") \n";
    if(sx == ex && sy == ey && ans == -1)
        ans = i;

}
cout<<ans<<"\n";
return 0;
}

