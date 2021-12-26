#include<iostream>
#include<algorithm>
#include<cstring>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
int main()
{
ui n,k;
cin>>n>>k;
char a[n];
ui kc = k;
getchar();//clear buffer
for(ui i=0;i<n;i++)
    {
    scanf("%c",&a[i]);
    if( a[i] == '#' )
        kc--;
    else
        kc = k;

   // cout<<"\n"<<kc<<" ";
    if(kc == 0)
        {
        cout<<"NO\n";
        return 0;
        }
    }
cout<<"YES\n";
return 0;
}
