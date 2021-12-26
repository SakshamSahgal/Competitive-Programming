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
        lli x1,p1,x2,p2;
        cin>>x1>>p1>>x2>>p2;
        string a = to_string(x1);
        string b = to_string(x2);
        lli d1 = a.length() + p1;
        lli d2 = b.length() + p2;

        if(d1 > d2)
        {
            cout<<">";
            goto k;
        }

        else if( d1 < d2)
        {
            cout<<"<";
            goto k;
        }
        else
        {
            for(int i=0; i<max(a.length(),b.length()); i++)
            {
                char ca,cb;

                if( i < a.length())
                    ca = a[i];
                else
                    ca = '0';

                if( i < b.length())
                    cb = b[i];
                else
                    cb = '0';


                if(ca < cb)
                {
                    cout<<"<";
                    goto k;
                }
                else if(ca > cb)
                {
                    cout<<">";
                    goto k;
                }
            }
        }

        cout<<"=";
k:
        cout<<"\n";
        t--;
    }
    return 0;
}
