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

string generator(char s,int i)
{
    string ss;
    ss += s;
    ss += to_string(i);
    return ss;
}


map<string,lli> fm;
map<string,lli> fp;
map<string,lli> fs;

void add_to(string s)
{
    if(s[1] == 'm')
        fm[s]++;
    else if(s[1] == 'p')
        fp[s]++;
    else if(s[1] == 's')
        fs[s]++;
}

void Map_printer(map<string,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}


bool three_check()
{
    for(auto i:fm)
    {
        if(i.second >= 3)
            return 1;
    }
    for(auto i:fp)
    {
        if(i.second >= 3)
            return 1;
    }
    for(auto i:fs)
    {
        if(i.second >= 3)
            return 1;
    }
    return 0;
}

bool one_check()
{
    lli a1=-1;
    lli a2=-1;
    lli a3=-1;
    for(auto i:fs)
    {
        lli no = i.first[0] - 48;
        if(i.second == 1)
        {
            if( fs[generator('s',no+1)] >= 1 && fs[generator('s',no-1)] >= 1 )
                return 0;
            else
            {
                if( fs[generator('s',no+1)] >= 1 || fs[generator('s',no-1)] >= 1 )
                    a1 = 1;
            }
        }

    }

    for(auto i:fm)
    {
        lli no = i.first[0] - 48;
        if(i.second == 1)
        {
            if( fm[generator('m',no+1)] >= 1 && fm[generator('m',no-1)] >= 1 )
                return 0;
            else
            {
                if( fm[generator('m',no+1)] >= 1 || fm[generator('m',no-1)] >= 1 )
                    a2 = 1;
            }
        }

    }

    for(auto i:fp)
    {
        lli no = i.first[0] - 48;
        if(i.second == 1)
        {
            if( fp[generator('p',no+1)] >= 1 && fm[generator('p',no-1)] >= 1 )
                return 0;
            else
            {
                if( fp[generator('p',no+1)] >= 1 || fm[generator('p',no-1)] >= 1 )
                    a3 = 1;
            }
        }
    }

    if(a1 == -1 && a2 == -1 && a3 == -1)
        return 2;
    else
        return 1;
}

int two_check()
{
    lli a1 = -1;
    lli a2 = -1;
    lli a3 = -1;
    for(auto i:fm)
    {
        if(i.second == 2)
        {
            lli no = i.first[0] - 48;
            if( fm[generator('m',no-1)] >= 1 || fm[generator('m',no+1)] >= 1)
                return 0;
            else
                a1 = 1;
        }
    }

    for(auto i:fs)
    {
        if(i.second == 2)
        {
            lli no = i.first[0] - 48;
            if( fm[generator('s',no-1)] >= 1 || fm[generator('s',no+1)] >= 1)
                return 0;
            else
                a2 = 1;
        }
    }

    for(auto i:fp)
    {
        if(i.second == 2)
        {
            lli no = i.first[0] - 48;
            if( fp[generator('p',no-1)] >= 1 || fp[generator('p',no+1)] >= 1)
                return 0;
            else
                a3 = 1;
        }
    }

    if(a1 == -1 && a2 == -1 && a3 == -1)
        return -1;
    else
        return 1;
}
int main()
{
    //GO_FAST

    string s1,s2,s3;
    cin>>s1>>s2>>s3;

    add_to(s1);
    add_to(s2);
    add_to(s3);

    Map_printer(fm);
    Map_printer(fp);
    Map_printer(fs);

    if(three_check() == 1)
        cout<<"0\n";
    else
    {
        lli tc = two_check();
        if(tc != -1)
            cout<<tc<<"\n";
        else
        {
            cout<<one_check();
        }
    }




    return 0;
}
