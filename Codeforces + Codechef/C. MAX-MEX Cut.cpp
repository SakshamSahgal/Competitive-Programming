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
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;

        char x[2][n];

        for(int i=0; i<n; i++)
            cin>>x[0][i];

        for(int i=0; i<n; i++)
            cin>>x[1][i];

        int c=0;

        for(int i=0; i<n; i++)
        {
            int noo=0;
            int noz=0;

            if(x[0][i] == '1')
                noo++;
            if(x[1][i] == '1')
                noo++;
            if(x[0][i] == '0')
                noz++;
            if(x[1][i] == '0')
                noz++;

            if(noz >= 1 && noo >= 1)
                c+=2;
            else
            {
                if(i+1 < n)
                {
                    if(noz == 2)
                    {
                        if(x[0][i+1] == '1' && x[1][i+1] == '1')
                        {
                            c+=2;
                            i++;
                        }
                        else
                            c++;
                    }
                    else if(noo == 2)
                    {
                        if(x[0][i+1] == '0' && x[1][i+1] == '0')
                        {
                            c+=2;
                            i++;
                        }
                    }
                }
                else
                {
                    if(noz == 2)
                        c++;
                }
            }
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}
