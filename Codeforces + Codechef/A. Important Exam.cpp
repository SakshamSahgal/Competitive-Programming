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

struct f
{
    lli fa;
    lli fb;
    lli fc;
    lli fd;
    lli fe;
    f()
    {
        fa=0;
        fb=0;
        fc=0;
        fd=0;
        fe=0;
    }
};
int main()
{
    //GO_FAST
    lli n,m;
    cin>>n>>m;
    char x[n][m];
    f freq[m];
    lli a[m];

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>x[i][j];




    for(int i=0; i<m; i++)
    {
        f temp;
        for(int j=0; j<n; j++)
        {

            if(x[j][i] == 'A')
                temp.fa++;
            if(x[j][i] == 'B')
                temp.fb++;
            if(x[j][i] == 'C')
                temp.fc++;
            if(x[j][i] == 'D')
                temp.fd++;
            if(x[j][i] == 'E')
                temp.fe++;
        }
         freq[i] = temp;
    }

    lli sum=0;
    for(int i=0; i<m; i++)
    {
        cin>>a[i];
       // cout<<freq[i].fa<<" "<<freq[i].fb<<" "<<freq[i].fc<<" "<<freq[i].fd<<" "<<freq[i].fe<<"\n";
        lli aa = (freq[i].fa) * a[i];
        lli bb = (freq[i].fb) * a[i];
        lli cc = (freq[i].fc) * a[i];
        lli dd = (freq[i].fd) * a[i];
        lli ee = (freq[i].fe) * a[i];
        sum += max(max(max(aa,bb),max(cc,dd)),ee);
       // cout<<sum<<"\n";
    }

    cout<<sum<<"\n";


    return 0;
}
