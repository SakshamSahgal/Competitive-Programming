#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
struct point
{
short int x;
short int y;
bool uf=0;
bool df =0;
bool rf=0;
bool lf=0;
};

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n;
cin>>n;
vector <point> v(n);
usi c=0;
usi x,y;
for(usi i=0;i<n;i++)
    {
    cin>>x>>y;
     v[i].x = x;
     v[i].y = y;
     v[i].uf = 0;
     v[i].df = 0;
     v[i].rf = 0;
     v[i].lf = 0;
    }
for(usi i=0;i<n;i++)
    {
    for(usi j=0;j<n;j++)
        {
            if(j!= i)
            {
                if(v[j].x == v[i].x)
                {
                    if(v[j].y>v[i].y)
                        v[i].uf = 1;
                    else
                        v[i].df = 1;
                }
            if(v[j].y == v[i].y)
                {
                    if(v[j].x>v[i].x)
                        v[i].rf = 1;
                    else
                        v[i].lf = 1;
                }
            }

        }
        if(v[i].lf == 1 && v[i].rf == 1 && v[i].uf == 1 && v[i].df == 1)
            {
            //cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].uf<<" "<<v[i].df<<" "<<v[i].rf<<" "<<v[i].lf<<"\n";
            c++;
            }

    }
/*
cout<<"\n";

for(usi i=0;i<v.size();i++)
    cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].uf<<" "<<v[i].df<<" "<<v[i].rf<<" "<<v[i].lf<<"\n";
*/
cout<<c;
return 0;
}
