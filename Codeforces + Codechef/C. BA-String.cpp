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

void Done_print(vector<lli> b,string s)
{
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] == 'a')
            cout<<s[i];
        else
        {
            for(int j=0; j<b[i]; j++)
                cout<<'b';
        }
    }
    cout<<"\n";
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void print_all(string s,vector<lli> b,vector<lli> prefix,lli i)
{
    k:
    if(s[i] == '*')
    {
        if(b[i] < k)
            b[i]++;
        else
        {
            i--;
            goto k;
        }

    }
    else
    {
        if()
    }

}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,k,x;
        cin>>n>>k>>x;
        string s;
        cin>>s;
        vector<lli> b(n,0);
        vector<lli> prefix(n,0);
        vector_printer(b);
        lli sum=0;
        cin>>s;


        if(x == 1)
        {
            for(int i=0; i<s.length(); i++)
                if(s[i] == 'a')
                    cout<<s[i];
            cout<<"\n";
        }
        else
        {
            for(int i=0;i<s.length();i++)
            {
                if(s[i] == '*')
                    sum++;
                prefix[i] = sum;
            }

        }



        t--;
    }
    return 0;
}
