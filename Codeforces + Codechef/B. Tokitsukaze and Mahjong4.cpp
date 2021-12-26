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

int m[15] = {0};
int p[15] = {0};
int s[15] = {0};
void fill_it(string x)
{
    if(x[1] == 'm')
        m[x[0] - 48]++;
    else if(x[1] == 'p')
        p[x[0] - 48]++;
    else
        s[x[0] - 48]++;
}

void show_it()
{
    cout<<"\n---------m------------\n";
    for(int i=1; i<=9; i++)
        cout<<m[i]<<" ";
    cout<<"\n---------p------------\n";
    for(int i=1; i<=9; i++)
        cout<<p[i]<<" ";
    cout<<"\n---------s------------\n";
    for(int i=1; i<=9; i++)
        cout<<s[i]<<" ";
    cout<<"\n----------------------\n";
}

bool check_zero()
{
    for(int i=1; i<=9; i++)
    {
        if( m[i] == 3 || (m[i] == 1 && m[i+1] == 1 && m[i+2] == 1))
            return 1;
    }

    for(int i=1; i<=9; i++)
    {
        if( p[i] == 3 || ( p[i] == 1 && p[i+1] == 1 && p[i+2] == 1 ))
            return 1;
    }

    for(int i=1; i<=9; i++)
    {
        if( s[i] == 3 || (s[i] == 1 && s[i+1] == 1 && s[i+2] == 1))
            return 1;
    }

    return 0;
}

bool check_one()
{
    for(int i=1; i<=9; i++)
    {
        if( (m[i] >= 1 && m[i+1] >= 1) || (m[i-1] >= 1 && m[i] == 0 && m[i+1] >= 1) || m[i] == 2)
            return 1;
    }

    for(int i=1; i<=9; i++)
    {
        if(p[i] >= 1 && p[i+1] >= 1 || (p[i-1] >= 1 && p[i] == 0 && p[i+1] >= 1) || p[i] == 2)
            return 1;
    }

    for(int i=1; i<=9; i++)
    {
        if( s[i] >= 1 && s[i+1] >= 1 || (s[i-1] >= 1 && s[i] == 0 && s[i+1] >= 1) || s[i] == 2)
            return 1;
    }
    return 0;
}
int main()
{
    //GO_FAST
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    fill_it(s1);
    fill_it(s2);
    fill_it(s3);
    //show_it();

    if(check_zero())
        cout<<0<<"\n";
    else
    {
        if(check_one())
            cout<<1<<"\n";
        else
            cout<<2<<"\n";
    }

    return 0;
}
