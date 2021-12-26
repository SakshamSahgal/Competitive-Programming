#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int switch_it(int x)
{
    if(x == 1)
        return 0;
    else
        return 1;

}

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

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    string s;
    cin>>s;
    int max_time = 2520;
    int toggle[n][max_time];
    int a[n];
    int b[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        cin>>b[i];
    }

    for(int i=0; i<n; i++)
    {
        vector<pair<int,int>> time;
        //cout<<"\n";
        for(int st = 0,ed = b[i] - 1; ed<max_time; st = ed + 1,ed+=a[i])
        {
            //cout<<st<<" "<<ed<<"\n";
            time.push_back({st,ed});
        }

        int initial = s[i] - 48;

        for(int j=0; j<time.size(); j++)
        {

            for(int k=time[j].first; k<=time[j].second; k++)
                toggle[i][k] = initial;

            initial = switch_it(initial);
        }

        for(int k = time[time.size()-1].second + 1; k<=max_time-1; k++)
            toggle[i][k] = initial;

    }

    //matrix_printer(n,max_time,(int*)toggle );

    int c=0;
    int maxx=INT_MIN;
    for(int t=0;t<max_time;t++)
    {
        c=0;
        for(int i=0;i<n;i++)
        {
            if(toggle[i][t] == 1)
                c++;
        }
        if(c>maxx)
            maxx = c;
    }

    cout<<maxx<<"\n";

    return 0;
}
