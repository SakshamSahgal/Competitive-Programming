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

void matrix_printer(int r,int c,int *x)
{
    cout<<"\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<*((x+i*c)+j)<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}

lli fast_Power(lli a,lli b,lli n)
{
    lli res = 1;
    while(b>0)
    {
        if((b&1) != 0) //b is odd
            res = ((res%n)*(a%n))%n;

        a = ((a%n)*(a%n))%n;
        b = b>>1; //b = b/2
    }
    return res;
}



int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        int a[2][n];

        map<lli,lli> up; //no index

        for(int i=0; i<n; i++)
        {
            cin>>a[0][i];
            up[a[0][i]] = i;
        }

        for(int i=0; i<n; i++)
            cin>>a[1][i];

        lli c = -1;
        lli st = a[0][0];
        lli done = 0;
        for(int i=0; i<n; i++)
        {
            if(a[0][i] > 0)
            {
                lli st = i;
                lli next = a[1][i];
                a[0][i] = c;
                a[1][i] = c;
                int j = up[next];
                done++;
                do
                {
                    next = a[1][j];
                    a[0][j] = c;
                    a[1][j] = c;
                    j = up[next];
                    done++;
                }
                while(j != st);

                if(done != n)
                    c--;
            }
        }

        //matrix_printer(2,n,(int *)a);
        cout<<fast_Power((lli)2,(lli)abs(c),1000000007)<<"\n";

        t--;
    }
    return 0;
}
