#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void Priority_Queue_Printer(priority_queue<lli> x)
{
    cout<<"\n----------------------\n";
    while(!x.empty())
    {
        cout<<x.top()<<"\n";
        x.pop();
    }
    cout<<"\n----------------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        priority_queue<lli> q;
        lli n;
        cin>>n;
        lli a[n];
        map<lli,lli> f;
        for(lli i=0; i<n; i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }

        for(auto i:f)
            q.push(i.second);

       // Priority_Queue_Printer(q);

        while(q.size() > 1)
        {
            lli x = q.top();
            q.pop();
            lli y = q.top();
            q.pop();
            x--;
            y--;

            if(x>0)
                q.push(x);
            if(y>0)
                q.push(y);

           // Priority_Queue_Printer(q);
        }

        if(q.size() == 0)
            cout<<0<<"\n";
        else
            cout<<q.top()<<"\n";

        t--;
    }
    return 0;
}
