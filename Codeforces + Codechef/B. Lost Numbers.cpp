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


pair<int,int> possibility(int ans)
{
    int a[6] = {4,8,15,16,23,42};

    for(int i=0; i<6; i++)
    {
        for(int j=i+1; j<6; j++)
        {
            //cout<<a[i]<<"*"<<a[j]<<" = "<<a[i]*a[j]<<"\n";
            if( (a[i]*a[j]) == ans )
            {
                pair<int,int> p1;
                p1.first = a[i];
                p1.second = a[j];
                return p1;
            }

        }

    }
}

int main()
{
    //GO_FAST
    lli ans[6];
    {
        int x1,x2;
        cout<<"? 1 2\n";
        cin>>x1;
        int a,b,c,d;

        pair<int,int> p1 = possibility(x1);
        a = p1.first;
        b = p1.second;
        cout<<"? 2 3\n";
        cin>>x2;
        pair<int,int> p2 = possibility(x2);
        c = p2.first;
        d = p2.second;

        if(a == c)
        {
            ans[0] = b;
            ans[1] = a;
            ans[2] = d;
        }
        else if(a == d)
        {
            ans[0] = b;
            ans[1] = a;
            ans[2] = c;
        }
        else if(b == c)
        {
            ans[0] = a;
            ans[1] = b;
            ans[2] = d;
        }
        else
        {
            ans[0] = a;
            ans[1] = b;
            ans[2] = c;
        }
    }

    {
        int x1,x2;
        cout<<"? 4 5\n";
        cin>>x1;
        int a,b,c,d;
        pair<int,int> p1 = possibility(x1);
        a = p1.first;
        b = p1.second;
        cout<<"? 5 6\n";
        cin>>x2;
        pair<int,int> p2 = possibility(x2);
        c = p2.first;
        d = p2.second;

        if(a == c)
        {
            ans[3] = b;
            ans[4] = a;
            ans[5] = d;
        }
        else if(a == d)
        {
            ans[3] = b;
            ans[4] = a;
            ans[5] = c;
        }
        else if(b == c)
        {
            ans[3] = a;
            ans[4] = b;
            ans[5] = d;
        }
        else
        {
            ans[3] = a;
            ans[4] = b;
            ans[5] = c;
        }
    }
    cout<<"! ";
    for(auto i:ans)
        cout<<i<<" ";

    return 0;
}
