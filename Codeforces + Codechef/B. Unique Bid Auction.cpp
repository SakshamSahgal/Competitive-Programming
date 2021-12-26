#include<iostream>
#include<vector>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    ui n;
    cin>>n;
    ui a[n];
    ui b[n];
    for(ui i=0;i<n;i++)
        {
        cin>>a[i];
        b[i] = a[i];
        }
    sort(a,a+n);
    bool got_ya = 0;
    ui last_index=0;
   for(ui i=0;i<n;i+=(last_index+1))
    {
    last_index = 0;
    got_ya = 0;
    for(ui j=i+1;j<n;j++)
        {

        if(a[i] == a[j] && i!=j)
            {
            got_ya = 1;
            last_index++;
            if(a[j+1] != a[i])
                {
                    break;
                }
            }
        }
    if(got_ya == 0)
        {
            for(ui k=0;k<n;k++)
                {
                if(a[i] == b[k])
                    {
                    cout<<(k+1)<<"\n";
                    goto y;
                    }

                }
        }

    }
    cout<<"-1\n";
    y:
    n=n;
        }


return 0;
}
