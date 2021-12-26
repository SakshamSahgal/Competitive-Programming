#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi n;
cin>>n;
usi a[n][2];
bool check=0;

for(int i=0;i<n;i++)
    cin>>a[i][0]>>a[i][1];
for(int i=0;i<n;i++)
    {
        if(a[i][0] != a[i][1])
            {
            cout<<"rated\n";
            return 0;
            }

        if(i<(n-1))
            {
                if(a[i][0]<a[i+1][0] && check == 0)
                    check = 1;
            }
    }

if(check == 1)
    cout<<"unrated\n";
else
    cout<<"maybe\n";
return 0;
}
